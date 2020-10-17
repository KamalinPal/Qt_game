#ifndef SKILL_FIRSTAID_H
#define SKILL_FIRSTAID_H

#include"skill.h"

class SkillFrost: public Skill
{
public:
    SkillFrost();
    QString use(ActorPlayer *player, ActorEnemy *enemy) final;
};

#endif // SKILL_FIRSTAID_H
