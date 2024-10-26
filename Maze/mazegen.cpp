#include "MazeGen.h"
#include "Grid.h"
#include "Cell.h"
#include <QDebug>

MazeGen::MazeGen()
    : paused(false),
    choise(Choice_generator::depth_first),
    deph_init(false),
    prim_init(false)
{
}

void MazeGen::update_generate_with_choosen(Grid &grid)
{
    qDebug() << "Update MazeGen!\n";
    if (!paused)  // Ensure this is properly scoped
    {
        if (choise == Choice_generator::depth_first)
        {
            qDebug() << "Choice: depth_first!\n";
            depth_first_search_stack(grid);
        }
        else if (choise == Choice_generator::prim)
        {
            qDebug() << "Choice: prim!\n";
            prim(grid);
        }
    }
}

void MazeGen::depth_first_search_stack(Grid &maze_grid)
{

    /*
    1. Choose the initial cell, mark it as visited and push it to the stack
    2. While the stack is not empty
    1. Pop a cell from the stack and make it a current cell
    2. If the current cell has any neighbours which have not been visited
        1. Push the current cell to the stack
        2. Choose one of the unvisited neighbours
        3. Remove the wall between the current cell and the chosen cell
        4. Mark the chosen cell as visited and push it to the stack
    */
    qDebug() << "depthFirst step!\n";
    if (paused) return;
    if (!deph_init)
    {
    Cell *start_cell = maze_grid.get_cell(0, 0);
    start_cell->set_visited();
    start_cell->set_type(Cell::Type::Start);
    cell_stack.push(start_cell);
    maze_grid.mark_cell_for_redraw(*start_cell);
    deph_init = true;
    }
    if (cell_stack.empty())
    {
        setPaused(true);
        return;
    }

    if(!cell_stack.empty())
    {
        Cell *currentCell = cell_stack.top();
        std::vector<Cell*> unvisited_neighbors = maze_grid.get_unvisited_neighbours(currentCell->get_x(), currentCell->get_y());

        if (!unvisited_neighbors.empty())
        {
            Cell *neighbour = maze_grid.select_random_cell(unvisited_neighbors);
            maze_grid.connect_cells(*currentCell, *neighbour);
            neighbour->set_visited();
            neighbour->set_type(Cell::Type::Visited);
            maze_grid.mark_cell_for_redraw(*neighbour);
            maze_grid.mark_cell_for_redraw(*currentCell);


            cell_stack.push(neighbour);
        }
        else
        {
            cell_stack.pop();
            currentCell->set_type(Cell::Type::Finished);
            maze_grid.mark_cell_for_redraw(*currentCell);

        }
        // You can update the grid after each step, or periodically, to avoid too frequent redraws.
        // Here we update it after marking cells.
        maze_grid.updateGrid();
    }
}

void MazeGen::prim(Grid &maze_grid)
{
    // Implement the Prim's algorithm here
}

void MazeGen::reset(Grid &grid)
{
    setPaused(false);
    while (!cell_stack.empty())
    {
        cell_stack.pop();
    }
    frontier_vec.clear();
    deph_init = false;
    prim_init = false;
}
