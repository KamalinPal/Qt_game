#ifndef MENU_STATE_SAVE_H
#define MENU_STATE_SAVE_H

#include"menustate.h"

class MenuStateSave: public MenuState
{
    Q_OBJECT
public:
    MenuStateSave(Menu *menu);
    void go() final;
    bool ret() final;
};

#endif // MENU_STATE_SAVE_H
