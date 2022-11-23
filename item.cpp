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

// OPERATORS
const Item &Item::operator=(const Item &item)
{
    name_ = item.name_;
    description_ = item.description_;
    value_ = item.value_;
    qtd_ = item.qtd_;

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Item &item)
{
    out << item.name_ << " Stats" << std::endl;
    out << "Name: " << item.name_ << std::endl;
    out << "Description: " << item.description_ << std::endl;
    out << "Value: " << item.value_ << std::endl;
    out << "Quantity: " << item.qtd_ << std::endl;

    return out;
}
bool Item::operator==(const Item &cp)
{
    if (name_ != cp.name_)
    {
        return false;
    }
    if (description_ != cp.description_)
    {
        return false;
    }
    if (value_ != cp.value_)
    {
        return false;
    }
    if (qtd_ != cp.qtd_)
    {
        return false;
    }
}

bool Item::operator!=(const Item &cp)
{
    return !(*this == cp);
}

Item Item::operator!()
{
    qtd_++;
    return *this;
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
// ARMOR CLASS
Armors::Armors()
    : Item(), armor_(0)
{
}

Armors::Armors(const std::string &n, const std::string &d, int value, int qtd, int arm)
    : Item(n, d, value, qtd)
{
    setArmor(arm);
}

Armors::Armors(const Item &cp, int arm)
    : Item(cp)
{
    setArmor(arm);
}

Armors::Armors(const Armors &cpA)
    : Item(cpA)
{
    setArmor(cpA.getArmor());
}

Armors::~Armors()
{
}

// OPERATORS
const Armors &Armors::operator=(const Armors &armor)
{
    *static_cast<Item *>(this) = static_cast<Item>(armor);

    armor_ = armor.armor_;

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Armors &armor)
{
    out << static_cast<Item>(armor);
    out << "Armor: " << armor.armor_ << std::endl;

    return out;
}

bool Armors::operator==(const Armors &cp)
{
    if (static_cast<Item>(*this) != static_cast<Item>(cp))
    {
        return false;
    }
    if (armor_ != cp.armor_)
    {
        return false;
    }
    return true;
}

bool Armors::operator!=(const Armors &cp)
{
    return !(*this == cp);
}

Armors Armors::operator!()
{
    armor_++;
    return *this;
}

// SETS AND GETS
// SETS
void Armors::setArmor(int arm)
{
    if (arm >= 0 && arm < MAX_ARMOR)
    {
        armor_ = arm;
        return;
    }
    std::cout << "valor invalido (setArmor)" << std::endl;
    armor_ = 0;
    return;
}

// GETS
int Armors::getArmor() const
{
    return armor_;
}

//----------------------------------------------------------------
// POCOES CLASS

Pocoes::Pocoes()
    : Weapons(), poder_(0)
{
}

Pocoes::Pocoes(const std::string &n, const std::string &d, int value, int qtd, int dg, int dura, int pd)
    : Weapons(n, d, value, qtd, dg, dura)
{
    setPoder(pd);
}

Pocoes::Pocoes(const Weapons &cp, int pd)
    : Weapons(cp)
{
    setPoder(pd);
}

Pocoes::Pocoes(const Pocoes &cpP)
    : Weapons(cpP)
{
    setPoder(cpP.getPoder());
}

// OPERATORS
const Pocoes &Pocoes::operator=(const Pocoes &pocoes)
{
    *static_cast<Weapons *>(this) = static_cast<Weapons>(pocoes);

    poder_ = pocoes.poder_;

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Pocoes &pocoes)
{
    out << static_cast<Weapons>(pocoes);
    out << "Poder da Pocao: " << pocoes.poder_ << std::endl;

    return out;
}

bool Pocoes::operator==(const Pocoes &cp)
{
    if (static_cast<Pocoes>(*this) != static_cast<Pocoes>(cp))
    {
        return false;
    }
    if (poder_ != cp.poder_)
    {
        return false;
    }
    return true;
}

bool Pocoes::operator!=(const Pocoes &cp)
{
    return !(*this == cp);
}

Pocoes Pocoes::operator!()
{
    poder_++;
    return *this;
}

// SETS AND GETS
//  SETS
void Pocoes::setPoder(int poder)
{
    if (poder > 0 && poder < MAX_PODER)
    {
        poder_ = poder;
        return;
    }
    std::cout << "valor invalido (setPoder)" << std::endl;
    return;
}
// GETS
int Pocoes::getPoder() const
{
    return poder_;
}

Pocoes::~Pocoes()
{
}

//----------------------------------------------------------------
// WEAPON CLASS

Weapons::Weapons() : Item(), dmg_(0), durability_(0)
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

// OPERATORS
const Weapons &Weapons::operator=(const Weapons &weapon)
{
    *static_cast<Item *>(this) = static_cast<Item>(weapon);

    dmg_ = weapon.dmg_;
    durability_ = weapon.durability_;

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Weapons &weapon)
{
    out << static_cast<Item>(weapon);
    out << "Damage: " << weapon.dmg_ << std::endl;
    out << "Durability: " << weapon.durability_ << std::endl;

    return out;
}

bool Weapons::operator==(const Weapons &cp)
{
    if (static_cast<Item>(*this) != static_cast<Item>(cp))
    {
        return false;
    }
    if (dmg_ != cp.dmg_)
    {
        return false;
    }
    if (durability_ != cp.durability_)
    {
        return false;
    }
    return true;
}

bool Weapons::operator!=(const Weapons &cp)
{
    return !(*this == cp);
}

Weapons Weapons::operator!()
{
    durability_++;
    return *this;
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

// MagicWeapons CLASS
MagicWeapons::MagicWeapons()
    : Weapons(), element_(0), power_level_(0)
{
}

MagicWeapons::MagicWeapons(const std::string &n, const std::string &d, int value, int qtd, int dg, int dura, int el, int pw)
    : Weapons(n, d, value, qtd, dg, dura)
{
    setElement(el);
    setPowerLvl(pw);
}

MagicWeapons::MagicWeapons(const Weapons &cpS, int el, int pw)
    : Weapons(cpS)
{
    setElement(el);
    setPowerLvl(pw);
}

MagicWeapons::MagicWeapons(const MagicWeapons &cpS)
    : Weapons(cpS)
{
    setElement(cpS.getElement());
    setPowerLvl(cpS.getPowerLvl());
}

MagicWeapons::~MagicWeapons()
{
}

// OPERATORS
const MagicWeapons &MagicWeapons::operator=(const MagicWeapons &mw)
{
    *static_cast<Weapons *>(this) = static_cast<Weapons>(mw);

    element_ = mw.element_;
    power_level_ = mw.power_level_;

    return *this;
}

std::ostream &operator<<(std::ostream &out, const MagicWeapons &mw)
{
    out << static_cast<Weapons>(mw);
    out << "Tipo do elemento: " << mw.element_ << std::endl;
    out << "Porcentagem de Mana infundida: " << mw.power_level_ << "%" << std::endl;

    return out;
}

bool MagicWeapons::operator==(const MagicWeapons &cp)
{
    if (static_cast<MagicWeapons>(*this) != static_cast<MagicWeapons>(cp))
    {
        return false;
    }
    if (element_ != cp.element_)
    {
        return false;
    }
    if (power_level_ != cp.power_level_)
    {
        return false;
    }
    return true;
}

bool MagicWeapons::operator!=(const MagicWeapons &cp)
{
    return !(*this == cp);
}

MagicWeapons MagicWeapons::operator!()
{
    power_level_++;
    return *this;
}

// SETS AND GETS
// SETS
void MagicWeapons::setElement(int ele)
{
    if (ele >= 0 && ele <= 5)
    {
        element_ = ele;
        return;
    }
    std::cout << "valor invalido (setElement)" << std::endl;
    element_ = 0;
    return;
}

void MagicWeapons::setPowerLvl(int p)
{
    if (p > 0 && p <= 100)
    {
        power_level_ = p;
        return;
    }
    std::cout << "valor invalido (setPowerLvl)" << std::endl;
    power_level_ = 1;
    return;
}

// GETS
int MagicWeapons::getElement() const
{
    return element_;
}

int MagicWeapons::getPowerLvl() const
{
    return power_level_;
}
// Special properties
