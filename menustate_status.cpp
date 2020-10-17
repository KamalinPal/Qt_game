#include"menustate_status.h"
#include"menu.h"

MenuStateStatus::MenuStateStatus(Menu *menu): MenuState(menu)
{
    QFont font;
    font.setPointSize(15);
    QPainter painter(&pixmap);
    painter.setFont(font);
    painter.drawRect(0, 0, 200, 400);
    painter.fillRect(1, 1, 198, 398, Qt::lightGray);
    auto p=menu->getPlayer();
    painter.drawText(0, 0, 200, 57, Qt::AlignCenter, "Name: "+p->getName());
    painter.drawText(0, 57, 200, 57, Qt::AlignCenter, "Hp: "+QString::number(p->getHp())
                     +"/"+QString::number(p->getMaxHp()));
    painter.drawText(0, 114, 200, 57, Qt::AlignCenter, "Mp: "+QString::number(p->getMp())
                     +"/"+QString::number(p->getMaxMp()));
    painter.drawText(0, 171, 200, 57, Qt::AlignCenter, "Attack: "+QString::number(p->getAttack()));
    painter.drawText(0, 228, 200, 57, Qt::AlignCenter, "Defence: "+QString::number(p->getDefence()));
    painter.drawText(0, 285, 200, 57, Qt::AlignCenter, "Exp: "+QString::number(p->getExp()));
    painter.drawText(0, 342, 200, 57, Qt::AlignCenter, "Lvl: "+QString::number(p->getLvl()));
    painter.end();
    indicant=new Indicant(0);
    indicant->hide();
}
void MenuStateStatus::go()
{

}
bool MenuStateStatus::ret()
{
    return true;
}
