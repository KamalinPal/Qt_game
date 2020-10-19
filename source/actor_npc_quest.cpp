#include"actor_npc_quest.h"
#include"actor_player.h"
#include"item_bone.h"
#include<QtDebug>

NpcQuest::NpcQuest()
{
    sheet=QPixmap(":/images/questnpc.png");
    setPixmap(sheet.copy(0, 0, 32, 48));
    name="QuestNpc";
}
QVector<QString> NpcQuest::talk(ActorPlayer *player)
{
    text.clear();
    int i;
    for(i=0;i<player->getItems()->length();++i) if(player->getItems()->at(i)->getName()=="Bone") break;
    if(i==player->getItems()->length()) text.push_back("Could you bring me a bone for my dog?");
    else
    {
        text.push_back("Thank you.");
        player->getItems()->removeAt(i);
    }
    return text;
}
