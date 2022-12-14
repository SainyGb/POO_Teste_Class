#include <iostream>
#include <string>
#include <typeinfo>

#include "aventureiro.h"
#include "item.h"
#include "weapons.h"

// TU N TEM ESCAPATORIA, SE QUISER FAZER O EQUIP DIREITO, VAI TER QUE ESTUDAR POLIMOFIRMO
// MAS SE TU DECIDIR QUE TA MTO EM CIMA DA HORA, SO REVERTER PARA O COMMIT QUE TA TUDO CERTO

Aventureiro::Aventureiro()
    : name_("noName"), max_hp_(0), hp_(max_hp_), def_(0)

{
}

Aventureiro::Aventureiro(
    const std::string &nm, int mhp,
    int amr, int d, int lv)
{
    setName(nm);
    setMaxHp(mhp);
    setDef(amr);
}

Aventureiro::Aventureiro(const Aventureiro &cp)
{
    setName(cp.getName());
    setMaxHp(cp.getMaxHp());
    setDef(cp.getDef());
}

Aventureiro::~Aventureiro()
{
}

void Aventureiro::inicializar(const std::string name)
{
    this->distanceTravelled = 0;
    this->setName(name);
    this->setMaxHp(250);
    Armors plate("Iron Plate", "Just a normal armor", 10, 1, 20, 100);
    Swords sword("Iron Sword", "A simple iron sword", 10, 1, 45, 35, 20, 1);
    addItem(sword);
    addItem(plate);
    equipItem(0);
    equipItem(0);
    invPocoes.push_back(new PocaoCura("Pocao de Cura", "Pocao que cura voce", 100, 1, 1, 0, 50));
    invPocoes.push_back(new PocaoCura("Pocao de Cura", "Pocao que cura voce", 100, 1, 1, 0, 50));
    invPocoes.push_back(new PocaoDef("Pocao de defesa", "Pocao que da defesa para voce", 100, 1, 1, 0, 50));
    invPocoes.push_back(new PocaoDef("Pocao de defesa", "Pocao que da defesa para voce", 100, 1, 1, 0, 50));
}

std::string Aventureiro::getStats() const
{

    std::string str =
        " | Name: " + this->getName() + " | Health: " + std::to_string(this->getMaxHp()) + "/" + std::to_string(this->getHp()) + " | Def: " + std::to_string(this->getDef()) + " | Dano: " + std::to_string(this->getMinDmg()) + " - " + std::to_string(this->getMaxDmg()) + " | Arma equipada: " + this->getArmaEquipada() +
        " | Armadura Equipada: " + this->getArmaduraEquipada() + "\n";
    return str;
}

// OPERATORS
std::ostream &operator<<(std::ostream &out, const Aventureiro &aventureiro)
{
    out
        << "Nome: " << aventureiro.getName() << std::endl;
    out << "Vida: " << aventureiro.getHp() << "/" << aventureiro.getMaxHp() << std::endl;
    out << "Armadura: " << aventureiro.getDef() << std::endl;
    out << std::endl;

    return out;
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
    std::cout << "valor invalido (setName)\n";
    name_ = "noName";
}

void Aventureiro::setMaxHp(int hp)
{
    if (hp >= 0 && hp < HP_CAP)
    {
        max_hp_ = hp;
        hp_ = max_hp_;
        return;
    }

    std::cout << "valor invalido (setMaxHp) aven \n";
    max_hp_ = 0;
    hp_ = max_hp_;
}

void Aventureiro::setDef(int armor)
{
    if (armor_.getArmor() > 0)
    {
        def_ = armor_.getArmor();
        return;
    }
    if (armor >= 0 && armor < DEF_CAP)
    {
        def_ = armor;
        return;
    }
    std::cout << "valor invalido (setDef)\n";
    def_ = 0;
}

void Aventureiro::setHp(int hp)
{
    if (hp >= 0 && hp < getMaxHp())
    {
        hp_ = hp;
        return;
    }
    if (hp > getMaxHp())
    {
        hp_ = getMaxHp();
        return;
    }
    hp_ = 0;
}

// void Aventureiro::setDmg(int dmg)
// {
//     if (dmg > 0 && dmg < DMG_CAP)
//     {
//         dmg_ = dmg;
//         return;
//     }
//     std::cout << "valor invalido (setDmg)\n";
//     dmg_ = 0;
// }

// GETS
std::string Aventureiro::getName() const
{
    return name_;
}

int Aventureiro::getMaxHp() const
{
    return max_hp_;
}

int Aventureiro::getHp() const
{
    return hp_;
}

int Aventureiro::getDef() const
{
    return def_;
}

