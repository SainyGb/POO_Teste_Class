#include "weapons.h"

Weapons::Weapons() : Item(), maxDmg_(0), minDmg_(0), durability_(0)
{
}

Weapons::Weapons(const std::string &n, const std::string &d, int value, int qtd, int mxdg, int mdg, int dura)
    : Item(n, d, value, qtd)
{
    setMaxDmg(mxdg);
    setMinDmg(mdg);
    setDurability(dura);
}

Weapons::Weapons(const Item &cp, int mxdg, int mdg, int dura)
    : Item(cp)
{
    setMaxDmg(mxdg);
    setMinDmg(mdg);
    setDurability(dura);
}

Weapons::Weapons(const Weapons &cpW)
    : Item(cpW)
{
    setMaxDmg(cpW.getMaxDmg());
    setMinDmg(cpW.getMinDmg());
    setDurability(cpW.getDurability());
}

Weapons::~Weapons()
{
}

// Weapons Weapons::operator!()
// {
//     durability_++;
//     return *this;
// }

// SETS AND GETS
// SETS
void Weapons::setMinDmg(int dmg)
{
    if (dmg > 0 && dmg <= this->maxDmg_)
    {
        minDmg_ = dmg;
        return;
    }
    std::cout << "valor invalido (setDmg)\n";
    minDmg_ = 0;
}

void Weapons::setMaxDmg(int dmg)
{
    if (dmg > 0 && dmg < MAX_DMG)
    {
        maxDmg_ = dmg;
        return;
    }
    std::cout << "valor invalido (setDmg)\n";
    maxDmg_ = 0;
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

int Weapons::getMinDmg() const
{
    return minDmg_;
}

int Weapons::getMaxDmg() const
{
    return maxDmg_;
}

int Weapons::getDurability() const
{
    return durability_;
}

// FUNCTIONS
void Weapons::durabilityDmg()
{
    if (getDurability() <= 0)
    {
        breakWeapons();
        return;
    }
    durability_ -= 1;
}

void Weapons::breakWeapons()
{
    setMaxDmg(0);
    setMinDmg(0);
    std::cout << "A arma esta danificada demais para ser efetiva, troque a arma" << std::endl;
}

//----------------------------------------------------------------

MagicWeapons::MagicWeapons()
    : Weapons(), element_(0), power_level_(0)
{
}

MagicWeapons::MagicWeapons(const std::string &n, const std::string &d, int value, int qtd, int mxdg, int mdg, int dura, int el, int pw)
    : Weapons(n, d, value, qtd, mxdg, mdg, dura)
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
    this->setName(mw.getName());
    this->setValue(mw.getValue());
    this->setDescription(mw.getDescription());
    this->setQtd(mw.getQtd());
    this->setMaxDmg(mw.getMaxDmg());
    this->setMinDmg(mw.getMinDmg());
    this->setDurability(mw.getDurability());
    this->setElement(mw.getElement());
    this->setPowerLvl(mw.getPowerLvl());
    return *this;
}

std::ostream &operator<<(std::ostream &out, const MagicWeapons &mw)
{
    out << mw.getStats() << std::endl;

    return out;
}

