#ifndef aventureiro_H_
#define aventureiro_H_

#include <iostream>
#include <string>
#include <vector>

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

    // Inicializar o jogo
    void inicializar(std::string n);

    // SETTERS
    void setName(const std::string &name);
    void setMaxHp(int hp);
    void setHp(int hp);
    void setDef(int arm = 0);

    // GETTERS
    std::string getName() const;
    int getMaxHp() const;
    int getHp() const;
    int getDef() const;
    int getMaxDmg() const;
    int getMinDmg() const;
    std::string getArmaEquipada() const;
    std::string getArmaduraEquipada() const;
    std::string getStats() const;

    // Combat tags
    int takeDamage(int d);
    bool isAlive() const;
    int attack();
    void usarPocao();

    void travel();
    const int &getDistTravel() const;
    void setDistTravelled(const int &distance);

    // INVETORY FUNCTIONS
    void addItem(const Item &item);
    void removeItem(const int index);
    const Item &getItem(const int index);
    const int getInventorySize() const;
    std::string getInv();
    // Equip and unequip items
    void equipItem(unsigned index);

    // equip items
    MagicWeapons magicWeapons_;
    Armors armor_;
    Murasama murasama_;
    Excalibur excalibur_;
    Swords swords_;

    // STATS CAPS
    static const int MAX_NAME_LENGTH = 16;
    static const int HP_CAP = 9999999;
    static const int DEF_CAP = 9999999;

private:
    std::string name_;
    int max_hp_;
    int hp_;
    int def_;
    // int dmg_;
    int lvl_;
    int distanceTravelled;
    std::vector<Pocoes *> invPocoes;

    // Inventory
    Inventory inventory;
};

#endif