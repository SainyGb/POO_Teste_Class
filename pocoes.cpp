#include "pocoes.h"
#include "item.h"

Pocoes::Pocoes()
    : Item(), poder_(0), duracao_(0)

{
}

Pocoes::Pocoes(std::string &name, std::string &getDescription, int valor, int qtd, int poder, int duracao)
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
const Pocoes &Pocoes::operator=(const Pocoes &pocoes)
{

    this->setName(pocoes.getName());
    this->setValue(pocoes.getValue());
    this->setDescription(pocoes.getDescription());
    this->setQtd(pocoes.getQtd());
    this->setPoder(pocoes.getPoder());
    this->setDuracao(pocoes.getDuracao());

    return *this;
}

std::ostream &operator<<(std::ostream &out, const PocaoCura &pocoes)
{
    out << pocoes.getStats() << std::endl;
    return out;
}

bool Pocoes::operator==(const Pocoes &cp)
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
    return true;
}

bool Pocoes::operator!=(const Pocoes &cp)
{
    return !(*this == cp);
}

// Pocoes Pocoes::operator!()
// {
//     poder_++;
//     return *this;
// }

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

PocaoCura::PocaoCura(std::string &name, std::string &getDescription, int valor, int qtd, int poder, int duracao, int valorCura)
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
        " | Name: " + this->getName() + " | Description: " + this->getDescription() + " | Value: " + std::to_string(this->getValue()) + " | Poder: " + std::to_string(this->getPoder()) + " | Duracao: " + std::to_string(this->duracaoTotal()) + " | Cura: " + std::to_string(this->curaTotal());
}

// ----------------------------------------------------------------
PocaoDef::PocaoDef()
    : Pocoes(), valorDef_(0)

{
}

PocaoDef::PocaoDef(std::string &name, std::string &getDescription, int valor, int qtd, int poder, int duracao, int valorCura)
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
        " | Name: " + this->getName() + " | Description: " + this->getDescription() + " | Value: " + std::to_string(this->getValue()) + " | Poder: " + std::to_string(this->getPoder()) + " | Duracao: " + std::to_string(this->duracaoTotal()) + " | Aumenta a Defesa em: " + std::to_string(this->defTotal());
}