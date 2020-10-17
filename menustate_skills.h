#ifndef MENU_STATE_SKILLS_H
#define MENU_STATE_SKILLS_H

#include"menustate.h"

class MenuStateSkills: public MenuState
{
    Q_OBJECT
public:
    MenuStateSkills(Menu *menu);
    void go() final;
    bool ret() final;
};

#endif // MENU_STATE_SKILLS_H
