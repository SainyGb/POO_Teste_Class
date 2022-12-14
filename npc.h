#ifndef NPC_H_
#define NPC_H_

#include <iostream>
#include <string>

class Npc
{
public:
    Npc();
    Npc(const std::string &name, int mhp, int arm, int mxdmg, int mdmg);
    Npc(const Npc &cp);
    ~Npc();

    // SETTERS
    void setName(const std::string &name);
    void setMaxHp(int hp);
    void setArmor(int arm);
    void setDmg(int dmg);
    void setMinDmg(int dmg);
    void setMaxDmg(int dmg);

    // GETTERS
    std::string getName() const;
    int getMaxHp() const;
    int getHp() const;
    int getArmor() const;
    int getMinDmg() const;
    int getMaxDmg() const;

    // COMBAT TAGS
    int takeDamage(int d);
    bool isAlive() const;
    int attack() const;

    static const int MAX_NAME_LENGTH = 30;
    static const int LVL_CAP = 1001;
    static const int HP_CAP = 9999999;
    static const int ARMOR_CAP = 9999999;
    static const int DMG_CAP = 9999999;

private:
    std::string name_;
    int hp_;
    int max_hp_;
    int armor_;
    unsigned int minDmg_;
    unsigned int maxDmg_;
};

#endif