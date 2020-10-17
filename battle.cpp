#include"battle.h"
#include<QDebug>
#include<QtGlobal>
#include<QLabel>
#include"battlestate_default.h"
#include"battlestate_items.h"
#include"battlestate_skills.h"
#include"consumable.h"
#include"skill_defensive.h"
#include"skill_defensive.h"
#include"item_bone.h"

Battle::Battle(ActorPlayer *player, QPixmap backGround)
{
    this->player=player;
    state=new BattleStateDefault();
    setSceneRect(0, 0, 800, 600);
    setStickyFocus(true);
    QFont font;
    font.setPointSize(12);
    QPainter painter;
    painter.begin(&backGround);
    painter.setFont(font);
    painter.drawPixmap(384, 375, player->getSprite());
    painter.drawRect(700, 300, 80, 120);
    painter.fillRect(701, 301, 79, 119, Qt::lightGray);
    painter.drawText(700, 300, 80, 30, Qt::AlignCenter, player->getName());
    painter.drawText(705, 330, 80, 30, Qt::AlignVCenter | Qt::AlignLeft, "Hp: ");
    painter.drawText(705, 360, 80, 30, Qt::AlignVCenter | Qt::AlignLeft, "Mp: ");
    painter.drawText(705, 390, 80, 30, Qt::AlignVCenter | Qt::AlignLeft, "Lvl: ");
    painter.drawRect(5, 495, 790, 100);
    painter.fillRect(6, 496, 789, 99, Qt::lightGray);
    painter.end();
    backGround=paint(backGround, 620, 425, "Attack", "Items", "Skills", "Flee");
    setBackgroundBrush(backGround);
    textItems[0]=addText("", font);
    textItems[0]->setPos(730, 332);
    textItems[1]=addText("", font);
    textItems[1]->setPos(730, 362);
    textItems[2]=addText("", font);
    textItems[2]->setPos(730, 392);
    textItems[3]=addText("", font);
    textItems[3]->setPos(10, 500);
    QPixmap i(160, 60);
    i=paint(i, 0, 0, "Hp Fluid", "Mp Fluid", "Tea", "Milk");
    itemTab=new QGraphicsPixmapItem(i);
    itemTab->setPos(620, 425);
    QPixmap s(160, 60);
    s=paint(s, 0, 0, "Frost", "Fireball", "Cure", "Quake");
    skillTab=new QGraphicsPixmapItem(s);
    skillTab->setPos(620, 425);
    indicant=new IndicantBattle(620);
    addItem(indicant);
}
void Battle::startBattle(ActorEnemy *enemy)
{
    indicant->reset();
    textItems[0]->setPlainText(QString::number(player->getHp()));
    textItems[1]->setPlainText(QString::number(player->getMp()));
    textItems[2]->setPlainText(QString::number(player->getLvl()));
    isNewText=true;
    endOfBattle=false;
    this->enemy=enemy;
    enemy->setPos(384, 200);
    addItem(enemy);
    textItems[3]->setPlainText("You were attacked by "+enemy->getName()+".");
}
void Battle::endBattle(bool hasWon)
{
    endOfBattle=true;
    isNewText=true;
    if(hasWon)
    {
        if(player->getItems()->indexOf(enemy->getLoot())==-1) player->getItems()->push_back(enemy->getLoot());
        else delete enemy->getLoot();
        player->changeExp(enemy->getExp());
        textItems[3]->setPlainText(textItems[3]->toPlainText()+"You won the battle and earned "+
                QString::number(enemy->getExp())+" experience points.");
        player->lvlUp();
        removeItem(enemy);
        delete enemy;
    }
    else
    {
        player->changeExp(-10);
        textItems[3]->setPlainText("You lost the battle.");
    }
}
void Battle::enemyTurn()
{
    int damage=qMax(0, enemy->getAttack()-player->getDefence());
    textItems[3]->setPlainText(textItems[3]->toPlainText()+"You lost "+
            QString::number(player->changeHp(-damage))+" hp due to "+enemy->getName()+"'s attack.");
    isNewText=true;
    textItems[0]->setPlainText(QString::number(player->getHp()));
    if(player->getHp()<=0)
    {
        endBattle(0);
    }
}
void Battle::check()
{
    textItems[1]->setPlainText(QString::number(player->getMp()));
    if(state->goBack())
    {
        delete state;
        state=new BattleStateDefault();
        indicant->reset();
        removeItem(itemAt(620, 425, QTransform()));
    }
    if(enemy->getHp()<=0) endBattle(1);
    else enemyTurn();
}
void Battle::keyPressEvent(QKeyEvent *event)
{
    if(isNewText&&(event->key()==Qt::Key_X||event->key()==Qt::Key_Z))
    {
        if(endOfBattle) emit battleEnd();
        else
        {
            isNewText=false;
            textItems[3]->setPlainText("What are you going to do?");
        }
    }
    else if(!isNewText)
    {
        if(event->key()==Qt::Key_Up||event->key()==Qt::Key_Down) indicant->move(0);
        if(event->key()==Qt::Key_Right||event->key()==Qt::Key_Left) indicant->move(1);
        if(event->key()==Qt::Key_X) state->go(this);
        if(event->key()==Qt::Key_Z&&state->goBack())
        {
            delete state;
            state=new BattleStateDefault();
            indicant->reset();
            removeItem(itemAt(620, 425, QTransform()));
        }
    }
}
void Battle::attack()
{
    int damage=qMax(0, player->getAttack()-enemy->getDefence());
    textItems[3]->setPlainText("You dealt "+QString::number(enemy->changeHp(-damage))+
                               " damage to the "+enemy->getName()+".\n\n");
    check();
}
void Battle::goItems()
{
    delete state;
    state=new BattleStateItems();
    indicant->reset();
    addItem(itemTab);
}
void Battle::goSkills()
{
    delete state;
    state=new BattleStateSkills();
    indicant->reset();
    addItem(skillTab);
}
void Battle::flee()
{
    if(qrand()%2==0)
    {
        indicant->reset();
        delete enemy;
        emit battleEnd();
    }
    else
    {
        textItems[3]->setPlainText("You failed to escape.\n\n");
        enemyTurn();
    }
}
void Battle::useItem()
{
    textItems[3]->setPlainText(player->getItems()->at(indicant->getPosition())->use(player));
    check();
}
void Battle::useSkill()
{
    textItems[3]->setPlainText(player->getSkills()->at(indicant->getPosition())->use(player, enemy));
    check();
}
ActorPlayer *Battle::getPlayer()
{
    return player;
}
IndicantBattle *Battle::getIndicant()
{
    return indicant;
}
QPixmap Battle::paint(QPixmap pixmap, int x, int y, QString text1, QString text2, QString text3, QString text4)
{
    QFont font;
    font.setPointSize(12);
    QPainter painter(&pixmap);
    painter.setFont(font);
    painter.drawRect(x, y, 160, 60);
    painter.fillRect(x+1, y+1, 159, 59, Qt::lightGray);
    painter.drawText(x+15, y, 65, 30, Qt::AlignVCenter | Qt::AlignLeft, text1);
    painter.drawText(x+95, y, 65, 30, Qt::AlignVCenter | Qt::AlignLeft, text2);
    painter.drawText(x+15, y+30, 65, 30, Qt::AlignVCenter | Qt::AlignLeft, text3);
    painter.drawText(x+95, y+30, 65, 30, Qt::AlignVCenter | Qt::AlignLeft, text4);
    painter.end();
    return pixmap;
}
