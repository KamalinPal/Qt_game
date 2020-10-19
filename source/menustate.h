#ifndef MENU_STATE_H
#define MENU_STATE_H

#include"indicant_menu.h"
#include<QObject>
#include<QFont>
#include<QPainter>
#include"indicant.h"

class Menu;

class MenuState: public QObject
{
protected:
    Menu *menu;
    QPixmap pixmap;
    Indicant *indicant;
public:
    MenuState(Menu *menu);
    ~MenuState();
    QPixmap getPixmap();
    Indicant* getIndicant();
    virtual void go()=0;
    virtual bool ret()=0;
};

#endif // MENU_STATE_H
