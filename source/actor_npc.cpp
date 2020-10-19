#include"actor_npc.h"
#include<QtDebug>

ActorNpc::ActorNpc()
{

}
QVector<QString> ActorNpc::talk(ActorPlayer *)
{
    return text;
}
