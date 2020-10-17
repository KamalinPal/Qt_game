#ifndef SKILL_OFFENSIVE_H
#define SKILL_OFFENSIVE_H

#include"skill.h"

class SkillOffensive: public Skill
{
public:
    SkillOffensive();
    QString use(ActorPlayer *player, ActorEnemy *enemy)=0;
};

#endif // SKILL_OFFENSIVE_H
