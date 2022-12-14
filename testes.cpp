#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>

#include "aventureiro.h"
#include "aventureiro.cpp"

#include "inventario.h"
#include "inventario.cpp"

#include "item.h"
#include "item.cpp"

#include "weapons.h"
#include "weapons.cpp"
// #include "pocoes.cpp"

int main(int argc, char **argv)
{
    // Creating an Item object
    int value = 0;
    int qtd = 1;
    // Item baseItem("Stick", "What powers does it hold?", value, qtd);
    // std::cout << baseItem << std::endl;
    // std::cout << std::endl;

    // Creating a Base item for an Armor
    int arm_value = 50;
    int arm_qtd = 1;
    // Item armorBaseItem("Armor", "Just a simple plate armor", arm_value, arm_qtd);
    // std::cout << armorBaseItem << std::endl;

    // Creating Armor object
    int def = 20;
    Armors armor("Armor", "Just a simple plate armor", arm_value, arm_qtd, def, 100);
    Armors armor2("Guatelamala", "use como escudo humano", 24, arm_qtd, 21, 100);
    // std::cout << armor << std::endl;
    // std::cout << std::endl;

    // Creating a Weapon
    int minDmg = 5;
    int maxDmg = 6;
    int durability = 20;
    // Weapons baseWeapon("Stick", "What powers does it hold?", value, qtd, maxDmg, minDmg, durability);
    //  std::cout << baseWeapon << std::endl;
    //  std::cout << std::endl;

    // Creating a MagicWeapon
    int element = 0;
    int power_level = 1;
    MagicWeapons Stick("Stick", "What powers does it hold?", 10, 1, 6, 5, 20, 0, 1);
    // Murasama mura("Murasama", "What powers does it hold?", 1000, 1, 150, 120, 100, 10, false, 0);

    PocaoCura("Pocao de Cura", "Cura voce", 100, 1, 1, 0, 10);
    std::cout << Stick << std::endl;
    std::cout << std::endl;

    int pt_value = 250;
    int pt_qtd = 1;
    int min_nat_dmg = 75;
    int max_nat_dmg = 75;
    int pt_durability = 3;
    int power = 35;

    Aventureiro Daniell("Daniell", 100,
                        0, 1, 1);
    std::cout << "Nome: " << Daniell.getName() << std::endl;
    std::cout << "Vida: " << Daniell.getHp() << "/" << Daniell.getMaxHp() << std::endl;
    std::cout << "Armadura: " << Daniell.armor_.getArmor() << std::endl;
    std::cout << "Dano: " << Daniell.magicWeapons_.getMinDmg() << " - " << Daniell.magicWeapons_.getMaxDmg() << std::endl;
    std::cout << std::endl;

    std::cout << "Adicionando coisas no inventario: " << std::endl;
    std::cout << Daniell.getInventorySize() << std::endl;
    Daniell.addItem(Stick);
    Daniell.addItem(armor);
    Daniell.addItem(armor2);
    // Daniell.addItem(mura);

    std::cout << Daniell.getInv();

    // Equipping the weapon
    std::cout << "Equipando equipamento" << std::endl;
    Daniell.equipItem(0);
    Daniell.equipItem(0);

    std::cout << Daniell.getInv();

    std::cout << Daniell.getStats();
}