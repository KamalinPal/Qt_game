#ifndef MENU_STATE_DEFAULT_H
#define MENU_STATE_DEFAULT_H

#include"menustate.h"

class MenuStateDefault: public MenuState
{
    Q_OBJECT
public:
    MenuStateDefault(Menu *menu);
    void go() final;
    bool ret() final;
};

#endif // MENU_STATE_DEFAULT_H
