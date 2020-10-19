#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

#include<QGraphicsScene>
#include<QGraphicsTextItem>
#include<QObject>
#include<QKeyEvent>
#include"indicant.h"

class TitleScreen: public QGraphicsScene
{
    Q_OBJECT
private:
    Indicant *indicant;
public:
    TitleScreen();
    void keyPressEvent(QKeyEvent *event);
signals:
    void start();
    void load();
    void quit();
};

#endif // TITLE_SCREEN_H
