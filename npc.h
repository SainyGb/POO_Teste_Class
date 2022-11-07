#ifndef NPC_H_
#define NPC_H_

#include <iostream>
#include <string>

class Npc
{
public:
    Npc();
    Npc(const std::string &name = "noName", int lvl = 0, int mhp = 0, int arm = 0, int dmg = 0);
    Npc(const Npc &cp);
    ~Npc();

    // SETTERS AND GETTERS
    void setName(const std::string &name);
    void setLvl(int lvl);
    void setMaxHp(int hp);
    void setArmor(int arm);
    void setDmg(int dmg);
    std::string getName() const;
    int getLvl() const;
    int getMaxHp() const;
    int getArmor() const;
    int getDmg() const;

private:
    std::string name_;
    int lvl_;
    int hp_;
    int max_hp_;
    int armor_;
    int dmg_;
};

#endif