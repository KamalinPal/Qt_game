#ifndef ACTOR_PLAYER_STATE_TALKING_H
#define ACTOR_PLAYER_STATE_TALKING_H

#include"actor_player_state.h"

class ActorPlayerStateTalking: public ActorPlayerState
{
public:
    ActorPlayerStateTalking();
    virtual ~ActorPlayerStateTalking();
    void action(ActorPlayer *player) final;
};

#endif // ACTOR_PLAYER_STATE_TALKING_H
