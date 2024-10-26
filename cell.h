#ifndef CELL_H
#define CELL_H

#include <QGraphicsRectItem>
#include <array>
#include <QBrush>

class Cell : public QGraphicsRectItem
{
public:
    enum class Wall {
        North,
        South,
        East,
        West
    };

    enum class Type {
        Start,
        End,
        Visited,
        Neutral,
        Finished,
        Frontier
    };

    Cell(int x, int y, int size, int wallSize, QGraphicsItem *parent = nullptr);

    // Getter
    int get_x() const { return x; }
    int get_y() const { return y; }
    bool get_visited() const { return visited; }
    bool get_isaktive() const { return isaktiv; }
    float get_gcost() const { return gcost; }
    float get_fcost() const { return fcost; }
    const std::array<bool, 4>& get_walls() const { return walls; }

    // Setter
    void set_gcost(float new_gcost) { gcost = new_gcost; }
    void set_fcost(float new_fcost) { fcost = new_fcost; }
    void set_type(Type type) { cell_type = type; }
    void set_visited() { visited = true; }
    void set_unvisited() { visited = false; }
    void set_isaktive() { isaktiv = true; }
    void set_cellColor();
    void set_size(int new_size) { size = new_size; }
    void remove_wall(Wall wall);

    // funcs
    void reset();
    void updateCell();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

private:
    int x;
    int y;

    bool visited;
    bool isaktiv;
    float gcost;
    float fcost;
    int size;
    int thickness_wall;
    Type cell_type = Type::Neutral;

    std::array<bool, 4> walls = { true, true, true, true }; // North, East, South, West

    QBrush brush;
    QGraphicsLineItem *northWall, *southWall, *eastWall, *westWall;
};

#endif // CELL_H
