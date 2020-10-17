#include"game.h"
#include<QBrush>
#include<QApplication>
#include<QGraphicsPixmapItem>
#include"map_cafe.h"
#include"map_village.h"
#include"map_route.h"
#include<QDebug>

Game::Game()
{
    titleScreen=new TitleScreen();
    timer=new QTimer();
    connect(titleScreen, SIGNAL(start()), this, SLOT(startGame()));
    connect(titleScreen, SIGNAL(load()), this, SLOT(loadGame()));
    connect(titleScreen, SIGNAL(quit()), qApp, SLOT(quit()));
    connect(timer, SIGNAL(timeout()), this, SLOT(gameLoop()));
    setScene(titleScreen);
    maps[0]=new Village();
    maps[1]=new Cafe();
    maps[2]=new Route();
    maps[0]->setNeighbours(maps[1], nullptr, maps[2], nullptr);
    maps[1]->setNeighbours(nullptr, nullptr, maps[0], nullptr);
    maps[2]->setNeighbours(maps[0], nullptr, nullptr, nullptr);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
void Game::startGame()
{
    player=new ActorPlayer("Player");
    menu=new Menu(player);
    connect(player, SIGNAL(openMenu()), this, SLOT(openMenu()));
    connect(menu, SIGNAL(closeMenu()), this, SLOT(closeMenu()));
    battle=new Battle(player, QPixmap(":/images/battle_bg.png"));
    connect(this, SIGNAL(battleStart()), this, SLOT(startBattle()));
    connect(battle, SIGNAL(battleEnd()), this, SLOT(quitBattle()));
    currentMap=maps[0];
    setScene(currentMap);
    loadPlayer(384, 272);
    timer->start(0);
}
void Game::loadGame()
{
    QString fileName="save1.txt";
    QFile save(fileName);
    if(!save.open(QFile::ReadOnly | QFile::Text)) return;
    QTextStream in(&save);
    QString name;
    int map, x, y, lvl, exp, hp, maxHp, mp, maxMp, attack, defence;
    in>>name>>map>>x>>y>>lvl>>exp>>hp>>maxHp>>mp>>maxMp>>attack>>defence;
    player=new ActorPlayer(name, map, lvl, exp, hp, maxHp, mp, maxMp, attack, defence);
    menu=new Menu(player);
    connect(player, SIGNAL(openMenu()), this, SLOT(openMenu()));
    connect(menu, SIGNAL(closeMenu()), this, SLOT(closeMenu()));
    battle=new Battle(player, QPixmap(":/images/battle_bg.png"));
    connect(this, SIGNAL(battleStart()), this, SLOT(startBattle()));
    connect(battle, SIGNAL(battleEnd()), this, SLOT(quitBattle()));
    currentMap=maps[map];
    setScene(currentMap);
    loadPlayer(x, y);
    timer->start(100);
}
void Game::loadPlayer(int x, int y)
{
    currentMap->addItem(player);
    player->setPos(x, y);
    player->setPrevPos(x, y);
    player->setFocus();
}
void Game::go()
{
    currentMap->removeItem(player);
    currentMap=currentMap->getNeighbour(player->getDirection());
    setScene(currentMap);
    if(player->getDirection()==0) loadPlayer(384, 560);
    if(player->getDirection()==1) loadPlayer(0, 272);
    if(player->getDirection()==2) loadPlayer(384, -16);
    if(player->getDirection()==3) loadPlayer(768, 272);
    player->setCurrentMap(currentMap->getNumber());
}
void Game::openMenu()
{
    currentMap->addItem(menu);
    currentMap->addItem(menu->getIndicant());
    menu->setFocus();
}
void Game::closeMenu()
{
    currentMap->removeItem(menu->getIndicant());
    currentMap->removeItem(menu);
    player->setFocus();
}
void Game::startBattle()
{
    player->clearFocus();
    setScene(battle);
    battle->startBattle(new ActorEnemy);
}
void Game::quitBattle()
{
    player->setFocus();
    setScene(currentMap);
}
void Game::gameLoop()
{
    int x=static_cast<int>(player->x()), y=static_cast<int>(player->y());
    if(x>=800||x<=-32||y<=-48||y>=592) go();
    else if(player->getHasMoved()&&qrand()%currentMap->getEncounterRate()==1)
    {
        player->setHasMoved(false);
        player->stop();
        emit battleStart();
    }
    player->setHasMoved(false);
}
