#include <iostream>
#include <string>

#include "aventureiro.h"
#include "item.h"

// TU N TEM ESCAPATORIA, SE QUISER FAZER O EQUIP DIREITO, VAI TER QUE ESTUDAR POLIMOFIRMO
// MAS SE TU DECIDIR QUE TA MTO EM CIMA DA HORA, SO REVERTER PARA O COMMIT QUE TA TUDO CERTO

Aventureiro::Aventureiro()
    : name_("noName"), max_hp_(0), hp_(max_hp_), armor_(0), /*dmg_(0),*/ lvl_(0)

{
    EquippedSwords_ = new Weapons("Rock", "Yes. That is it, a rock.", 0, 1, 1, 9999);
    swordEquipped_ = false;
    armorEquipped_ = false;
}

Aventureiro::Aventureiro(
    const std::string &nm, int mhp,
    int amr, int d, int lv)
{
    setName(nm);
    setMaxHp(mhp);
    setArmor(amr);
    // setDmg(d);
    setLvl(lv);
    EquippedSwords_ = new Weapons("Rock", "Yes. That is it, a rock.", 0, 1, 1, 9999);
    swordEquipped_ = false;
    armorEquipped_ = false;
}

Aventureiro::Aventureiro(const Aventureiro &cp)
{
    setName(cp.getName());
    setMaxHp(cp.getMaxHp());
    setArmor(cp.getArmor());
    // setDmg(cp.getDmg());
    setLvl(cp.getLvl());
    EquippedSwords_ = new Weapons("Rock", "Yes. That is it, a rock.", 0, 1, 1, 9999);
    swordEquipped_ = false;
    armorEquipped_ = false;
}

Aventureiro::~Aventureiro()
{
    delete EquippedSwords_;
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

void Aventureiro::setArmor(int armor)
{
    if (armor >= 0 && armor < ARMOR_CAP)
    {
        armor_ = armor;
        return;
    }

    std::cout << "valor invalido (setArmor)\n";
    armor_ = 0;
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

int Aventureiro::getArmor() const
{
    return armor_;
}

// int Aventureiro::getDmg() const
// {
//     return dmg_;
// }

int Aventureiro::getLvl() const
{
    return lvl_;
}

void Aventureiro::setEquipWeapon(const Weapons &weapon)
{
    if (!swordEquipped_)
    {
        delete EquippedSwords_;
        EquippedSwords_ = new Weapons(weapon);
        // setDmg(EquippedSwords_->getDmg());
        swordEquipped_ = true;
        std::cout << "Arma equipada com sucesso!" << std::endl;
        return;
    }
    std::cout << "Já tem uma arma equipada" << std::endl;
    return;
}

void Aventureiro::setEquipArmor(const Armors &armor)
{
    if (!armorEquipped_)
    {
        setArmor(armor.getArmor());
        armorEquipped_ = true;
        std::cout << "Armadura equipada com sucesso!" << std::endl;
        return;
    }
    std::cout << "Já tem uma armadura equipada" << std::endl;
    return;
}

void Aventureiro::setUnequipWeapon()
{
    if (swordEquipped_)
    {
        delete EquippedSwords_;
        EquippedSwords_ = new Weapons("Hand", "Yes. That is it, your hand.", 0, 1, 1, 99999999);
        swordEquipped_ = false;
        std::cout << "Arma desequipada" << std::endl;
        return;
    }
    std::cout << "Nao tem nada equipado" << std::endl;
    return;
}

void Aventureiro::setUnequipArmor()
{
    if (armorEquipped_)
    {
        armorEquipped_ = false;
        setArmor(0);
        std::cout << "Arma desequipada" << std::endl;
        return;
    }
    std::cout << "Nao tem nada equipado" << std::endl;
    return;
}