#include <iostream>
#include <string>

#include "item.h"

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
    unsigned int name_size = 16;
    if (n.length() < name_size)
    {
        name_ = n;
        return;
    }
    std::cout << "valor invalido\n";
    name_ = "noName";
}

void Item::setDescription(const std::string &d)
{
    unsigned int description_size = 500;
    if (d.length() < description_size)
    {
        description_ = d;
        return;
    }
    std::cout << "valor invalido\n";
    description_ = "noDescription";
}

void Item::setValue(int value)
{
    unsigned int value_cap = 9999999;
    if (value < 0 & value < value_cap)
    {
        value_ = value;
        return;
    }
    std::cout << "valor invalido\n";
    value_ = 0;
}

void Item::setQtd(int qtd)
{
    unsigned int qtd_cap = 9999999;
    if (qtd < 0 & qtd < qtd_cap)
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
