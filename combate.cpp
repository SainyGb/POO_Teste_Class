#include "combate.h"
#include "weapons.h"
// #include "pocoes.h"
#include "item.h"
#include "aventureiro.h"
#include "Npc.h"
#include "vector"

int Combate::nrOfEvents = 1;
std::vector<Pocoes *> invPocoes;

using namespace std;
;

Combate::Combate()
{
}

Combate::~Combate()
{
}

void Combate::generateEvent(Aventureiro &character, vector<Npc> &enemies)
{
     int i = rand() % Combate::nrOfEvents;

     switch (i)
     {
     case 0:
          // Enemy encounter
          this->enemyEncouter(character, enemies);
          break;
     default:
          break;
     }
}

void Combate::enemyEncouter(Aventureiro &character, std::vector<Npc> &enemies)
{

     bool playerTurn = false;
     int choice = 0;

     // Coin toss for turn
     int coinToss = rand() % 2 + 1;

     if (coinToss == 1)
          playerTurn = true;
     else
          playerTurn = false;

     // End conditions
     bool escape = false;
     bool playerDefeated = false;
     bool enemiesDefeated = false;

     // Enemies
     int nrOfEnemies = rand() % 5 + 1;

     for (size_t i = 0; i < nrOfEnemies; i++)
     {
          enemies.push_back(Npc());
     }

     // Battle variables
     int damage = 0;
     int playerTotal = 0;
     int enemyTotal = 0;
     int combatTotal = 0;
     int combatRollPlayer = 0;
     int combatRollEnemy = 0;

     while (!escape && !playerDefeated && !enemiesDefeated)
     {
          if (playerTurn && !playerDefeated)
          {
               // Menu
               // system("CLS");

               cout << "= PLAYER TURN ="
                    << "\n\n";
               cout << "Continue..."
                    << "\n\n";
               cin.get();
               system("CLS");

               cout << "= BATTLE MENU ="
                    << "\n\n";
               cout << "HP: " << character.getHp() << " / " << character.getMaxHp() << "\n\n";

               cout << "0: Escape"
                    << "\n";
               cout << "1: Attack"
                    << "\n";
               cout << "2: Defend"
                    << "\n";
               cout << "3: Use Item"
                    << "\n";
               cout << "\n";

               cout << "Choice: ";

               cin >> choice;

               while (cin.fail() || choice > 3 || choice < 0)
               {
                    system("CLS");

                    cout << "Faulty input!"
                         << "\n";
                    cin.clear();
                    cin.ignore(100, '\n');

                    cout << "= BATTLE MENU ="
                         << "\n\n";

                    cout << "0: Escape"
                         << "\n";
                    cout << "1: Attack"
                         << "\n";
                    cout << "2: Defend"
                         << "\n";
                    cout << "3: Use Item"
                         << "\n";
                    cout << "\n";

                    cout << "Choice: ";
                    cin >> choice;
               }

               cin.ignore(100, '\n');
               cout << "\n";

               // Moves
               switch (choice)
               {
               case 0: // ESCAPE
                    int canEscape;
                    canEscape = rand() % 100 + 1;
                    if (canEscape >= 60)
                    {
                         escape = true;
                         break;
                    }
                    escape = false;
                    break;

               case 1: // ATTACK

                    // Select enemy
                    if (character.swords_.getQtd() > 0)
                    {
                         cout << "0: Attack"
                              << "\n";
                         cout << "1: Double Slice Attack"
                              << "\n";
                         cout << "\n";
                         cout << "Choice: ";

                         cin >> choice;

                         while (cin.fail() || choice > 1 || choice < 0)
                         {
                              system("CLS");

                              cout << "Faulty input!"
                                   << "\n";
                              cin.clear();
                              cin.ignore(100, '\n');

                              cout << "0: Attack"
                                   << "\n";
                              cout << "1: Double Slice Attack"
                                   << "\n";
                              cout << "\n";

                              cout << "Choice: ";
                              cin >> choice;
                         }
                         if (choice == 0)
                              damage = character.attack();
                         else
                              damage = character.swords_.doubleSLice();
                    }
                    if (character.magicWeapons_.getQtd() > 0)
                    {
                         cout << "0: Attack"
                              << "\n";
                         cout << "1: Magic Missiles"
                              << "\n";
                         cout << "\n";
                         cout << "Choice: ";

                         cin >> choice;

                         while (cin.fail() || choice > 1 || choice < 0)
                         {
                              system("CLS");

                              cout << "Faulty input!"
                                   << "\n";
                              cin.clear();
                              cin.ignore(100, '\n');

                              cout << "0: Attack"
                                   << "\n";
                              cout << "1: Magic Missiles"
                                   << "\n";
                              cout << "\n";

                              cout << "Choice: ";
                              cin >> choice;
                         }
                         if (choice == 0)
                              damage = character.attack();
                         else
                              damage = character.magicWeapons_.magicMissiles();
                    }
                    if (character.murasama_.getQtd() > 0)
                    {
                         cout << "0: Attack"
                              << "\n";
                         cout << "1: Lingchi"
                              << "\n";
                         cout << "\n";
                         cout << "Choice: ";

                         cin >> choice;

                         while (cin.fail() || choice > 1 || choice < 0)
                         {
                              system("CLS");

                              cout << "Faulty input!"
                                   << "\n";
                              cin.clear();
                              cin.ignore(100, '\n');

                              cout << "0: Attack"
                                   << "\n";
                              cout << "1: Lingchi"
                                   << "\n";
                              cout << "\n";

                              cout << "Choice: ";
                              cin >> choice;
                         }
                         if (choice == 0)
                              damage = character.attack();
                         else
                              damage = character.murasama_.lingchi();
                    }
                    if (character.excalibur_.getQtd() > 0)
                    {
                         cout << "0: Attack"
                              << "\n";
                         cout << "1: EXCALIBUR: ENERGY BEAM!"
                              << "\n";
                         cout << "\n";
                         cout << "Choice: ";

                         cin >> choice;

                         while (cin.fail() || choice > 1 || choice < 0)
                         {
                              system("CLS");

                              cout << "Faulty input!"
                                   << "\n";
                              cin.clear();
                              cin.ignore(100, '\n');

                              cout << "0: Attack"
                                   << "\n";
                              cout << "1: EXCALIBUR: ENERGY BEAM!"
                                   << "\n";
                              cout << "\n";

                              cout << "Choice: ";
                              cin >> choice;
                         }
                         if (choice == 0)
                              damage = character.attack();
                         else
                              damage = character.excalibur_.excalibur();
                    }

                    cout << "Select enemy: "
                         << "\n\n";

                    for (size_t i = 0; i < enemies.size(); i++)
                    {
                         cout << i << ": "
                              << "Nome: " << enemies[i].getName() << " - "
                              << "HP: " << enemies[i].getHp() << "/" << enemies[i].getMaxHp() << " - "
                              << "Defence: " << enemies[i].getArmor() << " - "
                              << "Damage: " << enemies[i].getMinDmg() << " - " << enemies[i].getMaxDmg() << "\n";
                    }

                    cout << "\n";
                    cout << "Choice: ";

                    cin >> choice;

                    while (cin.fail() || choice >= enemies.size() || choice < 0)
                    {
                         cout << "Faulty input!"
                              << "\n";
                         cin.clear();
                         cin.ignore(100, '\n');

                         cout << "Select enemy: "
                              << "\n\n";
                         cout << "Choice: ";
                         cin >> choice;
                    }

                    cin.ignore(100, '\n');
                    cout << "\n";

                    cout << "HIT! "
                         << "\n\n";

                    // damage = character.attack();
                    enemies[choice].takeDamage(damage);

                    cout << "Damage: " << enemies[choice].takeDamage(damage) << "!"
                         << "\n\n";

                    if (!enemies[choice].isAlive())
                    {
                         cout << "ENEMY DEFEATED!"
                              << "\n\n";

                         enemies.erase(enemies.begin() + choice);
                    }

                    break;

               case 2: // USE ABILITY

                    break;

               case 3: // ITEM
                    character.usarPocao();

                    break;

               default:
                    break;
               }

               // End turn
               playerTurn = false;
          }
          else if (!playerTurn && !playerDefeated && !escape && !enemiesDefeated)
          {
               cout << "= ENEMY TURN ="
                    << "\n";

               cout << "Continue..."
                    << "\n\n";
               cin.get();
               system("CLS");

               // Enemy attack
               for (size_t i = 0; i < enemies.size(); i++)
               {
                    cout << "Continue..."
                         << "\n\n";
                    cin.get();
                    system("CLS");

                    cout << "Enemy: " << i << "\n\n";

                    cout << "HIT! "
                         << "\n\n";

                    damage = enemies[i].attack();
                    character.takeDamage(damage);

                    cout << "Damage: " << character.takeDamage(damage) << "!"
                         << "\n";
                    cout << "HP: " << character.getHp() << " / " << character.getMaxHp() << "\n\n";

                    if (!character.isAlive())
                    {
                         cout << "YOU ARE DEFEATED!"
                              << "\n\n";
                         playerDefeated = true;
                    }
               }

               // End turn
               playerTurn = true;
          }

          // Conditions
          if (!character.isAlive())
          {
               playerDefeated = true;
          }
          else if (enemies.size() <= 0)
          {
               enemiesDefeated = true;
          }
     }
}
