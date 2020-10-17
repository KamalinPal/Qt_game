#ifndef GAME_H
#define GAME_H

#include<QGraphicsView>
#include<QTimer>
#include"titlescreen.h"
#include"actor_player.h"
#include"map.h"
#include"battle.h"
#include"menu.h"

class Game: public QGraphicsView
{
    Q_OBJECT
private:
    TitleScreen *titleScreen;
    Map *maps[3];
    Map *currentMap;
    ActorPlayer *player;
    Menu *menu;
    Battle *battle;
    QTimer *timer;
public:
    Game();
    void loadPlayer(int x, int y);
    void go();
private slots:
    void startGame();
    void loadGame();
    void openMenu();
    void closeMenu();
    void startBattle();
    void quitBattle();
    void gameLoop();
signals:
    void battleStart();
};

#endif // GAME_H
