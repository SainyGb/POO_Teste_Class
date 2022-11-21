#ifndef ITEM_H__
#define ITEM_H__

#include <iostream>
#include <string>

class Item
{
public:
    Item();
    Item(const std::string &n, const std::string &d, int value, int qtd);
    Item(const Item &cp);
    ~Item();

    // SETTERS
    void setName(const std::string &name);
    void setDescription(const std::string &description);
    void setValue(int value);
    void setQtd(int qtd);

    // GETTERS
    std::string getName() const;
    std::string getDescription() const;
    int getValue() const;
    int getQtd() const;

private:
    std::string name_;
    std::string description_;
    int value_;
    int qtd_;

    // STAT CAPS
    static const int MAX_NAME_LENGTH = 16;
    static const int MAX_DESC_LENGTH = 500;
    static const int MAX_VALUE = 9999999;
    static const int MAX_QTD = 999;
};

// ----------------------------------------------------------------
class Weapons : public Item
{
public:
    Weapons();
    Weapons(const std::string &n, const std::string &d, int value, int qtd, int dg, int dura);
    Weapons(const Item &cp, int dg, int dura);
    Weapons(const Weapons &cpW);
    ~Weapons();

    // SETTERS
    void setDmg(int dmg);
    void setDurability(int dura);
    // GETTERS
    int getDmg() const;
    int getDurability() const;

private:
    unsigned int dmg_;
    int durability_;

    // STAT CAPS
    static const int MAX_DMG = 99999999;
    static const int MAX_DURA = 99999999;
};

class Swords : public Weapons
{
public:
    Swords();
    Swords(const std::string &n, const std::string &d, int value, int qtd, int dg, int dura, bool ast);
    Swords(const Weapons &cpW, bool ast);
    Swords(const Swords &cpS);
    ~Swords();

    // SETTERS
    void setAutoSwing(bool ast);
    // GETTERS
    bool getAutoSwing() const;

    // Special properties
    void TripleSwingAttack() const;

private:
    bool autoSwingAttack_;
};

// ----------------------------------------------------------------
// class Armors : public Item
// {
// public:
//     Armors :

#endif