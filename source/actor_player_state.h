#ifndef ACTOR_PLAYER_STATE_H
#define ACTOR_PLAYER_STATE_H

class ActorPlayer;

class ActorPlayerState
{
public:
    ActorPlayerState();
    virtual ~ActorPlayerState();
    virtual void action(ActorPlayer *player)=0;
};

#endif // ACTOR_PLAYER_STATE_H
