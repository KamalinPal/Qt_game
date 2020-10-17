#ifndef ACTOR_PLAYER_STATE_WALKING_H
#define ACTOR_PLAYER_STATE_WALKING_H

#include"actor_player_state.h"

class ActorPlayerStateWalking: public ActorPlayerState
{
public:
    ActorPlayerStateWalking();
    virtual ~ActorPlayerStateWalking();
    void action(ActorPlayer *player) final;
};

#endif // ACTOR_PLAYER_STATE_WALKING_H
