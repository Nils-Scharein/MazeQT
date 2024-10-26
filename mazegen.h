#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H

#include <QObject>
#include <stack>
#include <vector>

class Grid;
class Cell;

enum class Choice_generator {
    None_gen,
    depth_first,
    prim
};

class MazeGen : public QObject
{
    Q_OBJECT

public:
    MazeGen();

    void update_generate_with_choosen(Grid &grid);
    void reset(Grid &grid);

    void set_choice(Choice_generator choice) { this->choise = choice; }

    void setPaused(bool paused) { this->paused = paused; }
    bool isPaused() const { return paused; }
    bool togglePaused() { this->paused = !paused; }

    // Helper Variables
    std::stack<Cell *> cell_stack;
    std::vector<Cell *> frontier_vec;

private:
    void depth_first_search_stack(Grid &maze_grid);
    void prim(Grid &maze_grid);

    bool paused;
    Choice_generator choise;
    bool deph_init;
    bool prim_init;
};

#endif // MAZEGENERATOR_H
