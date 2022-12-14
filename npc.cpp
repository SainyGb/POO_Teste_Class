#include <iostream>
#include <string>

#include "npc.h"

Npc::Npc()
    : name_("Bandido"), max_hp_(100), hp_(max_hp_), armor_(0), minDmg_(10), maxDmg_(15)
{
}

Npc::Npc(const std::string &name, int mhp, int arm, int mxdmg, int mdmg)
{
    setName(name);
    setMaxHp(mhp);
    setArmor(arm);
    setMinDmg(mdmg);
    setMaxDmg(mxdmg);
}

Npc::Npc(const Npc &cp)
{
    setName(cp.getName());
    setMaxHp(cp.getMaxHp());
    setArmor(cp.getArmor());
    setMinDmg(cp.getMinDmg());
    setMaxDmg(cp.getMaxDmg());
}

Npc::~Npc()
{
}

// SETS AND GETS
// SETS

void Npc::setName(const std::string &name)
{
    if (name.length() < MAX_NAME_LENGTH)
    {
        name_ = name;
        return;
    }
    std::cout << "valor invalido\n";
    name_ = "noName";
    return;
}

void Npc::setMaxHp(int hp)
{
    if (hp >= 0 && hp < HP_CAP)
    {
        max_hp_ = hp;
        hp_ = max_hp_;
        return;
    }

    std::cout << "valor invalido (setMaxHp) \n";
    max_hp_ = 0;
    hp_ = max_hp_;
}

void Npc::setArmor(int armor)
{
    if (armor >= 0 && armor < ARMOR_CAP)
    {
        armor_ = armor;
        return;
    }
    std::cout << "valor invalido (setArmor)\n";
    armor_ = 0;
    return;
}

// GETS

std::string Npc::getName() const
{
    return name_;
}

int Npc::getMaxHp() const
{
    return max_hp_;
}

int Npc::getArmor() const
{
    return armor_;
}

int Npc::getHp() const
{
    return hp_;
}

// COMBAT FUNCTIONS
bool Npc::isAlive() const
{
    return this->hp_ > 0;
}

int Npc::takeDamage(int damage)
{
    int totalDamage = damage - getArmor();
    if (totalDamage > 0)
    {
        hp_ -= totalDamage;
        return totalDamage;
    }
    if (this->hp_ <= 0)
    {
        this->hp_ = 0;
        return totalDamage;
    }
}

void Npc::setMinDmg(int dmg)
{
    if (dmg > 0)
    {
        minDmg_ = dmg;
        return;
    }
    std::cout << "valor invalido (setDmg)\n";
    minDmg_ = 0;
}

void Npc::setMaxDmg(int dmg)
{
    if (dmg > 0)
    {
        maxDmg_ = dmg;
        return;
    }
    std::cout << "valor invalido (setDmg)\n";
    maxDmg_ = 0;
}

int Npc::getMinDmg() const
{
    return minDmg_;
}

int Npc::getMaxDmg() const
{
    return maxDmg_;
}

int Npc::attack() const
{
    return rand() % getMaxDmg() + getMinDmg();
}