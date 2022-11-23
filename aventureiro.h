#ifndef aventureiro_H_
#define aventureiro_H_

#include <iostream>
#include <string>

#include "item.h"

class Aventureiro
{
public:
    Aventureiro();
    Aventureiro(const std::string &nm, int mhp,
                int arm, int d, int lv);
    Aventureiro(const Aventureiro &);
    ~Aventureiro();

    // SETTERS
    void setName(const std::string &name);
    void setMaxHp(int hp);
    void setArmor(int arm);
    // void setDmg(int dmg);
    void setLvl(int lvl);

    // Equip and unequip items
    void setEquipArmor(const Armors &a);
    void setEquipWeapon(const Weapons &w);

    void setUnequipArmor();
    void setUnequipWeapon();

    // GETTERS
    std::string getName() const;
    int getMaxHp() const;
    int getArmor() const;
    // int getDmg() const;
    int getLvl() const;
    int getHp() const;

    // Attack
    void attack();

    // equip items
    Weapons *EquippedSwords_;
    MagicWeapons *EquippedMagicSwords_;

    // STATS CAPS
    static const int MAX_NAME_LENGTH = 16;
    static const int HP_CAP = 9999999;
    static const int ARMOR_CAP = 9999999;
    // static const int DMG_CAP = 9999999;
    static const int LVL_CAP = 1001;

private:
    std::string name_;
    int max_hp_;
    int hp_;
    int armor_;
    // int dmg_;
    int lvl_;

    // Items and Weapons
    bool armorEquipped_;
    bool swordEquipped_;
    bool magicSwordEquipped_;
};

#endif