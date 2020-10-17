#include"menustate_save.h"
#include"menu.h"
#include<QTextStream>

MenuStateSave::MenuStateSave(Menu *menu): MenuState(menu)
{
    QFont font;
    font.setPointSize(20);
    QPainter painter(&pixmap);
    painter.setFont(font);
    painter.drawRect(0, 0, 200, 400);
    painter.fillRect(1, 1, 198, 398, Qt::lightGray);
    for(int i=0;i<4;++i)
    {
        painter.drawText(0, 100*i, 200, 100, Qt::AlignCenter, "File"+QString::number(i+1));
    }
    painter.end();
    indicant=new Indicant(300, 4, 100, 139, 0.5);
}
void MenuStateSave::go()
{
    QString fileName="save"+QString::number(menu->getIndicant()->getPosition()+1)+".txt";
    QFile save(fileName);
    if(!save.open(QFile::WriteOnly | QFile::Text)) return;
    QTextStream out(&save);
    ActorPlayer *p=menu->getPlayer();
    out<<p->getName()<<" "<<p->getCurrentMap()<<" "<<p->x()<<" "<<p->y()<<" "<<p->getLvl()
      <<" "<<p->getExp()<<" "<<p->getHp()<<" "<<p->getMaxHp()<<" "<<p->getMp()<<" "
     <<p->getMaxMp()<<" "<<p->getAttack()<<" "<<p->getDefence();
    save.close();
    menu->setMessage("Game saved.");
}
bool MenuStateSave::ret()
{
    return true;
}
