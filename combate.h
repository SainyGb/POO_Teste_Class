#ifndef COMBATE_H
#define COMBATE_H

#include <vector>
#include "aventureiro.h"
#include "npc.h"

class Combate
{
private:
public:
    Combate();
    virtual ~Combate();
    void generateEvent(Aventureiro &character, std::vector<Npc> &enemies);

    // Events
    void enemyEncouter(Aventureiro &character, std::vector<Npc> &enemies);

    // statics
    static int nrOfEvents;
};

#endif //