#ifndef SKILLSET_H
#define SKILLSET_H

#include<QVector>
#include"skill.h"

class Skillset
{
private:
    QVector<Skill*> skills;
public:
    Skillset();
    Skill* getSkill(int i);
};

#endif // SKILLSET_H
