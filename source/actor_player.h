#ifndef PLAYER_H
#define PLAYER_H

#include<QTimer>
#include<QVector>
#include<QKeyEvent>
#include"item.h"
#include"skill.h"
#include"equipment.h"
#include"actor_npc.h"
#include"actor_enemy.h"
#include"shop.h"

class ActorPlayer: public Actor
{
    Q_OBJECT
private:
    int lvl;
    int prevX;
    int prevY;
    bool hasMoved;
    int currentMap;
    int frame;
    int talking;
    bool walking;
    QTimer *timer;
    Equipment *eq;
    Shop *shop;
    QVector<Item*> *items;
    QVector<Skill*> *skills;
    QVector<QString> dialog;
public:
    ActorPlayer(QString name);
    ActorPlayer(QString name, int currentMap, int lvl, int exp, int hp, int maxHp, int mp, int maxMp, int attack, int defence);
    void setUp();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    QString basicAttack(ActorEnemy *enemy);
    void fixCollision();
    void setPrevPos(int x, int y);
    void setHasMoved(bool hasMoved);
    void setCurrentMap(int currentMap);
    void stop();
    bool lvlUp();
    QVector<Item*>* getItems();
    QVector<Skill*>* getSkills();
    QPixmap getSprite();
    int getLvl();
    int getMaxHp();
    int getMaxMp();
    bool getHasMoved();
    int getCurrentMap();
private slots:
    void move();
    void endShopping();
signals:
    void openMenu();
};

#endif // PLAYER_H
