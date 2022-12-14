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
Armors::Armors(const std::string &n, const std::string &d, int value, int qtd, int arm, int dbrt)
    : Item(n, d, value, qtd)
{
    setArmor(arm);
    setDurability(dbrt);
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
    this->setDurability(armor.getDurability());

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

void Armors::setDurability(int durability)
{
    if (durability >= 0)
    {
        durability_ = durability;
        return;
    }
    durability_ = 0;
}

// GETS
int Armors::getArmor() const
{
    return armor_;
}

int Armors::getDurability() const
{
    return durability_;
}

// FUNCTIONS

void Armors::breakArmor()
{
    setArmor(0);
    std::cout << "Armadura danificada de mais para lhe proteger, troque de armadura" << std::endl;
}

void Armors::durabilityDmg()
{
    if (getDurability() <= 0)
    {
        breakArmor();
        return;
    }
    durability_ -= 1;
}

// VIRTUAL FUNCTIONS

std::string Armors::getStats() const
{
    std::string str =
        " | Name: " + this->getName() + " | Description: " + this->getDescription() + " | Value: " + std::to_string(this->getValue()) + " | Armor: " + std::to_string(this->getArmor()) + "\n";

    return str;
}

// VIRTUAL FUNCTIONS
Armors *Armors::clone() const
{
    return new Armors(*this);
}

//----------------------------------------------------------------

Pocoes::Pocoes()
    : Item(), poder_(0), duracao_(0)

{
}

Pocoes::Pocoes(const std::string &name, const std::string &getDescription, int valor, int qtd, int poder, int duracao)
    : Item(name, getDescription, valor, qtd)
{
    setPoder(poder);
    setDuracao(duracao);
}

Pocoes::Pocoes(const Pocoes &other)
    : Item(other)
{
    setPoder(other.getPoder());
    setDuracao(other.getDuracao());
}

Pocoes::~Pocoes()
{
}

// OPERATORS

//  SETTERS
void Pocoes::setPoder(int poder)
{
    if (poder > 0 && poder <= 5)
    {
        poder_ = poder;
        return;
    }
    std::cout << "valor invalido (setPoder)\n";
    return;
}

void Pocoes::setDuracao(int duracao)
{
    if (duracao >= 0 && duracao <= 5)
    {
        duracao_ = duracao;
        return;
    }
    std::cout << "valor invalido (setDuracao)\n";
    return;
}

// GETTERS
int Pocoes::getPoder() const
{
    return poder_;
}

int Pocoes::getDuracao() const
{
    return duracao_;
}

// FUNCTIONS
int Pocoes::duracaoTotal() const
{
    return (this->getDuracao() * this->getPoder());
}

//----------------------------------------------------------------
PocaoCura::PocaoCura()
    : Pocoes(), valorCura_(0)

{
}

PocaoCura::PocaoCura(const std::string &name, const std::string &getDescription, int valor, int qtd, int poder, int duracao, int valorCura)
    : Pocoes(name, getDescription, valor, qtd, poder, duracao)
{
    setValorCura(valorCura);
}

PocaoCura::PocaoCura(const PocaoCura &other)
    : Pocoes(other)
{
    setValorCura(other.getValorCura());
}

PocaoCura::~PocaoCura()
{
}

// OPERATORS

const PocaoCura &PocaoCura::operator=(const PocaoCura &pocoes)
{

    this->setName(pocoes.getName());
    this->setValue(pocoes.getValue());
    this->setDescription(pocoes.getDescription());
    this->setQtd(pocoes.getQtd());
    this->setPoder(pocoes.getPoder());
    this->setDuracao(pocoes.getDuracao());
    this->setValorCura(pocoes.getValorCura());

    return *this;
}

std::ostream &operator<<(std::ostream &out, const PocaoCura &pocoes)
{
    out << pocoes.getStats() << std::endl;
    return out;
}

bool PocaoCura::operator==(const PocaoCura &cp)
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
    if (this->getPoder() != cp.getPoder())
    {
        return false;
    }
    if (this->getDuracao() != cp.getDuracao())
    {
        return false;
    }
    if (this->getValorCura() != cp.getValorCura())
    {
        return false;
    }
    return true;
}

