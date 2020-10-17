#include"menustate_skills.h"
#include"menu.h"

MenuStateSkills::MenuStateSkills(Menu *menu): MenuState(menu)
{
    QFont font;
    font.setPointSize(15);
    QPainter painter(&pixmap);
    painter.setFont(font);
    painter.drawRect(0, 0, 200, 400);
    painter.fillRect(1, 1, 198, 398, Qt::lightGray);
    auto skills=menu->getPlayer()->getSkills();
    for(int i=0;i<skills->length();++i)
    {
        painter.drawPixmap(25, 32*i, skills->at(i)->getPixmap());
        painter.drawText(65, 32*i+4, 125, 32, Qt::AlignLeft, skills->at(i)->getName());
    }
    painter.end();
    indicant=new Indicant(300, skills->length(), 32, 107, 0.4);
}
void MenuStateSkills::go()
{
    menu->setMessage(menu->getPlayer()->getSkills()->at(menu->getIndicant()->getPosition())->
            use(menu->getPlayer(), nullptr));
}
bool MenuStateSkills::ret()
{
    return true;
}