int Aventureiro::getMaxDmg() const
{

    if (magicWeapons_.getQtd() > 0)
    {
        return magicWeapons_.getMaxDmg();
    }
    if (murasama_.getQtd() > 0)
    {
        return murasama_.getMaxDmg();
    }
    if (excalibur_.getQtd() > 0)
    {
        return excalibur_.getMaxDmg();
    }
    if (swords_.getQtd() > 0)
    {
        return swords_.getMaxDmg();
    }
}

int Aventureiro::getMinDmg() const
{

    if (magicWeapons_.getQtd() > 0)
    {
        return magicWeapons_.getMinDmg();
    }
    if (murasama_.getQtd() > 0)
    {
        return murasama_.getMinDmg();
    }
    if (excalibur_.getQtd() > 0)
    {
        return excalibur_.getMinDmg();
    }
    if (swords_.getQtd() > 0)
    {
        return swords_.getMinDmg();
    }
}

std::string Aventureiro::getArmaEquipada() const
{

    if (magicWeapons_.getQtd() > 0)
    {
        return magicWeapons_.getName();
    }
    if (murasama_.getQtd() > 0)
    {
        return murasama_.getName();
    }
    if (excalibur_.getQtd() > 0)
    {
        return excalibur_.getName();
    }
    if (swords_.getQtd() > 0)
    {
        return swords_.getName();
    }
    return "Nada equipado";
}

std::string Aventureiro::getArmaduraEquipada() const
{

    if (armor_.getQtd() > 0)
    {
        return armor_.getName();
    }
    return "Nada equipado";
}

void Aventureiro::equipItem(unsigned index)
{
    if (index < 0 || index >= this->inventory.size())
    {
        std::cout << "O inventario esta vazio"
                  << "\n\n";
    }
    else
    {
        Weapons *w = nullptr;
        w = dynamic_cast<Weapons *>(&this->inventory[index]);

        Armors *a = nullptr;
        a = dynamic_cast<Armors *>(&this->inventory[index]);

        // Is weapon
        if (w != nullptr)
        {
            if (typeid(*w).name() == typeid(MagicWeapons).name())
            {
                if (this->magicWeapons_.getQtd() > 0)
                    this->inventory.addItem(this->magicWeapons_);

                // check para impedir varias armas equipadas
                if (this->murasama_.getQtd() > 0)
                {
                    this->inventory.addItem(this->murasama_);
                    this->murasama_ = Murasama();
                }
                if (this->excalibur_.getQtd() > 0)
                {
                    this->inventory.addItem(this->excalibur_);
                    this->excalibur_ = Excalibur();
                }
                if (this->swords_.getQtd() > 0)
                {
                    this->inventory.addItem(this->swords_);
                    this->swords_ = Swords();
                }
                this->magicWeapons_ = *static_cast<MagicWeapons *>(&this->inventory[index]);
                this->inventory.removeItem(index);
            }
            else if (typeid(*w).name() == typeid(Murasama).name())
            {
                if (this->murasama_.getQtd() > 0)
                    this->inventory.addItem(this->murasama_);

                // check para impedir varias armas equipadas
                if (this->magicWeapons_.getQtd() > 0)
                {
                    this->inventory.addItem(this->magicWeapons_);
                    this->magicWeapons_ = MagicWeapons();
                }
                if (this->excalibur_.getQtd() > 0)
                {
                    this->inventory.addItem(this->excalibur_);
                    this->excalibur_ = Excalibur();
                }
                if (this->swords_.getQtd() > 0)
                {
                    this->inventory.addItem(this->swords_);
                    this->swords_ = Swords();
                }
                this->murasama_ = *static_cast<Murasama *>(&this->inventory[index]);
                this->inventory.removeItem(index);
            }
            else if (typeid(*w).name() == typeid(Excalibur).name())
            {
                if (this->excalibur_.getQtd() > 0)
                    this->inventory.addItem(this->excalibur_);

                // check para impedir varias armas equipadas
                if (this->magicWeapons_.getQtd() > 0)
                {
                    this->inventory.addItem(this->magicWeapons_);
                    this->magicWeapons_ = MagicWeapons();
                }
                if (this->murasama_.getQtd() > 0)
                {
                    this->inventory.addItem(this->murasama_);
                    this->murasama_ = Murasama();
                }
                if (this->swords_.getQtd() > 0)
                {
                    this->inventory.addItem(this->swords_);
                    this->swords_ = Swords();
                }
                this->excalibur_ = *static_cast<Excalibur *>(&this->inventory[index]);
                this->inventory.removeItem(index);
            }
            else if (typeid(*w).name() == typeid(Swords).name())
            {
                if (this->swords_.getQtd() > 0)
                    this->inventory.addItem(this->swords_);

                // check para impedir varias armas equipadas
                if (this->magicWeapons_.getQtd() > 0)
                {
                    this->inventory.addItem(this->magicWeapons_);
                    this->magicWeapons_ = MagicWeapons();
                }
                if (this->murasama_.getQtd() > 0)
                {
                    this->inventory.addItem(this->murasama_);
                    this->murasama_ = Murasama();
                }
                if (this->excalibur_.getQtd() > 0)
                {
                    this->inventory.addItem(this->excalibur_);
                    this->excalibur_ = Excalibur();
                }
                this->swords_ = *static_cast<Swords *>(&this->inventory[index]);
                this->inventory.removeItem(index);
            }
        }
        else if (a != nullptr)
        {
            if (this->armor_.getQtd() > 0)
                this->inventory.addItem(this->armor_);
            this->armor_ = *a;
            this->inventory.removeItem(index);
            setDef();
        }
        else
        {
            std::cout << "ERROR EQUIP ITEM, ITEM IS NOT ARMOR OR WEAPON!";
        }
    }
}

