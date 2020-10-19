#ifndef INDICANT_H
#define INDICANT_H

#include<QGraphicsPixmapItem>

class Indicant: public QGraphicsPixmapItem
{
protected:
    int position;
    int length;
    int multiplier;
    int offset;
    int windowSize;
public:
    Indicant(int x);
    Indicant(int x, int length, int multiplier, int offset, qreal scale);
    virtual void move(int direction);
    virtual void reset();
    int getPosition();
};

#endif // INDICANT_H