bool PocaoCura::operator!=(const PocaoCura &cp)
{
    return !(*this == cp);
}

PocaoCura PocaoCura::operator!()
{
    valorCura_ += 10;
    return *this;
}

// SETTERS
void PocaoCura::setValorCura(int valorCura)
{
    if (valorCura > 0 && valorCura < (HP_CAP / 5))
    {
        valorCura_ = valorCura;
        return;
    }
    std::cout << "valor invalido (setValorCura)" << std::endl;
    return;
}

int PocaoCura::getValorCura() const
{
    return valorCura_;
}

// FUNCTIONS
int PocaoCura::curaTotal() const
{
    return (this->getValorCura() * this->getPoder());
}

// VIRTUAL FUNCTIONS
PocaoCura *PocaoCura::clone() const
{
    return new PocaoCura(*this);
}

std::string PocaoCura::getStats() const
{
    std::string str =
        " | Name: " + this->getName() + " | Description: " + this->getDescription() + " | Value: " + std::to_string(this->getValue()) + " | Poder: " + std::to_string(this->getPoder()) + " | Duracao: " + std::to_string(this->duracaoTotal()) + " | Cura: " + std::to_string(this->curaTotal()) + "\n";
}

// ----------------------------------------------------------------
PocaoDef::PocaoDef()
    : Pocoes(), valorDef_(0)

{
}

PocaoDef::PocaoDef(const std::string &name, const std::string &getDescription, int valor, int qtd, int poder, int duracao, int valorCura)
    : Pocoes(name, getDescription, valor, qtd, poder, duracao)
{
    setValorDef(valorCura);
}

PocaoDef::PocaoDef(const PocaoDef &other)
    : Pocoes(other)
{
    setValorDef(other.getValorDef());
}

PocaoDef::~PocaoDef()
{
}

// OPERATORS

const PocaoDef &PocaoDef::operator=(const PocaoDef &pocoes)
{

    this->setName(pocoes.getName());
    this->setValue(pocoes.getValue());
    this->setDescription(pocoes.getDescription());
    this->setQtd(pocoes.getQtd());
    this->setPoder(pocoes.getPoder());
    this->setDuracao(pocoes.getDuracao());
    this->setValorDef(pocoes.getValorDef());

    return *this;
}

std::ostream &operator<<(std::ostream &out, const PocaoDef &pocoes)
{
    out << pocoes.getStats() << std::endl;
    return out;
}

bool PocaoDef::operator==(const PocaoDef &cp)
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
    if (this->getPoder() != cp.getPoder())
    {
        return false;
    }
    if (this->getDuracao() != cp.getDuracao())
    {
        return false;
    }
    if (this->getValorDef() != cp.getValorDef())
    {
        return false;
    }
    return true;
}

bool PocaoDef::operator!=(const PocaoDef &cp)
{
    return !(*this == cp);
}

PocaoDef PocaoDef::operator!()
{
    valorDef_ += 5;
    return *this;
}

// SETTERS
void PocaoDef::setValorDef(int valor)
{
    if (valor > 0 && valor < DEF_CAP)
    {
        valorDef_ = valor;
        return;
    }
    std::cout << "valor invalido (setValorDef)" << std::endl;
}

// GETTERS
int PocaoDef::getValorDef() const
{
    return valorDef_;
}

// FUNCTIONS
int PocaoDef::defTotal() const
{
    return (this->getValorDef() * this->getPoder());
}

// VIRTUAL FUNCTIONS
PocaoDef *PocaoDef::clone() const
{
    return new PocaoDef(*this);
}

std::string PocaoDef::getStats() const
{
    std::string str =
        " | Name: " + this->getName() + " | Description: " + this->getDescription() + " | Value: " + std::to_string(this->getValue()) + " | Poder: " + std::to_string(this->getPoder()) + " | Duracao: " + std::to_string(this->duracaoTotal()) + " | Aumenta a Defesa em: " + std::to_string(this->defTotal()) + "\n";
}