// INVENTORY FUNCTIONS
void Aventureiro::removeItem(const int index)
{
    if (index < 0 || index >= this->inventory.size())
        std::cout << "ERROR, NOT POSSIBLE TO REMOVE ITEM, removeItem Character"
                  << "\n\n";
    else
    {
        this->inventory.removeItem(index);
    }
}

const Item &Aventureiro::getItem(const int index)
{
    if (index < 0 || index >= this->inventory.size())
    {
        std::cout << "ERROR, NOT POSSIBLE TO REMOVE ITEM, getItem Character"
                  << "\n\n";
        throw("ERROR OUT OF BOUNDS, GETITEM CHARACTER");
    }

    return this->inventory[index];
}

std::string Aventureiro::getInv()
{
    std::string inv;

    if (this->inventory.size() == 0)
    {
        std::cout << "Inventory empty!" << std::endl;
        return inv;
    }

    for (size_t i = 0; i < this->inventory.size(); i++)
    {
        {
            inv += std::to_string(i) + ": " + this->inventory[i].getStats() + "\n";
        }
    }

    return inv;
}

void Aventureiro::addItem(const Item &item)
{
    this->inventory.addItem(item);
}

const int Aventureiro::getInventorySize() const
{
    return this->inventory.size();
}

// COMBAT FUNCTIONS
bool Aventureiro::isAlive() const
{
    return this->hp_ > 0;
}

int Aventureiro::takeDamage(int damage)
{
    int totalDamage = damage - getDef();
    if (totalDamage > 0)
    {
        hp_ -= totalDamage;
        return totalDamage;
    }
    if (totalDamage < 0)
    {
        return totalDamage = 0;
    }
    if (this->hp_ <= 0)
    {
        this->hp_ = 0;
        return totalDamage;
    }
}

int Aventureiro::attack()
{
    if (magicWeapons_.getQtd() > 0)
    {
        return magicWeapons_.attack();
    }
    if (murasama_.getQtd() > 0)
    {
        return murasama_.attack();
    }
    if (excalibur_.getQtd() > 0)
    {
        return excalibur_.attack();
    }
    if (swords_.getQtd() > 0)
    {
        return swords_.attack();
    }
}

// TRAVEL

void Aventureiro::travel()
{
    this->distanceTravelled++;
}
const int &Aventureiro::getDistTravel() const
{
    return this->distanceTravelled;
}
void Aventureiro::setDistTravelled(const int &distance)
{
    this->distanceTravelled = distance;
}

void Aventureiro::usarPocao()
{
    int escolha;
    int contador = 0;
    for (const auto &str : invPocoes)
        std::cout << *str << std::endl;
    std::cout << "Escolha uma pocao para usar" << std::endl;
    std::cin >> escolha;
    for (Pocoes *i : invPocoes)
    {
        if (contador == escolha)
        {
            PocaoCura *cura = dynamic_cast<PocaoCura *>(i);
            PocaoDef *def = dynamic_cast<PocaoDef *>(i);
            if (cura != 0)
            {
                this->getStats();
                this->setHp(this->getHp() + cura->getValorCura());
                delete i;
                invPocoes.erase(invPocoes.begin() + contador);
            }
            if (def != 0)
            {
                this->setDef(this->getDef() + def->getValorDef());
                delete i;
                invPocoes.erase(invPocoes.begin() + contador);
            }
            break;
        }
        PocaoCura *cura = dynamic_cast<PocaoCura *>(i);
        std::cout << cura->getValorCura() << std::endl;
        contador++;
    }
    std::cout << this->getStats() << std::endl;
}