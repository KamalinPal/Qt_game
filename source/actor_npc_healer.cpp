#include"actor_npc_healer.h"
#include"actor_player.h"

NpcHealer::NpcHealer()
{
    sheet=QPixmap(":/images/healer.png");
    setPixmap(sheet.copy(0, 0, 32, 48));
    name="Healer";
    text.push_back("Hello.");
    text.push_back("Let me heal your wounds.");
}
QVector<QString> NpcHealer::talk(ActorPlayer *player)
{
    player->changeHp(player->getMaxHp());
    player->changeMp(player->getMaxMp());
    return text;
}
