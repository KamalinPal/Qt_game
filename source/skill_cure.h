#ifndef SKILL_CURE_H
#define SKILL_CURE_H

#include"skill.h"

class SkillCure: public Skill
{
public:
    SkillCure();
    virtual QString use(ActorPlayer *player, ActorEnemy*) final;
};

#endif // SKILL_CURE_H