bool MagicWeapons::operator==(const MagicWeapons &cp)
{
    if (this->getName() != cp.getName())
    {
        return false;
    }
    if (this->getValue() != cp.getValue())
    {
        return false;
    }
    if (this->getQtd() != cp.getQtd())
    {
        return false;
    }
    if (this->getMaxDmg() != cp.getMaxDmg())
    {
        return false;
    }
    if (this->getMinDmg() != cp.getMinDmg())
    {
        return false;
    }
    if (this->getDurability() != cp.getDurability())
    {
        return false;
    }
    if (this->getElement() != cp.getElement())
    {
        return false;
    }
    if (this->getPowerLvl() != cp.getPowerLvl())
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

// FUNCTIONS
int MagicWeapons::magicMissiles()
{
    return attack() * rand() % 5 + 1;
}

// VIRTUAL FUNCTIONS
std::string MagicWeapons::getStats() const
{
    std::string str =
        " | Name: " + this->getName() + " | Description: " + this->getDescription() + " | Value: " + std::to_string(this->getValue()) + " | Damage: " + std::to_string(this->getMinDmg()) + " - " + std::to_string(this->getMaxDmg()) +
        " | Durability: " +
        std::to_string(this->getDurability()) + " | Element: " + std::to_string(this->getElement()) +
        " | Power Level: " + std::to_string(this->getPowerLvl()) + "\n";

    return str;
}

MagicWeapons *MagicWeapons::clone() const
{
    return new MagicWeapons(*this);
}

int MagicWeapons::attack()
{
    durabilityDmg();
    return (int)(1.25 * (rand() % getMaxDmg() + getMinDmg()));
}

//----------------------------------------------------------------
// Swords CLASS
Swords::Swords()
    : Weapons(), poder_(0)
{
}

Swords::Swords(const std::string &n, const std::string &d, int value, int qtd, int mxdg, int mdg, int dura, int pd)
    : Weapons(n, d, value, qtd, mxdg, mdg, dura)
{
    setPoder(pd);
}

Swords::Swords(const Weapons &cp, int pd)
    : Weapons(cp)
{
    setPoder(pd);
}

Swords::Swords(const Swords &cpP)
    : Weapons(cpP)
{
    setPoder(cpP.getPoder());
}

Swords::~Swords()
{
}

// OPERATORS
// VER DEPOIS
const Swords &Swords::operator=(const Swords &swords)
{
    this->setName(swords.getName());
    this->setDescription(swords.getDescription());
    this->setValue(swords.getValue());
    this->setQtd(swords.getQtd());
    this->setMaxDmg(swords.getMaxDmg());
    this->setMinDmg(swords.getMinDmg());
    this->setDurability(swords.getDurability());
    this->setPoder(swords.getPoder());

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Swords &swords)
{
    out << swords.getStats() << std::endl;

    return out;
}

bool Swords::operator==(const Swords &cp)
{
    if (this->getName() != cp.getName())
    {
        return false;
    }
    if (this->getValue() != cp.getValue())
    {
        return false;
    }
    if (this->getQtd() != cp.getQtd())
    {
        return false;
    }
    if (this->getMaxDmg() != cp.getMaxDmg())
    {
        return false;
    }
    if (this->getMinDmg() != cp.getMinDmg())
    {
        return false;
    }
    if (this->getDurability() != cp.getDurability())
    {
        return false;
    }
    if (this->getPoder() != cp.getPoder())
    {
        return false;
    }
    return true;
}

bool Swords::operator!=(const Swords &cp)
{
    return !(*this == cp);
}

Swords Swords::operator!()
{
    poder_++;
    return *this;
}

// SETS AND GETS
//  SETS
void Swords::setPoder(int poder)
{
    if (poder > 0 && poder < MAX_PODER)
    {
        poder_ = poder;
        return;
    }
    std::cout << "valor invalido (setPoder)" << std::endl;
    poder_ = poder;
    return;
}
// GETS
int Swords::getPoder() const
{
    return poder_;
}

// FUNCTIONS
int Swords::doubleSLice()
{
    return (int)((double)attack() * 1.5);
}

// VIRTUAL FUNCTIONS
std::string
Swords::getStats() const
{
    std::string str =
        " | Name: " + this->getName() + " | Description: " + this->getDescription() + " | Value: " + std::to_string(this->getValue()) + " | Dano: " + std::to_string(this->getMinDmg()) + " - " + std::to_string(this->getMaxDmg()) +
        " | Durability: " + std::to_string(this->getDurability()) + " | Poder: " + std::to_string(this->getPoder()) + "\n";
    return str;
}

Swords *Swords::clone() const
{
    return new Swords(*this);
}

int Swords::attack()
{
    int minDmg, maxDmg;
    minDmg = getMinDmg();
    maxDmg = getMaxDmg();
    durabilityDmg();
    return rand() % maxDmg + minDmg;
}

//----------------------------------------------------------------

Murasama::Murasama()
    : Swords(), hiddenPowerIsActive_(false), ragePool_(0)
{
    // beenAcquired_ = false;
}

Murasama::Murasama(const std::string &n, const std::string &d, int value, int qtd, int mxdg, int mdg, int dura, int p, bool beenAcquired, int rage)
    : Swords(n, d, value, qtd, mxdg, mdg, dura, p), hiddenPowerIsActive_(false)
{
    // beenAcquired_ = true;
    setRagePool(rage);
}

Murasama::Murasama(const Murasama &other)
    : Swords(other), hiddenPowerIsActive_(false)
{
    // beenAcquired_ = true;
    setRagePool(other.getRagePool());
}

Murasama::~Murasama()
{
}

// OPERATORS
const Murasama &Murasama::operator=(const Murasama &swords)
{
    *static_cast<Murasama *>(this) = static_cast<Murasama>(swords);
    this->hiddenPowerIsActive_ = swords.hiddenPowerIsActive_;
    this->setRagePool(swords.getRagePool());

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Murasama &swords)
{
    out << swords.getStats() << std::endl;

    return out;
}

bool Murasama::operator==(const Murasama &cp)
{
    if (static_cast<Murasama>(*this) != static_cast<Murasama>(cp))
    {
        return false;
    }
    if (this->getHiddenPower() != cp.getHiddenPower())
    {
        return false;
    }
    if (this->getRagePool() != cp.getRagePool())
    {
        return false;
    }
    return true;
}

bool Murasama::operator!=(const Murasama &cp)
{
    return !(*this == cp);
}

Murasama Murasama::operator!()
{
    setMinDmg(getMinDmg() + 2);
    setMaxDmg(getMaxDmg() + 3);
    return *this;
}

// SETTERS

void Murasama::setRagePool(int rage)
{
    if (rage <= 0 && rage <= 100)
    {
        ragePool_ = rage;
        return;
    }
    std::cout << "valor invalido (setRagePool)" << std::endl;
    ragePool_ = 0;
    return;
}

// GETTERS
bool Murasama::getHiddenPower() const
{
    return hiddenPowerIsActive_;
}

// bool Murasama::getBeenAcquired() const
// {
//     return beenAcquired_;
// }

int Murasama::getRagePool() const
{
    return ragePool_;
}

// FUNCTIONS
int Murasama::lingchi()
{
    if (getHiddenPower())
    {
        lockHiddenPower();
        return this->getPoder() * (attack() * (int)(350 / 100));
    }
}

void Murasama::unlockHiddenPower()
{
    if (this->getRagePool() >= 100)
    {
        hiddenPowerIsActive_ = true;
        return;
    }
    std::cout << "Voce ainda nao pode despertar." << std::endl;
    return;
}

void Murasama::lockHiddenPower()
{
    setRagePool(0);
    hiddenPowerIsActive_ = false;
    return;
}

void Murasama::decreaseRagePool()
{
    if (ragePool_ <= 10)
    {
        ragePool_ = 0;
        lockHiddenPower();
        return;
    }
    ragePool_ -= 10;
}

void Murasama::increaseRagePool()
{
    if (ragePool_ >= 100)
    {
        ragePool_ = 100;
        return;
    }
    ragePool_ += 10;
}

// VIRTUAL FUNCTIONS
std::string Murasama::getStats() const
{
    std::string str =
        " | Name: " + this->getName() + " | Description: " + this->getDescription() + " | Value: " + std::to_string(this->getValue()) + " | Dano: " + std::to_string(this->getMinDmg()) + " - " + std::to_string(this->getMaxDmg()) +
        " | Durability: " + std::to_string(this->getDurability()) + " | Rage Meter: " + std::to_string(this->getRagePool()) + "/100" + " | Poder: " + std::to_string(this->getPoder()) + "\n";
    return str;
}

Murasama *Murasama::clone() const
{
    return new Murasama(*this);
}

int Murasama::attack()
{
    int minDmg, maxDmg;
    minDmg = getMinDmg();
    maxDmg = getMaxDmg();
    if (getHiddenPower())
    {
        decreaseRagePool();
        return getPoder() * (int)((double)(125.0 / 100.0) * (double)(rand() % getMaxDmg() + getMinDmg()));
    }
    increaseRagePool();
    durabilityDmg();
    return getPoder() * (rand() % getMaxDmg() + getMinDmg());
}

//----------------------------------------------------------------
Excalibur::Excalibur()
    : Swords(), energyPool_(0)
{
    // beenAcquired_ = false;
}

Excalibur::Excalibur(const std::string &name, const std::string &description, int value, int qtd, int mxdg, int mdg, int dura, int poder, int energy)
    : Swords(name, description, value, qtd, mxdg, mdg, dura, poder)
{
    // beenAcquired_ = true;
    setEnergy(energy);
}

Excalibur::Excalibur(const Excalibur &other)
    : Swords(other)
{
    // beenAcquired_ = true;
    setEnergy(other.getEnergy());
}

Excalibur::~Excalibur()
{
}

// OPERATORS
const Excalibur &Excalibur::operator=(const Excalibur &swords)
{
    *static_cast<Excalibur *>(this) = static_cast<Excalibur>(swords);
    this->setEnergy(swords.getEnergy());

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Excalibur &swords)
{
    out << swords.getStats() << std::endl;

    return out;
}

bool Excalibur::operator==(const Excalibur &cp)
{
    if (static_cast<Excalibur>(*this) != static_cast<Excalibur>(cp))
    {
        return false;
    }
    if (this->getEnergy() != cp.getEnergy())
    {
        return false;
    }
    return true;
}

bool Excalibur::operator!=(const Excalibur &cp)
{
    return !(*this == cp);
}

Excalibur Excalibur::operator!()
{
    setMinDmg(getMinDmg() + 2);
    setMaxDmg(getMaxDmg() + 3);
    return *this;
}

// SETTERS
void Excalibur::setEnergy(int energy)
{
    if (energy >= 0 && energy <= 100)
    {
        energyPool_ = energy;
        return;
    }
    energyPool_ = 0;
    std::cout << "valor invalido (setEnergy)" << std::endl;
    return;
}

// GETTERS
int Excalibur::getEnergy() const
{
    return energyPool_;
}

// bool Excalibur::getBeenAcquired() const
// {
//     return beenAcquired_;
// }

// FUNCTIONS

void Excalibur::increaseEnergy()
{
    if (energyPool_ >= 100)
    {
        energyPool_ = 100;
        std::cout << "Voce sente Excalibur tremeluzindo em sua mao" << std::endl;
        return;
    }
    energyPool_ += 10;
}

void Excalibur::resetEnergy()
{
    setEnergy(0);
}

int Excalibur::excalibur()
{

    if (getEnergy() >= 100)
    {
        resetEnergy();
        return getPoder() * (int)(attack() * (825.0 / 100.0));
    }
    std::cout << "Excalibur ainda nao estava pronta para liberar seu poder..." << std::endl;
    resetEnergy();
    return getPoder() * (int)(attack() + (attack() * (getEnergy() / 100)));
}

// VIRTUAL FUNCTIONS
std::string Excalibur::getStats() const
{
    std::string str =
        " | Name: " + this->getName() + " | Description: " + this->getDescription() + " | Value: " + std::to_string(this->getValue()) + " | Dano: " + std::to_string(this->getMinDmg()) + " - " + std::to_string(this->getMaxDmg()) +
        " | Durability: " + std::to_string(this->getDurability()) + " | Energy Pool: " + std::to_string(this->getEnergy()) + "/100" + " | Poder: " + std::to_string(this->getPoder()) + "\n";
    return str;
}

Excalibur *Excalibur::clone() const
{
    return new Excalibur(*this);
}

int Excalibur::attack()
{
    int minDmg, maxDmg;
    minDmg = getMinDmg();
    maxDmg = getMaxDmg();
    return getPoder() * (rand() % maxDmg + minDmg);
}