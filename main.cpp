#include "gerenciamento.h"
#include "gerenciamento.cpp"

int main()
{
    // srand(time(NULL));

    Gerenciador game;
    game.initGame();

    while (game.getPlaying())
    {
        game.mainMenu();
    }

    return 0;
}
