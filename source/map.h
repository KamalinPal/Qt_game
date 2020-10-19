#ifndef MAP_H
#define MAP_H

#include<QGraphicsScene>
#include<QPixmap>
#include<QGraphicsPixmapItem>

class Map: public QGraphicsScene
{
private:
    Map *up;
    Map *down;
    Map *right;
    Map *left;
protected:
    int number;
    int encounterRate;
    QPixmap pixmap;
    QGraphicsRectItem *textBox;
    QGraphicsTextItem *text;
public:
    Map();
    void setNeighbours(Map *up, Map *right, Map *down, Map *left);
    Map* getNeighbour(int dir);
    int getNumber();
    int getEncounterRate();
    QGraphicsRectItem* getTextBox();
    QGraphicsTextItem* getText();
};

#endif // MAP_H
