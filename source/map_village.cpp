#include"map_village.h"
#include<QPainter>
#include<QDebug>
#include"actor_npc_healer.h"
#include"actor_npc_shopkeeper.h"
#include"actor_npc_quest.h"
#include<QGraphicsPixmapItem>

Village::Village()
{
    number=0;
    pixmap=QPixmap(":/images/village.png");
    QPixmap background(800, 600);
    QPainter painter(&background);
    for(int x=0;x<800;x+=32)
    {
        for(int y=0;y<600;y+=32)
        {
            if(x==384||((y>=96&&y<=480)&&(x==128||x==640))||((x>=160&&x<=640)&&(y==96||y==480)))
                painter.drawPixmap(x, y, pixmap, 0, 0, 32, 32);
            else painter.drawPixmap(x, y, pixmap, 0, 64, 32, 32);
        }
    }
    painter.end();
    setBackgroundBrush(background);
    int iter=0;
    for(int x=0;x<800;x+=32)
    {
        for(int y=0;y<600;y+=32)
        {
            if((x==0||y==0||x==768||y==576))
            {
                if(x==384&&(y==0||y==576)) continue;
                if(iter==0) addPixmap(pixmap.copy(0, 272, 32, 32))->setPos(x, y);
                if(iter==1) addPixmap(pixmap.copy(0, 175, 32, 32))->setPos(x, y);
                if(iter==2) addPixmap(pixmap.copy(127, 256, 32, 32))->setPos(x,y);
                if(iter==3) addPixmap(pixmap.copy(159, 256, 32, 32))->setPos(x, y);
            }
            ++iter;
            iter%=4;
        }
    }
    addPixmap(pixmap.copy(128, 307, 128, 109))->setPos(192, 240);
    addPixmap(pixmap.copy(1, 483, 115, 157))->setPos(480, 210);
    addPixmap(pixmap.copy(32, 32, 32, 32))->setPos(352, 64);
    addPixmap(pixmap.copy(32, 32, 32, 32))->setPos(416, 512);
    NpcHealer *h=new NpcHealer();
    h->setPos(352, 272);
    h->setZValue((h->y()+16)/32);
    addItem(h);
    NpcShopkeeper *s=new NpcShopkeeper();
    s->setPos(416, 272);
    s->setZValue((s->y()+16)/32);
    addItem(s);
    NpcQuest *q =new NpcQuest();
    q->setPos(416, 432);
    q->setZValue((q->y()+16)/32);
    addItem(q);
    auto dog=addPixmap(QPixmap(":/images/animals.png").copy(32, 32, 32, 32));
    dog->setPos(448, 448);
    dog->setZValue((q->y()+16)/32);
}
