#ifndef SKILL_H
#define SKILL_H

#include<QString>
#include<QPixmap>

class ActorPlayer;
class ActorEnemy;

class Skill
{
protected:
    int cost;
    int effect;
    QString name;
    QPixmap pixmap;
public:
    Skill();
    virtual ~Skill();
    QString getName();
    QPixmap getPixmap();
    virtual QString use(ActorPlayer *player, ActorEnemy *enemy)=0;
};

#endif // SKILL_H
