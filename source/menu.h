#ifndef MENU_H
#define MENU_H

#include<QObject>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include"menustate.h"
#include"indicant.h"
#include"actor_player.h"

class Menu: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    MenuState *currentState;
    Indicant *indicant;
    ActorPlayer *player;
    QString message;
public:
    Menu(ActorPlayer *player);
    void keyPressEvent(QKeyEvent *event);
    void openTab();
    ActorPlayer* getPlayer();
    Indicant* getIndicant();
    void setMessage(QString message);
signals:
    void closeMenu();
};

#endif // MENU_H
