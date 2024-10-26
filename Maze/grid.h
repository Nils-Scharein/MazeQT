#ifndef GRID_H
#define GRID_H

#include <QGraphicsView>
#include <vector>
#include "Cell.h"

class Grid : public QGraphicsView
{
    Q_OBJECT

public:
    Grid(QWidget *parent = nullptr);

    Cell* get_cell(int x, int y);
    std::vector<Cell*> get_unvisited_neighbours(int x, int y);
    void connect_cells(Cell &current, Cell &neighbor);
    Cell* select_random_cell(const std::vector<Cell*>& cells);
    void updateGrid();
    void mark_cell_for_redraw(Cell& cell);
    void createGrid();
    void resetGrid();
    int getNumberOfCellsToUpdate() {return cells_to_redraw.size();};
    void setRows(int num) {rows = num; };
    void setColums(int num) {columns = num; };
    void setWallSize(int num) {wallSize = num; };
    void clearCellstoRedraw() {cells_to_redraw.clear();} ;

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    int rows;
    int columns;
    int cellSize;
    int wallSize;

    std::vector<Cell*> cells;
    static std::vector<Cell*> cells_to_redraw;

    void initializeGrid();
    void updateCellSizes();  // Added this declaration
};

#endif // GRID_H
