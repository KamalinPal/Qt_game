#ifndef SHOP_H
#define SHOP_H

#include<QGraphicsPixmapItem>
#include"item.h"
#include"indicant.h"

class ActorPlayer;

class Shop: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Indicant *indicant;
    QVector<Item*> stock;
    ActorPlayer *player;
public:
    Shop();
    void keyPressEvent(QKeyEvent *event);
    Indicant* getIndicant();
    void setPlayer(ActorPlayer *player);
signals:
    void endShopping();
};

#endif // SHOP_H
