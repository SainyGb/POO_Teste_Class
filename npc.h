#ifndef NPC_H_
#define NPC_H_

#include <iostream>
#include <string>

class Npc
{
public:
    Npc();
    Npc(const std::string &name, int lvl, int mhp, int arm, int dmg);
    Npc(const Npc &cp);
    ~Npc();

    // SETTERS
    void setName(const std::string &name);
    void setLvl(int lvl);
    void setMaxHp(int hp);
    void setArmor(int arm);
    void setDmg(int dmg);

    // GETTERS
    std::string getName() const;
    int getLvl() const;
    int getMaxHp() const;
    int getArmor() const;
    int getDmg() const;

    static const int MAX_NAME_LENGTH = 16;
    static const int LVL_CAP = 1001;
    static const int HP_CAP = 9999999;
    static const int ARMOR_CAP = 9999999;
    static const int DMG_CAP = 9999999;

private:
    std::string name_;
    int lvl_;
    int hp_;
    int max_hp_;
    int armor_;
    int dmg_;
};

#endif