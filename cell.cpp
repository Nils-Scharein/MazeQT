#include "Cell.h"
#include <QPen>
#include <QDebug>
#include <QPainter>
#include <QGraphicsSceneHoverEvent>

Cell::Cell(int x, int y, int size, int wallSize, QGraphicsItem *parent)
    : QGraphicsRectItem(parent),
    x(x),
    y(y),
    size(size),
    visited(false),
    isaktiv(false),
    thickness_wall(wallSize),
    brush(Qt::white) // Start with a white brush
{
    // Set the rectangle for the cell
    setRect(x * size, y * size, size, size);
    setPen(Qt::NoPen); // No border pen for the cell itself
    setBrush(brush);
    setZValue(0); // Ensure it's drawn at the correct Z level

    // Enable hover events
    setAcceptHoverEvents(true);

    // Create wall lines (position and attach to the cell)
    northWall = new QGraphicsLineItem(x * size, y * size, (x + 1) * size, y * size, this);
    southWall = new QGraphicsLineItem(x * size, (y + 1) * size, (x + 1) * size, (y + 1) * size, this);
    eastWall = new QGraphicsLineItem((x + 1) * size, y * size, (x + 1) * size, (y + 1) * size, this);
    westWall = new QGraphicsLineItem(x * size, y * size, x * size, (y + 1) * size, this);

    // Set wall pens to ensure they're visible and correct
    QPen wallPen(Qt::black, thickness_wall);
    northWall->setPen(wallPen);
    southWall->setPen(wallPen);
    eastWall->setPen(wallPen);
    westWall->setPen(wallPen);

    // Initialize the cell color
    set_cellColor();
}

void Cell::set_cellColor()
{
    switch (cell_type)
    {
    case Type::Start:
        brush.setColor(Qt::green);
        break;
    case Type::End:
        brush.setColor(Qt::red);
        break;
    case Type::Neutral:
        brush.setColor(Qt::white);
        break;
    case Type::Visited:
        brush.setColor(QColor(255, 166, 0));  // Orange for visited cells
        break;
    case Type::Finished:
        brush.setColor(Qt::yellow);  // Yellow for finished cells
        break;
    case Type::Frontier:
        brush.setColor(QColor(255, 192, 203));  // Pink for frontier cells
        break;
    default:
        brush.setColor(Qt::cyan); // Fallback color if no type is matched
        break;
    }

    this->setBrush(brush);  // Ensure the brush is applied
}

void Cell::remove_wall(Wall wall)
{
    switch (wall)
    {
    case Wall::North:
        walls[0] = false;
        northWall->hide();
        break;
    case Wall::South:
        walls[2] = false;
        southWall->hide();
        break;
    case Wall::East:
        walls[1] = false;
        eastWall->hide();
        break;
    case Wall::West:
        walls[3] = false;
        westWall->hide();
        break;
    }

    this->update();
}

void Cell::reset()
{
    isaktiv = false;
    set_unvisited();
    for (int i = 0; i < 4; ++i)
    {
        walls[i] = true;
    }
    set_type(Type::Neutral);
    set_cellColor();

    // Trigger a repaint to ensure walls are reset
    this->update();
}

void Cell::updateCell()
{
    qDebug() << "Updating cell at position: (" << x << ", " << y << ")";

    // Full size for the cell
    setRect(x * size, y * size, size, size);

    // Update the color based on the cell type
    set_cellColor();

    // Trigger a repaint to ensure walls are updated
    this->update();
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Call the base class implementation to draw the rectangle
    QGraphicsRectItem::paint(painter, option, widget);

    // Create a pen with the specified wall thickness
    QPen wallPen(Qt::black, thickness_wall);

    // Set the pen for the painter
    painter->setPen(wallPen);

    // Draw the walls manually
    if (walls[0])
    {
        // North
        painter->drawLine(x * size, y * size, (x + 1) * size, y * size);
    }
    if (walls[1])
    {
        // East
        painter->drawLine((x + 1) * size, y * size, (x + 1) * size, (y + 1) * size);
    }
    if (walls[2])
    {
        // South
        painter->drawLine(x * size, (y + 1) * size, (x + 1) * size, (y + 1) * size);
    }
    if (walls[3])
    {
        // West
        painter->drawLine(x * size, y * size, x * size, (y + 1) * size);
    }
}

void Cell::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    // Change the brush color to purple on hover
    brush.setColor(QColorConstants::Svg::purple);
    this->setBrush(brush);

    // Change the pen color of the walls to purple on hover
    QPen hoverPen(QColorConstants::Svg::purple, thickness_wall);
    northWall->setPen(hoverPen);
    southWall->setPen(hoverPen);
    eastWall->setPen(hoverPen);
    westWall->setPen(hoverPen);

    // Trigger a repaint to ensure the hover effect is shown
    this->update();

    QGraphicsRectItem::hoverEnterEvent(event);
}

void Cell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    // Revert the brush color to the original
    set_cellColor();

    // Revert the pen color of the walls to black
    QPen wallPen(Qt::black, thickness_wall);
    northWall->setPen(wallPen);
    southWall->setPen(wallPen);
    eastWall->setPen(wallPen);
    westWall->setPen(wallPen);

    // Trigger a repaint to ensure the hover effect is removed
    this->update();

    QGraphicsRectItem::hoverLeaveEvent(event);  // Call base class implementation
}
