#include <iostream>
#include <string>

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
    std::cout << "valor invalido (setName)\n";
    name_ = "noName";
}

void Item::setDescription(const std::string &d)
{
    if (d.length() < MAX_DESC_LENGTH)
    {
        description_ = d;
        return;
    }
    std::cout << "valor invalido (setDescription)\n";
    description_ = "noDescription";
}

void Item::setValue(int value)
{
    if (value >= 0 && value < MAX_VALUE)
    {
        value_ = value;
        return;
    }
    std::cout << "valor invalido (setValue)\n";
    value_ = 0;
}

void Item::setQtd(int qtd)
{
    if (qtd > 0 && qtd < MAX_QTD)
    {
        qtd_ = qtd;
        return;
    }
    std::cout << "valor invalido (setQtd)\n";
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
// WEAPON CLASS

Weapons::Weapons()
    : Item(), dmg_(0), durability_(0)
{
}

Weapons::Weapons(const std::string &n, const std::string &d, int value, int qtd, int dg, int dura)
    : Item(n, d, value, qtd)
{
    setDmg(dg);
    setDurability(dura);
}

Weapons::Weapons(const Item &cp, int dg, int dura)
    : Item(cp)
{
    setDmg(dg);
    setDurability(dura);
}

Weapons::Weapons(const Weapons &cpW)
    : Item(cpW)
{
    setDmg(cpW.getDmg());
    setDurability(cpW.getDurability());
}

Weapons::~Weapons()
{
}

// SETS AND GETS
// SETS
void Weapons::setDmg(int dmg)
{
    if (dmg > 0 && dmg < MAX_DMG)
    {
        dmg_ = dmg;
        return;
    }
    std::cout << "valor invalido (setDmg)\n";
    dmg_ = 0;
}

void Weapons::setDurability(int durability)
{
    if (durability > 0 && durability < MAX_DURA)
    {
        durability_ = durability;
        return;
    }
    std::cout << "valor invalido (setDurability)\n";
    durability_ = 0;
}

// GETS

int Weapons::getDmg() const
{
    return dmg_;
}

int Weapons::getDurability() const
{
    return durability_;
}

// SWORD CLASS
Swords::Swords()
    : Weapons(), autoSwingAttack_(false)
{
}

Swords::Swords(const std::string &n, const std::string &d, int value, int qtd, int dg, int dura, bool ast)
    : Weapons(n, d, value, qtd, dg, dura)
{
    setAutoSwing(ast);
}

Swords::Swords(const Weapons &cpS, bool ast)
    : Weapons(cpS)
{
    setAutoSwing(ast);
}

Swords::Swords(const Swords &cpS)
    : Weapons(cpS)
{
    setAutoSwing(cpS.getAutoSwing());
}

Swords::~Swords()
{
}

// SETS AND GETS
// SETS
void Swords::setAutoSwing(bool ast)
{
    autoSwingAttack_ = ast;
}

// GETS

bool Swords::getAutoSwing() const
{
    return autoSwingAttack_;
}

// Special properties

void Swords::TripleSwingAttack() const
{
    std::cout << "Triple Swing Attack did: " << getDmg() * 3 << std::endl;
}
