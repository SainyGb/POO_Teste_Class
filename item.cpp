#include <iostream>
#include <string>

#include "item.h"

// ITEM CLASS
Item::Item()
    : name_("noName"), description_("noDescription"), value_(0), qtd_(0)
{
}

Item::Item(const std::string &n, const std::string &d, int value, int qtd)
{
    setName(n);
    setDescription(d);
    setValue(value);
    setQtd(qtd);
}

Item::Item(const Item &cp)
{
    setName(cp.getName());
    setDescription(cp.getDescription());
    setValue(cp.getValue());
    setQtd(cp.getQtd());
}

Item::~Item()
{
}

// SETS AND GETS
// SETS

void Item::setName(const std::string &n)
{
    if (n.length() < MAX_NAME_LENGTH)
    {
        name_ = n;
        return;
    }
    std::cout << "valor invalido\n";
    name_ = "noName";
}

void Item::setDescription(const std::string &d)
{
    if (d.length() < MAX_DESC_LENGTH)
    {
        description_ = d;
        return;
    }
    std::cout << "valor invalido\n";
    description_ = "noDescription";
}

void Item::setValue(int value)
{
    if (value < 0 & value < MAX_VALUE)
    {
        value_ = value;
        return;
    }
    std::cout << "valor invalido\n";
    value_ = 0;
}

void Item::setQtd(int qtd)
{
    if (qtd < 0 & qtd < MAX_QTD)
    {
        qtd_ = qtd;
        return;
    }
    std::cout << "valor invalido\n";
    qtd_ = 0;
}

// GETS

std::string Item::getName() const
{
    return name_;
}

std::string Item::getDescription() const
{
    return description_;
}

int Item::getValue() const
{
    return value_;
}

int Item::getQtd() const
{
    return qtd_;
}

//----------------------------------------------------------------
// SWORD CLASS

Swords::Swords()
    : Item(), dmg_(0), durability_(0)
{
}

Swords::Swords(const std::string &n, const std::string &d, int value, int qtd, int dg, int dura)
    : Item(n, d, value, qtd)
{
    setDmg(dg);
    setDurability(dura);
}

Swords::Swords(const Item &cp, int dg, int dura)
    : Item(cp)
{
    setDmg(dg);
    setDurability(dura);
}

Swords::Swords(const Item &cpI, const Swords &cpS)
    : Item(cpI)
{
    setDmg(cpS.getDmg());
    setDurability(cpS.getDurability());
}

Swords::~Swords()
{
}

// SETS AND GETS
// SETS
void Swords::setDmg(int dmg)
{
    if (dmg > 0 & dmg < MAX_DMG)
    {
        dmg_ = dmg;
        return;
    }
    std::cout << "valor invalido\n";
    dmg_ = 0;
}

void Swords::setDurability(int durability)
{
    if (durability > 0 & durability < MAX_DURA)
    {
        durability_ = durability;
        return;
    }
    std::cout << "valor invalido\n";
    durability_ = 0;
}

// GETS

int Swords::getDmg() const
{
    return dmg_;
}

int Swords::getDurability() const
{
    return durability_;
}