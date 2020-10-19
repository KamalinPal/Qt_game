#include"shop.h"
#include"equipable_armor.h"
#include"equipable_shield.h"
#include"equipable_sword.h"
#include<QFont>
#include<QPainter>
#include<QKeyEvent>
#include<QGraphicsScene>
#include"actor_player.h"
#include<QtDebug>
#include"map.h"

Shop::Shop()
{
    setPos(250, 100);
    setZValue(19);
    setFlag(ItemIsFocusable);
    stock.push_back(new EquipableArmor(0, 2));
    stock.push_back(new EquipableShield(0, 1));
    stock.push_back(new EquipableSword(1, 0));
    QFont font;
    font.setPointSize(14);
    QPixmap pixmap(300, 400);
    QPainter painter(&pixmap);
    painter.setFont(font);
    painter.drawRect(0, 0, 300, 400);
    painter.fillRect(1, 1, 298, 398, Qt::lightGray);
    for(int i=0;i<stock.length();++i)
    {
        painter.drawPixmap(25, 32*i, stock[i]->getPixmap());
        painter.drawText(65, 32*i+4, 230, 32, Qt::AlignLeft, stock[i]->getName()
                         +" - "+QString::number(stock[i]->getPrice())+"gp");
    }
    painter.end();
    setPixmap(pixmap);
    indicant=new Indicant(250, stock.length(), 32, 107, 0.4);
}
void Shop::keyPressEvent(QKeyEvent *event)
{
    Map *map=dynamic_cast<Map*>(scene());
    if(map->getTextBox()->isVisible()&&(event->key()==Qt::Key_X||event->key()==Qt::Key_Z))
    {
        map->getText()->hide();
        map->getTextBox()->hide();
    }
    else if(event->key()==Qt::Key_Up) indicant->move(-1);
    else if(event->key()==Qt::Key_Down) indicant->move(1);
    else if(event->key()==Qt::Key_X)
    {
        if(player->getItems()->indexOf(stock[indicant->getPosition()])==-1)
        {
            player->getItems()->push_back(stock[indicant->getPosition()]);
            map->getText()->setPlainText(player->getName()+" bought "+
                                         stock[indicant->getPosition()]->getName()+".");
            map->getTextBox()->show();
            map->getText()->show();
        }
        else
        {
            map->getText()->setPlainText("Item aleady bought.");
            map->getTextBox()->show();
            map->getText()->show();
        }
    }
    else if(event->key()==Qt::Key_Z)
    {
        emit endShopping();
    }
}
Indicant *Shop::getIndicant()
{
    return indicant;
}
void Shop::setPlayer(ActorPlayer *player)
{
    this->player=player;
}
