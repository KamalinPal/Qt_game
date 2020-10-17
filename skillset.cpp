#include"skillset.h"
#include"skill_frost.h"
#include"skill_fireball.h"
#include"skill_cure.h"
#include"skill_quake.h"

Skillset::Skillset()
{
    skills.push_back(new SkillFrost());
    skills.push_back(new SkillFireball());
    skills.push_back(new SkillCure());
    skills.push_back(new SkillQuake());
}
Skill* Skillset::getSkill(int i)
{
    return skills[i];
}
