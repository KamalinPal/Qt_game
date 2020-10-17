#include"menustate_default.h"
#include"menu.h"

MenuStateDefault::MenuStateDefault(Menu *menu): MenuState(menu)
{
    QFont font;
    font.setPointSize(20);
    QPainter painter(&pixmap);
    painter.setFont(font);
    painter.drawRect(0, 0, 200, 400);
    painter.fillRect(1, 1, 198, 398, Qt::lightGray);
    painter.drawText(0, 0, 200, 100, Qt::AlignCenter, "Items");
    painter.drawText(0, 100, 200, 100, Qt::AlignCenter, "Skills");
    painter.drawText(0, 200, 200, 100, Qt::AlignCenter, "Status");
    painter.drawText(0, 300, 200, 100, Qt::AlignCenter, "Save");
    painter.end();
    indicant=new Indicant(300, 4, 100, 139, 0.5);
}
void MenuStateDefault::go()
{
    menu->openTab();
}
bool MenuStateDefault::ret()
{
    return false;
}
