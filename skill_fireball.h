#ifndef SKILL_FIREBALL_H
#define SKILL_FIREBALL_H

#include"skill.h"

class SkillFireball: public Skill
{
public:
    SkillFireball();
    QString use(ActorPlayer *player, ActorEnemy *enemy) final;
};

#endif // SKILL_FIREBALL_H
