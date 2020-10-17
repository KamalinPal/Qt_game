#include"map.h"

Map::Map()
{
    setSceneRect(0, 0, 800, 600);
    setStickyFocus(true);
    encounterRate=1;
    textBox=addRect(5, 495, 790, 100, QPen(), QBrush(Qt::lightGray));
    textBox->setZValue(20);
    textBox->hide();
    QFont font;
    font.setPointSize(12);
    text=addText("", font);
    text->setPos(10, 500);
    text->setZValue(21);
    text->hide();
}
void Map::setNeighbours(Map *up, Map *right, Map *down, Map *left)
{
    this->up=up;
    this->right=right;
    this->down=down;
    this->left=left;
}
Map *Map::getNeighbour(int dir)
{
    if(dir==0) return up;
    if(dir==1) return right;
    if(dir==2) return down;
    if(dir==3) return left;
    return nullptr;
}
int Map::getNumber()
{
    return number;
}
int Map::getEncounterRate()
{
    return encounterRate;
}
QGraphicsTextItem *Map::getText()
{
    return text;
}
QGraphicsRectItem *Map::getTextBox()
{
    return textBox;
}
