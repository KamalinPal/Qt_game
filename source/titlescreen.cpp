#include"titlescreen.h"
#include<QPainter>
#include<QDebug>

TitleScreen::TitleScreen()
{
    setSceneRect(0, 0, 800, 600);
    QPixmap background(":/images/menu.jpg");
    QFont font;
    font.setPointSize(30);
    font.setBold(1);
    QPainter painter(&background);
    painter.setFont(font);
    painter.setPen(Qt::red);
    painter.drawText(200, 150, 400, 100, Qt::AlignCenter, "Start");
    painter.drawText(200, 250, 400, 100, Qt::AlignCenter, "Load");
    painter.drawText(200, 350, 400, 100, Qt::AlignCenter, "Exit");
    painter.end();
    setBackgroundBrush(background);
    indicant=new Indicant(300, 3, 100, 177, 1);
    addItem(indicant);
}
void TitleScreen::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Up)
    {
        indicant->move(-1);
    }
    if(event->key()==Qt::Key_Down)
    {
        indicant->move(1);
    }
    if(event->key()==Qt::Key_X)
    {
        if(indicant->getPosition()==0) emit start();
        if(indicant->getPosition()==1) emit load();
        if(indicant->getPosition()==2) emit quit();
    }
}
