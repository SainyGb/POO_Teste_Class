#include <iostream>
#include <string>

#include "aventureiro.h"

Aventureiro::Aventureiro()
    : name_("noName"), max_hp_(0), hp_(max_hp_), armor_(0), dmg_(0), lvl_(0)
{
}

Aventureiro::Aventureiro(
    const std::string &nm, int mhp,
    int amr, int d, int lv)
{
    setName(nm);
    setMaxHp(mhp);
    setArmor(amr);
    setDmg(d);
    setLvl(lv);
}

Aventureiro::Aventureiro(const Aventureiro &cp)
{
    setName(cp.getName());
    setMaxHp(cp.getMaxHp());
    setArmor(cp.getArmor());
    setDmg(cp.getDmg());
    setLvl(cp.getLvl());
}

Aventureiro::~Aventureiro()
{
}

Aventureiro::~Aventureiro()
{
}

// SETS AND GETS
// SETS
void Aventureiro::setName(const std::string &name)
{
    if (name.length() < MAX_NAME_LENGTH)
    {
        name_ = name;
        return;
    }
    std::cout << "valor invalido\n";
    name_ = "noName";
}

void Aventureiro::setMaxHp(int hp)
{
    if (hp > 0 & hp < HP_CAP)
    {
        max_hp_ = hp;
        hp_ = max_hp_;
        return;
    }

    std::cout << "valor invalido\n";
    max_hp_ = 0;
    hp_ = max_hp_;
}

void Aventureiro::setArmor(int armor)
{
    if (armor > 0 & armor < ARMOR_CAP)
    {
        armor_ = armor;
        return;
    }

    std::cout << "valor invalido\n";
    armor_ = 0;
}

void Aventureiro::setDmg(int dmg)
{
    if (dmg > 0 & dmg < DMG_CAP)
    {
        dmg_ = dmg;
        return;
    }
    std::cout << "valor invalido\n";
    dmg_ = 0;
}

void Aventureiro::setLvl(int lvl)
{
    if (lvl > 0 & lvl < LVL_CAP)
    {
        lvl_ = lvl;
        return;
    }
    std::cout << "valor invalido\n";
    lvl_ = 0;
}

// GETS
std::string Aventureiro::getName() const
{
    return name_;
}

int Aventureiro::getMaxHp() const
{
    return max_hp_;
}

int Aventureiro::getArmor() const
{
    return armor_;
}

int Aventureiro::getDmg() const
{
    return dmg_;
}

int Aventureiro::getLvl() const
{
    return lvl_;
}