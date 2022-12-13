#ifndef aventureiro_H_
#define aventureiro_H_

#include <iostream>
#include <string>

#include "item.h"
#include "inventario.h"
#include "weapons.h"

class Aventureiro
{
    friend std::ostream &operator<<(std::ostream &, const Aventureiro &);

public:
    Aventureiro();
    Aventureiro(const std::string &nm, int mhp,
                int arm, int d, int lv);
    Aventureiro(const Aventureiro &);
    ~Aventureiro();

    // SETTERS
    void setName(const std::string &name);
    void setMaxHp(int hp);
    void setDef(int arm);
    // void setDmg(int dmg);
    void setLvl(int lvl);

    // GETTERS
    std::string getName() const;
    int getMaxHp() const;
    int getHp() const;
    int getDef() const;
    // int getDmg() const;
    int getLvl() const;

    // Combat tags
    bool isAlive() const;

    // INVETORY FUNCTIONS
    void addItem(const Item &item) { this->inventory.addItem(item); }
    void removeItem(const int index);
    const Item &getItem(const int index);
    inline const int getInventorySize() const { return this->inventory.size(); }
    std::string getInv();
    // Equip and unequip items
    void equipItem(unsigned index);

    // equip items
    MagicWeapons magicWeapons_;
    Armors armor_;
    Murasama marasama;
    Excalibur excalibur;

    // STATS CAPS
    static const int MAX_NAME_LENGTH = 16;
    static const int HP_CAP = 9999999;
    static const int DEF_CAP = 9999999;
    // static const int DMG_CAP = 9999999;
    static const int LVL_CAP = 1001;

private:
    std::string name_;
    int max_hp_;
    int hp_;
    int def_;
    // int dmg_;
    int lvl_;

    // Inventory
    Inventory inventory;

    // Items and Weapons
    bool armorEquipped_;
    bool swordEquipped_;
    bool magicSwordEquipped_;
};

#endif