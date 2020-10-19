#ifndef MENU_STATE_STATUS_H
#define MENU_STATE_STATUS_H

#include"menustate.h"

class MenuStateStatus: public MenuState
{
    Q_OBJECT
public:
    MenuStateStatus(Menu *menu);
    void go() final;
    bool ret() final;
};

#endif // MENU_STATE_STATUS_H
