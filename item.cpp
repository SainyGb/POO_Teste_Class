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

// VER DEPOIS
// Item Item::operator!()
// {
//     qtd_++;
//     return *this;
// }
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
    if (qtd > 0 && qtd <= MAX_QTD)
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
    //*static_cast<Item *>(this) = static_cast<Item>(armor);

    this->setName(armor.getName());
    this->setValue(armor.getValue());
    this->setDescription(armor.getDescription());
    this->setQtd(armor.getQtd());
    this->setArmor(armor.getArmor());

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Armors &armor)
{
    out << armor.getStats() << std::endl;
    return out;
}

bool Armors::operator==(const Armors &cp)
{
    if (this->getName() != cp.getName())
    {
        return false;
    }
    if (this->getValue() != cp.getValue())
    {
        return false;
    }
    if (this->getDescription() != cp.getDescription())
    {
        return false;
    }
    if (this->getQtd() != cp.getQtd())
    {
        return false;
    }
    if (this->getArmor() != cp.getArmor())
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

// VIRTUAL FUNCTIONS

std::string Armors::getStats() const
{
    std::string str =
        " | Name: " + this->getName() + " | Description: " + this->getDescription() + " | Value: " + std::to_string(this->getValue()) + " | Armor: " + std::to_string(this->getArmor());

    return str;
}

// VIRTUAL FUNCTIONS
Armors *Armors::clone() const
{
    return new Armors(*this);
}
