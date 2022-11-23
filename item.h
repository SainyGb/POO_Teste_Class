#ifndef ITEM_H__
#define ITEM_H__

#include <iostream>
#include <string>

class Item
{
    friend std::ostream &operator<<(std::ostream &, const Item &);

public:
    Item();
    Item(const std::string &n, const std::string &d, int value, int qtd);
    Item(const Item &cp);
    ~Item();

    // OPERATORS
    const Item &operator=(const Item &);
    bool operator==(const Item &);
    bool operator!=(const Item &);
    Item operator!();

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
    friend std::ostream &operator<<(std::ostream &, const Weapons &);

public:
    Weapons();
    Weapons(const std::string &n, const std::string &d, int value, int qtd, int dg, int dura);
    Weapons(const Item &cp, int dg, int dura);
    Weapons(const Weapons &cpW);
    ~Weapons();

    // OPERATORS
    const Weapons &operator=(const Weapons &);
    bool operator==(const Weapons &);
    bool operator!=(const Weapons &);
    Weapons operator!();

    // SETTERS
    void setDmg(int dmg);
    void setDurability(int dura);
    // GETTERS
    int getDmg() const;
    int getDurability() const;

private:
    unsigned int dmg_;
    int durability_;
    // std::string type_;

    // STAT CAPS
    static const int MAX_DMG = 99999999;
    static const int MAX_DURA = 99999999;
};

class MagicWeapons : public Weapons
{
    friend std::ostream &operator<<(std::ostream &, const MagicWeapons &);

public:
    MagicWeapons();
    MagicWeapons(const std::string &n, const std::string &d, int value, int qtd, int dg, int dura, int el, int pw);
    MagicWeapons(const Weapons &cpW, int el, int pw);
    MagicWeapons(const MagicWeapons &cpS);
    ~MagicWeapons();

    // OPERATORS
    const MagicWeapons &operator=(const MagicWeapons &);
    bool operator==(const MagicWeapons &);
    bool operator!=(const MagicWeapons &);
    MagicWeapons operator!();
    // SETTERS
    void setElement(int el);
    void setPowerLvl(int pw);
    // GETTERS
    int getElement() const;
    int getPowerLvl() const;

private:
    int element_;     // coming soon (will be usable as a modifier for the damage type)
    int power_level_; // defines the dmg multiplier (will range from 1 to 100)
};

// ----------------------------------------------------------------
class Armors : public Item
{
    friend std::ostream &operator<<(std::ostream &, const Armors &);

public:
    Armors();
    Armors(const std::string &n, const std::string &d, int value, int qtd, int arm);
    Armors(const Item &cp, int arm);
    Armors(const Armors &cpA);
    ~Armors();

    // OPERATORS
    const Armors &operator=(const Armors &);
    bool operator==(const Armors &);
    bool operator!=(const Armors &);
    Armors operator!();
    // SETTERS
    void setArmor(int arm);
    // GETTERS
    int getArmor() const;

    static const int MAX_ARMOR = 9999;

private:
    int armor_;
};

// ----------------------------------------------------------------
class Pocoes : public Weapons
{
    friend std::ostream &operator<<(std::ostream &, const Pocoes &);

public:
    Pocoes();
    Pocoes(const std::string &n, const std::string &d, int value, int qtd, int dg, int dura, int p);
    Pocoes(const Weapons &cp, int p);
    Pocoes(const Pocoes &cpP);
    ~Pocoes();

    // OPERATORS
    const Pocoes &operator=(const Pocoes &);
    bool operator==(const Pocoes &);
    bool operator!=(const Pocoes &);
    Pocoes operator!();
    // SETTERS
    void setPoder(int p);
    // GETTERS
    int getPoder() const;

    static const int MAX_PODER = 9999;

private:
    int poder_;
};
#endif