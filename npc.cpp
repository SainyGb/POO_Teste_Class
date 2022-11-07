#include <iostream>
#include <string>

#include "npc.h"

Npc::Npc()
    : name_("noName"), lvl_(0), max_hp_(0), hp_(max_hp_), armor_(0), dmg_(0)
{
}

Npc::Npc(const std::string &name, int lvl, int mhp, int arm, int dmg)
{
    setName(name);
    setLvl(lvl);
    setMaxHp(mhp);
    setArmor(arm);
    setDmg(dmg);
}

Npc::Npc(const Npc &cp)
{
    setName(cp.getName());
    setLvl(cp.getLvl());
    setMaxHp(cp.getMaxHp());
    setArmor(cp.getArmor());
    setDmg(cp.getDmg());
}

Npc::~Npc()
{
}

// SETS AND GETS
// SETS

void Npc::setName(const std::string &name)
{
    if (name.length() > MAX_NAME_LENGTH)
    {
        name_ = name;
        return;
    }
    std::cout << "valor invalido\n";
    name_ = "noName";
    return;
}

void Npc::setLvl(int lvl)
{
    if (lvl < LVL_CAP)
    {
        lvl_ = lvl;
        return;
    }
    std::cout << "valor invalido\n";
    lvl_ = 0;
    return;
}

void Npc::setMaxHp(int hp)
{
    if (hp < HP_CAP)
    {
        max_hp_ = hp;
        hp_ = max_hp_;
        return;
    }
    std::cout << "valor invalido\n";
    hp_ = 0;
    return;
}

void Npc::setArmor(int armor)
{
    if (armor < ARMOR_CAP)
    {
        armor_ = armor;
        return;
    }
    std::cout << "valor invalido\n";
    armor_ = 0;
    return;
}

void Npc::setDmg(int dmg)
{
    if (dmg < DMG_CAP)
    {
        dmg_ = dmg;
        return;
    }
    std::cout << "valor invalido\n";
    dmg_ = 0;
    return;
}

// GETS

std::string Npc::getName() const
{
    return name_;
}

int Npc::getLvl() const
{
    return lvl_;
}

int Npc::getMaxHp() const
{
    return max_hp_;
}

int Npc::getArmor() const
{
    return armor_;
}

int Npc::getDmg() const
{
    return dmg_;
}