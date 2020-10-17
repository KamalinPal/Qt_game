#include"actor_player.h"
#include<QGraphicsScene>
#include<QDebug>
#include"map.h"
#include"consumable_hpfluid.h"
#include"consumable_mpfluid.h"
#include"consumable_tea.h"
#include"consumable_milk.h"
#include"skill_frost.h"
#include"skill_fireball.h"
#include"skill_cure.h"
#include"skill_quake.h"
#include"actor_npc_healer.h"
#include"actor_npc_shopkeeper.h"
#include"shop.h"

ActorPlayer::ActorPlayer(QString name)
{
    currentMap=0;
    this->name=name;
    lvl=1;
    exp=0;
    maxHp=6;
    hp=6;
    maxMp=3;
    mp=3;
    attack=1;
    defence=0;
    setUp();
}
ActorPlayer::ActorPlayer(QString name, int currentMap, int lvl, int exp, int hp, int maxHp, int mp, int maxMp, int attack, int defence)
{
    this->currentMap=currentMap;
    this->name=name;
    this->lvl=lvl;
    this->exp=exp;
    this->hp=hp;
    this->maxHp=maxHp;
    this->mp=mp;
    this->maxMp=maxMp;
    this->attack=attack;
    this->defence=defence;
    setUp();
}
void ActorPlayer::setUp()
{
    timer=new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    setFlag(QGraphicsItem::ItemIsFocusable);
    talking=0;
    walking=false;
    hasMoved=false;
    direction=2;
    frame=0;
    sheet=QPixmap(":/images/player.png");
    setPixmap(sheet.copy(0, 0, 32, 48));
    items=new QVector<Item*>({new ConsumableHpFluid(), new ConsumableMpFluid(),
                              new ConsumableTea(), new ConsumableMilk()});
    skills=new QVector<Skill*>({new SkillFrost(), new SkillFireball(), new SkillCure(), new SkillQuake()});
    setZValue((y()+16)/32);
    timer->start(125);
}
void ActorPlayer::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat()&&!walking&&!talking&&frame%64==0)
    {
        if(event->key()==Qt::Key_Up)
        {
            setDirection(0);
            walking=true;
        }
        if(event->key()==Qt::Key_Right)
        {
            setDirection(1);
            walking=true;
        }
        if(event->key()==Qt::Key_Down)
        {
            setDirection(2);
            walking=true;
        }
        if(event->key()==Qt::Key_Left)
        {
            setDirection(3);
            walking=true;
        }
        if(event->key()==Qt::Key_C) emit openMenu();
        if(event->key()==Qt::Key_X)
        {
            ActorNpc *npc;
            if(direction==0) npc=dynamic_cast<ActorNpc*>(scene()->itemAt(x()+16, y(), QTransform()));
            if(direction==1) npc=dynamic_cast<ActorNpc*>(scene()->itemAt(x()+48, y()+32, QTransform()));
            if(direction==2) npc=dynamic_cast<ActorNpc*>(scene()->itemAt(x()+16, y()+64, QTransform()));
            if(direction==3) npc=dynamic_cast<ActorNpc*>(scene()->itemAt(x()-16, y()+32, QTransform()));
            if(npc)
            {
                npc->setDirection((direction+2)%4);
                auto shopkeeper=dynamic_cast<NpcShopkeeper*>(npc);
                if(shopkeeper)
                {
                    shop=shopkeeper->getShop();
                    shop->setPlayer(this);
                    connect(shop, SIGNAL(endShopping()), this, SLOT(endShopping()));
                    scene()->addItem(shop);
                    scene()->addItem(shop->getIndicant());
                    shop->setFocus();
                }
                else dialog=npc->talk(this);
                if(dialog.length()>0)
                {
                    Map *map=dynamic_cast<Map*>(scene());
                    map->getTextBox()->show();
                    map->getText()->setPlainText(dialog[talking++]);
                    map->getText()->show();
                }
            }
        }
    }
    else if(event->key()==Qt::Key_X&&talking)
    {
        auto map=dynamic_cast<Map*>(scene());
        if(talking>=dialog.length())
        {
            dialog.clear();
            talking=0;
            map->getTextBox()->hide();
            map->getText()->hide();
        }
        else map->getText()->setPlainText(dialog[talking++]);
    }
}
void ActorPlayer::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        int x=event->key();
        if(x==Qt::Key_Up||x==Qt::Key_Right||x==Qt::Key_Down||x==Qt::Key_Left) walking=false;
    }
}
void ActorPlayer::move()
{
    if(walking||frame%64)
    {
        frame=(frame+32)%128;
        if(direction==0)
        {
            setPixmap(sheet.copy(frame, 144, 32, 48));
            moveBy(0, -16);
        }
        if(direction==1)
        {
            setPixmap(sheet.copy(frame, 96, 32, 48));
            moveBy(16, 0);
        }
        if(direction==2)
        {
            setPixmap(sheet.copy(frame, 0, 32, 48));
            moveBy(0, 16);
        }
        if(direction==3)
        {
            setPixmap(sheet.copy(frame, 48, 32, 48));
            moveBy(-16, 0);
        }
        fixCollision();
    }
    setZValue((y()+16)/32);
}
void ActorPlayer::endShopping()
{
    scene()->removeItem(shop->getIndicant());
    scene()->removeItem(shop);
    this->setFocus();
    disconnect(shop, SIGNAL(endShopping()), this, SLOT(endShopping()));
}
QString ActorPlayer::basicAttack(ActorEnemy *enemy)
{
    int damage=qMax(0, (attack-enemy->getDefence()));
    return name+" dealt "+QString::number(enemy->changeHp(-damage))+" damage to the "+enemy->getName()+".\n\n";
}
void ActorPlayer::fixCollision()
{
    if(!collidingItems().isEmpty()) setPos(prevX, prevY);
    else
    {
        prevX=static_cast<int>(x());
        prevY=static_cast<int>(y());
        hasMoved=true;
    }
}
void ActorPlayer::setPrevPos(int x, int y)
{
    prevX=x;
    prevY=y;
}
void ActorPlayer::setHasMoved(bool hasMoved)
{
    this->hasMoved=hasMoved;
}
void ActorPlayer::setCurrentMap(int currentMap)
{
    this->currentMap=currentMap;
}
void ActorPlayer::stop()
{
    walking=false;
}
bool ActorPlayer::lvlUp()
{
    if(exp>=20)
    {
        exp-=20;
        maxHp+=2;
        hp=maxHp;
        maxMp+=1;
        mp=maxMp;
        attack+=1;
        defence+=1;
        ++lvl;
        return true;
    }
    return false;
}
QVector<Item*>* ActorPlayer::getItems()
{
    return items;
}
QVector<Skill*>* ActorPlayer::getSkills()
{
    return skills;
}
QPixmap ActorPlayer::getSprite()
{
    return sheet.copy(0, 144, 32, 48);
}
int ActorPlayer::getLvl()
{
    return lvl;
}
int ActorPlayer::getMaxHp()
{
    return maxHp;
}
int ActorPlayer::getMaxMp()
{
    return maxMp;
}
bool ActorPlayer::getHasMoved()
{
    return hasMoved;
}
int ActorPlayer::getCurrentMap()
{
    return currentMap;
}
