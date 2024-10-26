#include "Grid.h"
#include <QGraphicsScene>
#include <cstdlib>
#include <ctime>
#include <QDebug>

std::vector<Cell*> Grid::cells_to_redraw;

Grid::Grid(QWidget *parent)
    : QGraphicsView(parent), rows(20), columns(20), wallSize(1)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    initializeGrid();
    std::srand(std::time(0));
    cells_to_redraw.clear();
}

void Grid::initializeGrid()
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    this->setScene(scene);
    createGrid();
}

void Grid::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
    createGrid();  // Adjust the grid size, but don't force a square shape
}

void Grid::createGrid()
{
    qDebug() << "Creating new Grid!\n";
    this->scene()->clear();
    cells.clear();
    int viewSize = std::min(this->width(), this->height());
    cellSize = viewSize / std::max(rows, columns);

    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < columns; ++x) {
            Cell *cell = new Cell(x, y, cellSize, wallSize);
            cells.push_back(cell);
            this->scene()->addItem(cell);
            cell->updateCell();
        }
    }

    this->scene()->setSceneRect(0, 0, columns * cellSize, rows * cellSize);
}

Cell* Grid::get_cell(int x, int y)
{
    int index = y * columns + x;
    if (index >= 0 && index < cells.size()) {
        return cells[index];
    }
    return nullptr;
}

std::vector<Cell*> Grid::get_unvisited_neighbours(int x, int y)
{
    std::vector<Cell*> neighbours;
    if (y > 0) {
        Cell *north = get_cell(x, y - 1);
        if (north && !north->get_visited()) {
            neighbours.push_back(north);
        }
    }
    if (y < rows - 1) {
        Cell *south = get_cell(x, y + 1);
        if (south && !south->get_visited()) {
            neighbours.push_back(south);
        }
    }
    if (x > 0) {
        Cell *west = get_cell(x - 1, y);
        if (west && !west->get_visited()) {
            neighbours.push_back(west);
        }
    }
    if (x < columns - 1) {
        Cell *east = get_cell(x + 1, y);
        if (east && !east->get_visited()) {
            neighbours.push_back(east);
        }
    }
    return neighbours;
}

void Grid::connect_cells(Cell &current, Cell &neighbor)
{
    int dx = neighbor.get_x() - current.get_x();
    int dy = neighbor.get_y() - current.get_y();

    if (dx == 1) {
        current.remove_wall(Cell::Wall::East);
        neighbor.remove_wall(Cell::Wall::West);
    } else if (dx == -1) {
        current.remove_wall(Cell::Wall::West);
        neighbor.remove_wall(Cell::Wall::East);
    } else if (dy == 1) {
        current.remove_wall(Cell::Wall::South);
        neighbor.remove_wall(Cell::Wall::North);
    } else if (dy == -1) {
        current.remove_wall(Cell::Wall::North);
        neighbor.remove_wall(Cell::Wall::South);
    }

    // Ensure that both cells are marked for redraw
    mark_cell_for_redraw(current);
    mark_cell_for_redraw(neighbor);
}

Cell* Grid::select_random_cell(const std::vector<Cell*>& cells)
{
    if (cells.empty()) {
        return nullptr;
    }
    int index = std::rand() % cells.size();
    return cells[index];
}

void Grid::mark_cell_for_redraw(Cell& cell)
{
    cells_to_redraw.push_back(&cell);
}

void Grid::updateGrid()
{
    qDebug() << "Updating grid...";

    // Do not clear the scene, as this removes all items from the scene
    qDebug() << "Number of Cells to Redraw: " << cells_to_redraw.size();
    for (const auto& cell : cells_to_redraw)
    {
        qDebug() << "Redrawing cell at position: (" << cell->get_x() << ", " << cell->get_y() << ")";
        cell->updateCell();
    }
    cells_to_redraw.clear();
}

void Grid::resetGrid()
{
    for (auto single_cell : cells)
    {
        {
            qDebug() << "Redrawing cell at position: (" <<  single_cell->get_x() << ", " <<  single_cell->get_y() << ")";
            single_cell->reset();
            mark_cell_for_redraw(*single_cell);
        }
    }
}
