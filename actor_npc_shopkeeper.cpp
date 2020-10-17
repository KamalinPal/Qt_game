#include"actor_npc_shopkeeper.h"

NpcShopkeeper::NpcShopkeeper()
{
    sheet=QPixmap(":/images/shopkeeper.png");
    setPixmap(sheet.copy(0, 0, 32, 48));
    name="Shopkeeper";
    shop=new Shop();
}
Shop *NpcShopkeeper::getShop()
{
    return shop;
}
