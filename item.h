#ifndef ITEM_H
#define ITEM_H

#include<QPixmap>
#include<QString>

class ActorPlayer;

class Item
{
protected:
    int price;
    int amount;
    QString name;
    QPixmap pixmap;
public:
    Item();
    virtual ~Item();
    int getPrice();
    int getAmount();
    QString getName();
    QPixmap getPixmap();
    virtual QString use(ActorPlayer *player)=0;
};

#endif // ITEM_H
