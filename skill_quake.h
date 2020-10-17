#ifndef SKILL_QUAKE_H
#define SKILL_QUAKE_H

#include"skill.h"

class SkillQuake: public Skill
{
public:
    SkillQuake();
    QString use(ActorPlayer *player, ActorEnemy *enemy) final;
};

#endif // SKILL_QUAKE_H
