#include"menustate_items.h"
#include"menu.h"

MenuStateItems::MenuStateItems(Menu *menu): MenuState(menu)
{
    QFont font;
    font.setPointSize(14);
    QPainter painter(&pixmap);
    painter.setFont(font);
    painter.drawRect(0, 0, 200, 400);
    painter.fillRect(1, 1, 198, 398, Qt::lightGray);
    auto items=menu->getPlayer()->getItems();
    for(int i=0;i<items->length();++i)
    {
        painter.drawPixmap(25, 32*i, items->at(i)->getPixmap());
        painter.drawText(65, 32*i+4, 125, 32, Qt::AlignLeft, items->at(i)->getName());
    }
    painter.end();
    indicant=new Indicant(300, items->length(), 32, 107, 0.4);
}
void MenuStateItems::go()
{
    menu->setMessage(menu->getPlayer()->getItems()->at(menu->getIndicant()->getPosition())->
                     use(menu->getPlayer()));
}
bool MenuStateItems::ret()
{
    return true;
}
