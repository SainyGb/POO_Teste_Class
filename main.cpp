#include <iostream>
#include <string>

#include "item.h"
#include "item.cpp"

#include "aventureiro.h"
#include "aventureiro.cpp"

int main(int argc, char **argv)
{
    // Creating an Item object
    int value = 0;
    int qtd = 1;
    Item baseItem("Stick", "What powers does it hold?", value, qtd);
    std::cout << baseItem << std::endl;
    std::cout << std::endl;

    // Creating a Base item for an Armor
    int arm_value = 50;
    int arm_qtd = 1;
    Item armorBaseItem("Armor", "Just a simple plate armor", arm_value, arm_qtd);
    std::cout << armorBaseItem << std::endl;
    // Creating Armor object
    int def = 20;
    Armors armor(armorBaseItem, def);
    std::cout << armor << std::endl;
    std::cout << std::endl;

    // Creating a Weapon
    int dmg = 5;
    int durability = 20;
    Weapons baseWeapon(baseItem, dmg, durability);
    std::cout << baseWeapon << std::endl;
    std::cout << std::endl;

    // Creating a MagicWeapon
    int element = 0;
    int power_level = 1;
    MagicWeapons Stick(baseWeapon, element, power_level);
    std::cout << Stick << std::endl;
    std::cout << std::endl;

    // Creating a Weapon Potion
    int pt_value = 250;
    int pt_qtd = 1;
    int nat_dmg = 75;
    int pt_durability = 3;
    int power = 35;
    Pocoes poisonPotion("Arachasae", "A poison of a misterious spider of a misterious place", pt_value, pt_qtd, nat_dmg, pt_durability, power);
    std::cout << poisonPotion << std::endl;
    std::cout << std::endl;

    // Creating a Adverturer to use the weapon
    Aventureiro Daniell("Daniell", 100,
                        0, 1, 1);
    std::cout << "Nome: " << Daniell.getName() << std::endl;
    std::cout << "Vida: " << Daniell.getHp() << "/" << Daniell.getMaxHp() << std::endl;
    std::cout << "Armadura: " << Daniell.getArmor() << std::endl;
    std::cout << "Dano: " << Daniell.EquippedSwords_->getDmg() << std::endl;
    std::cout << "Nivel: " << Daniell.getLvl() << std::endl;
    std::cout << std::endl;

    // Equipping the weapon
    std::cout << "Equipando equipamento" << std::endl;
    Daniell.setEquipWeapon(Stick);
    Daniell.setEquipArmor(armor);
    std::cout
        << "Nome: " << Daniell.getName() << std::endl;
    std::cout << "Vida: " << Daniell.getHp() << "/" << Daniell.getMaxHp() << std::endl;
    std::cout << "Armadura: " << Daniell.getArmor() << std::endl;
    std::cout << "Dano: " << Daniell.EquippedSwords_->getDmg() << std::endl;
    std::cout << "Nivel: " << Daniell.getLvl() << std::endl;
    std::cout << std::endl;

    return 0;
}