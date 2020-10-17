#ifndef SKILL_DEFENSIVE_H
#define SKILL_DEFENSIVE_H

#include"skill.h"

class SkillDefensive: public Skill
{
public:
    SkillDefensive();
    virtual QString use(ActorPlayer *player, ActorEnemy *enemy) final;
};

#endif // SKILL_DEFENSIVE_H
