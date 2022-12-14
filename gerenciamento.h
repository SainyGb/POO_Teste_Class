#ifndef GERENCIAMENTO_H
#define GERENCIAMENTO_H

#include <fstream>
#include <sstream>
#include <vector>

#include "combate.h"
#include "combate.cpp"

#include "aventureiro.h"
#include "aventureiro.cpp"

#include "inventario.h"
#include "inventario.cpp"

#include "item.h"
#include "item.cpp"

#include "weapons.h"
#include "weapons.cpp"

#include "pocoes.h"

#include "npc.h"
#include "npc.cpp"

using namespace std;

class Gerenciador
{
private:
    int choice;
    bool playing;

    // Character related
    int activeCharacter;
    std::vector<Aventureiro> characters;
    std::string fileName;

    // Enemies
    vector<Npc> enemies;

public:
    Gerenciador();
    virtual ~Gerenciador();

    // Operators

    // Functions
    void initGame();
    void mainMenu();
    void createNewCharacter();
    void characterMenu();
    void selectCharacter();
    void travel();

    // MENU FUNCTIONS
    const std::string menu_title(const std::string title);
    const std::string menu_divider(const unsigned amount = 30, const char symbol = '-');
    const std::string menu_item(const unsigned index, const std::string text);

    // Accessors
    inline bool getPlaying() const { return this->playing; }

    // Modifiers
};

#endif