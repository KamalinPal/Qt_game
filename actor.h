#ifndef ACTOR_H
#define ACTOR_H

#include<QObject>
#include<QGraphicsPixmapItem>
#include<QString>

class Actor: public QObject, public QGraphicsPixmapItem
{
protected:
    QPixmap sheet;
    QString name;
    int exp;
    int hp;
    int maxHp;
    int mp;
    int maxMp;
    int attack;
    int defence;
    int direction;
public:
    Actor();
    QPainterPath shape() const;
    void changeExp(int delta);
    int changeHp(int delta);
    int changeMp(int delta);
    void changeAttack(int delta);
    void changeDefence(int delta);
    void setDirection(int direction);
    QString getName();
    int getExp();
    int getHp();
    int getMp();
    int getAttack();
    int getDefence();
    int getDirection();
};

#endif // ACTOR_H
