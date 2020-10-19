#include"item_bone.h"

ItemBone::ItemBone()
{
    name="Bone";
    pixmap=QPixmap(":/images/items.png").copy(384, 32, 32, 32);
}
QString ItemBone::use(ActorPlayer *)
{
    return "Random bone.";
}
