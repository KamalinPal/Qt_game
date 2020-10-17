#include"menustate.h"
#include"menu.h"
#include<QtDebug>

MenuState::MenuState(Menu *menu)
{
    this->menu=menu;
    pixmap=QPixmap(200, 400);
}
MenuState::~MenuState()
{
    delete indicant;
}
QPixmap MenuState::getPixmap()
{
    return pixmap;
}
Indicant *MenuState::getIndicant()
{
    return indicant;
}
