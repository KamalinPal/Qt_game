#ifndef MENU_STATE_ITEMS_H
#define MENU_STATE_ITEMS_H

#include"menustate.h"

class MenuStateItems: public MenuState
{
    Q_OBJECT
public:
    MenuStateItems(Menu *menu);
    void go() final;
    bool ret() final;
};

#endif // MENU_STATE_ITEMS_H
