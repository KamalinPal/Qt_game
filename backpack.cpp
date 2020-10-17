#include"backpack.h"
#include"consumable_hpfluid.h"
#include"consumable_mpfluid.h"
#include"consumable_tea.h"
#include"consumable_milk.h"

Backpack::Backpack()
{
    items.push_back(new ConsumableHpFluid());
    items.push_back(new ConsumableMpFluid());
    items.push_back(new ConsumableTea());
    items.push_back(new ConsumableMilk());
}
QVector<Item*> Backpack::getItems()
{
    return items;
}
