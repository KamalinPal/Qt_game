#include"menu.h"
#include"menustate_default.h"
#include"menustate_items.h"
#include"menustate_skills.h"
#include"menustate_status.h"
#include"menustate_save.h"
#include"map.h"
#include"map_village.h"
#include<QDebug>

Menu::Menu(ActorPlayer *player)
{
    currentState=new MenuStateDefault(this);
    indicant=currentState->getIndicant();
    setFlag(ItemIsFocusable);
    setPixmap(currentState->getPixmap());
    setPos(300, 100);
    this->player=player;
    setZValue(19);
    message="";
}
void Menu::openTab()
{
    int x=indicant->getPosition();
    delete currentState;
    if(x==0) currentState=new MenuStateItems(this);
    if(x==1) currentState=new MenuStateSkills(this);
    if(x==2) currentState=new MenuStateStatus(this);
    if(x==3) currentState=new MenuStateSave(this);
    setPixmap(currentState->getPixmap());
    indicant=currentState->getIndicant();
    scene()->addItem(indicant);
}
void Menu::keyPressEvent(QKeyEvent *event)
{
    Map *map=dynamic_cast<Map*>(scene());
    if(map->getTextBox()->isVisible()&&(event->key()==Qt::Key_X||event->key()==Qt::Key_Z))
    {
        map->getTextBox()->hide();
        map->getText()->hide();
    }
    else if(event->key()==Qt::Key_Up) indicant->move(-1);
    else if(event->key()==Qt::Key_Down) indicant->move(1);
    else if(event->key()==Qt::Key_X)
    {
        currentState->go();
        if(message!="")
        {
            map->getText()->setPlainText(message);
            map->getTextBox()->show();
            map->getText()->show();
            message="";
        }
    }
    else if(event->key()==Qt::Key_Z)
    {
        if(currentState->ret())
        {
            delete currentState;
            currentState=new MenuStateDefault(this);
            setPixmap(currentState->getPixmap());
            indicant=currentState->getIndicant();
            scene()->addItem(indicant);
        }
        else emit closeMenu();
    }
}
ActorPlayer *Menu::getPlayer()
{
    return player;
}
Indicant *Menu::getIndicant()
{
    return indicant;
}
void Menu::setMessage(QString message)
{
    this->message=message;
}
