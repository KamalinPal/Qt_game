#-------------------------------------------------
#
# Project created by QtCreator 2017-11-07T21:22:36
#
#-------------------------------------------------

QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    game.cpp \
    map.cpp \
    menu.cpp \
    battle.cpp \
    indicant.cpp \
    indicant_battle.cpp \
    item.cpp \
    map_cafe.cpp \
    map_route.cpp \
    map_village.cpp \
    actor_player.cpp \
    actor.cpp \
    actor_enemy.cpp \
    skill.cpp \
    titlescreen.cpp \
    skill_fireball.cpp \
    skill_frost.cpp \
    skill_cure.cpp \
    skill_quake.cpp \
    actor_npc.cpp \
    consumable.cpp \
    equipment.cpp \
    equipable.cpp \
    equipable_armor.cpp \
    equipable_shield.cpp \
    equipable_sword.cpp \
    actor_npc_shopkeeper.cpp \
    menustate_default.cpp \
    menustate_items.cpp \
    menustate_save.cpp \
    menustate_skills.cpp \
    menustate_status.cpp \
    battlestate_default.cpp \
    battlestate_items.cpp \
    battlestate_skills.cpp \
    consumable_hpfluid.cpp \
    consumable_milk.cpp \
    consumable_mpfluid.cpp \
    consumable_tea.cpp \
    menustate.cpp \
    battlestate.cpp \
    shop.cpp \
    actor_npc_healer.cpp \
    actor_npc_quest.cpp \
    item_bone.cpp

HEADERS += \
    game.h \
    map.h \
    battle.h \
    indicant.h \
    indicant_battle.h \
    item.h \
    map_cafe.h \
    map_village.h \
    map_route.h \
    menu.h \
    actor.h \
    actor_player.h \
    actor_enemy.h \
    skill.h \
    titlescreen.h \
    skill_fireball.h \
    skill_frost.h \
    skill_cure.h \
    skill_quake.h \
    actor_npc.h \
    consumable.h \
    equipment.h \
    equipable.h \
    equipable_sword.h \
    battlestate.h \
    battlestate_default.h \
    battlestate_skills.h \
    battlestate_items.h \
    equipable_armor.h \
    equipable_shield.h \
    consumable_hpfluid.h \
    consumable_milk.h \
    consumable_mpfluid.h \
    consumable_tea.h \
    menustate.h \
    menustate_default.h \
    menustate_items.h \
    menustate_save.h \
    menustate_status.h \
    menustate_skills.h \
    actor_npc_shopkeeper.h \
    shop.h \
    actor_npc_healer.h \
    actor_npc_quest.h \
    item_bone.h

FORMS +=

RESOURCES += \
    zasoby.qrc

DISTFILES +=
