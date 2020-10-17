#ifndef BATTLE_H
#define BATTLE_H

#include<QGraphicsScene>
#include<QKeyEvent>
#include<QGraphicsTextItem>
#include"actor_enemy.h"
#include<QPainter>
#include<QFont>
#include"actor_player.h"
#include"indicant_battle.h"
#include"battlestate.h"

class Battle: public QGraphicsScene
{
    Q_OBJECT
private:
    bool isNewText;
    bool endOfBattle;
    ActorEnemy *enemy;
    ActorPlayer *player;
    BattleState *state;
    IndicantBattle *indicant;
    QGraphicsPixmapItem *itemTab;
    QGraphicsPixmapItem *skillTab;
    QGraphicsTextItem *textItems[4];
public:
    Battle(ActorPlayer *player, QPixmap backGround);
    void startBattle(ActorEnemy *enemy);
    void endBattle(bool hasWon);
    void enemyTurn();
    void check();
    void keyPressEvent(QKeyEvent *event);
    void attack();
    void goItems();
    void goSkills();
    void flee();
    void useItem();
    void useSkill();
    QPixmap paint(QPixmap pixmap, int x, int y, QString text1, QString text2, QString text3, QString text4);
    ActorPlayer* getPlayer();
    IndicantBattle* getIndicant();
signals:
    void battleEnd();
};

#endif // BATTLE_H
