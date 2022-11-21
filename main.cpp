#include <iostream>
#include <string>

#include "item.h"
#include "item.cpp"

#include "aventureiro.h"
#include "aventureiro.cpp"

int main(int argc, char **argv)
{
    // Creating an adventurer
    Aventureiro Daniell("Daniell", 100, 0, 3, 1);
    std::cout << "Nome: " << Daniell.getName() << std::endl;
    std::cout << "Vida: " << Daniell.getHp() << "/" << Daniell.getMaxHp() << std::endl;
    std::cout << " Armadura: " << Daniell.getArmor() << std::endl;
    std::cout << "Dano: " << Daniell.getDmg() << std::endl;
    std::cout << "Nivel: " << Daniell.getLvl() << std::endl;
    std::cout << std::endl;

    // Creating a Swor]d
    Swords WoodenSword("WoodenSword", "A stick you mistakenly assumed to be a sword", 0, 1, 5, 20, false);
    std::cout << WoodenSword.getName() << " Stats" << std::endl;
    std::cout << "Name: " << WoodenSword.getName() << std::endl;
    std::cout << "Description: " << WoodenSword.getDescription() << std::endl;
    std::cout << "Value: " << WoodenSword.getValue() << std::endl;
    std::cout << "Quantity: " << WoodenSword.getQtd() << std::endl;
    std::cout << "Damage: " << WoodenSword.getDmg() << std::endl;
    std::cout << "Durability: " << WoodenSword.getDurability() << std::endl;
    std::cout << "Auto Swings: " << WoodenSword.getAutoSwing() << " dmg" << std::endl;
    WoodenSword.TripleSwingAttack();

    std::cout << std::endl;

    // Equipping the weapon
    Daniell.setEquipWeapon(WoodenSword);
    std::cout << "Nome: " << Daniell.getName() << std::endl;
    std::cout << "Vida: " << Daniell.getHp() << "/" << Daniell.getMaxHp() << std::endl;
    std::cout << " Armadura: " << Daniell.getArmor() << std::endl;
    std::cout << "Dano: " << Daniell.getDmg() << std::endl;
    std::cout << "Nivel: " << Daniell.getLvl() << std::endl;
    std::cout << std::endl;

    return 0;
}