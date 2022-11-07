#ifndef aventureiro_H_
#define aventureiro _H_

#include <iostream>
#include <string>

class Aventureiro
{
public:
    Aventureiro();
    Aventureiro(const std::string &nm = "noName", int mhp = 0,
                int arm = 0, int d = 0, int lv = 0);
    Aventureiro(const Aventureiro &);
    ~Aventureiro();

    // SETTERS
    void setName(const std::string &name);
    void setMaxHp(int hp);
    void setArmor(int arm);
    void setDmg(int dmg);
    void setLvl(int lvl);

    // GETTERS
    std::string getName() const;
    int getMaxHp() const;
    int getArmor() const;
    int getDmg() const;
    int getLvl() const;

private:
    std::string name_;
    int max_hp_;
    int hp_;
    int armor_;
    int dmg_;
    int lvl_;
};

#endif