#include <iostream>
#include <string>

#include "aventureiro.h"
#include "item.h"
#include "weapons.h"

// TU N TEM ESCAPATORIA, SE QUISER FAZER O EQUIP DIREITO, VAI TER QUE ESTUDAR POLIMOFIRMO
// MAS SE TU DECIDIR QUE TA MTO EM CIMA DA HORA, SO REVERTER PARA O COMMIT QUE TA TUDO CERTO

Aventureiro::Aventureiro()
    : name_("noName"), max_hp_(0), hp_(max_hp_), def_(0), /*dmg_(0),*/ lvl_(0)

{
    // EquippedSwords_ = new Weapons("Rock", "Yes. That is it, a rock.", 0, 1, 1, 9999);
    swordEquipped_ = false;
    armorEquipped_ = false;
}

Aventureiro::Aventureiro(
    const std::string &nm, int mhp,
    int amr, int d, int lv)
{
    setName(nm);
    setMaxHp(mhp);
    setDef(amr);
    // setDmg(d);
    setLvl(lv);
    // EquippedSwords_ = new Weapons("Rock", "Yes. That is it, a rock.", 0, 1, 1, 9999);
    swordEquipped_ = false;
    armorEquipped_ = false;
}

Aventureiro::Aventureiro(const Aventureiro &cp)
{
    setName(cp.getName());
    setMaxHp(cp.getMaxHp());
    setDef(cp.getDef());
    // setDmg(cp.getDmg());
    setLvl(cp.getLvl());
    // EquippedSwords_ = new Weapons("Rock", "Yes. That is it, a rock.", 0, 1, 1, 9999);
    swordEquipped_ = false;
    armorEquipped_ = false;
}

Aventureiro::~Aventureiro()
{
}

// OPERATORS
std::ostream &operator<<(std::ostream &out, const Aventureiro &aventureiro)
{
    out
        << "Nome: " << aventureiro.getName() << std::endl;
    out << "Vida: " << aventureiro.getHp() << "/" << aventureiro.getMaxHp() << std::endl;
    out << "Armadura: " << aventureiro.armor_.getArmor() << std::endl;
    out << "Dano: " << aventureiro.magicWeapons_.getMinDmg() << " - " << aventureiro.magicWeapons_.getMaxDmg() << std::endl;
    out << "Nivel: " << aventureiro.getLvl() << std::endl;
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
    if (hp > 0 && hp < HP_CAP)
    {
        max_hp_ = hp;
        hp_ = max_hp_;
        return;
    }

    std::cout << "valor invalido (setMaxHp)\n";
    max_hp_ = 0;
    hp_ = max_hp_;
}

void Aventureiro::setDef(int armor)
{
    if (armor >= 0 && armor < DEF_CAP)
    {
        def_ = armor;
        return;
    }

    std::cout << "valor invalido (setDef)\n";
    def_ = 0;
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

void Aventureiro::setLvl(int lvl)
{
    if (lvl > 0 && lvl < LVL_CAP)
    {
        lvl_ = lvl;
        return;
    }
    std::cout << "valor invalido (setLvl)\n";
    lvl_ = 0;
}

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

// int Aventureiro::getDmg() const
// {
//     return dmg_;
// }

int Aventureiro::getLvl() const
{
    return lvl_;
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
            MagicWeapons *mw = nullptr;
            mw = dynamic_cast<MagicWeapons *>(&this->inventory[index]);

            if (mw != nullptr)
            {
                if (this->magicWeapons_.getQtd() > 0)
                    this->inventory.addItem(this->magicWeapons_);
                this->magicWeapons_ = *mw;
                this->inventory.removeItem(index);
            }

            // else if (this->weapons_.getQtd() > 0)
            //     this->inventory.addItem(this->weapons_);
            // this->weapons_ = *w;
            // this->inventory.removeItem(index);
        }
        else if (a != nullptr)
        {
            if (this->armor_.getQtd() > 0)
                this->inventory.addItem(this->armor_);
            this->armor_ = *a;
            this->inventory.removeItem(index);
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

// COMBAT FUNCTIONS
bool Aventureiro::isAlive() const
{
    return this->hp_ > 0;
}