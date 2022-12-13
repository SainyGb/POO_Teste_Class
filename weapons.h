#ifndef WEAPONS_H_
#define WEAPONS_H_

#include <iostream>
#include <string>

#include "item.h"

class Weapons : public Item
{
    friend std::ostream &operator<<(std::ostream &, const Weapons &);

public:
    Weapons();
    Weapons(const std::string &n, const std::string &d, int value, int qtd, int mxdg, int mdg, int dura);
    Weapons(const Item &cp, int mxdg, int mdg, int dura);
    Weapons(const Weapons &cpW);
    virtual ~Weapons();

    // PURE VIRTUAL FUNCTIONS
    /**
     * Utilizada para copiar objetos de maneira mais pratica no inventario
     */
    virtual Weapons *clone() const = 0;
    virtual std::string getStats() const = 0;
    virtual int attack() = 0;

    // OPERATORS
    // VOLTAR DPS
    const Weapons &
    operator=(const Weapons &);
    bool operator==(const Weapons &);
    bool operator!=(const Weapons &);
    // Weapons operator!();

    // SETTERS
    void setMinDmg(int dmg);
    void setMaxDmg(int dmg);
    void setDurability(int dura);
    // GETTERS
    int getMinDmg() const;
    int getMaxDmg() const;
    int getDurability() const;

    // FUNCTIONS
    void durabilityDmg();
    void breakWeapons();

private:
    unsigned int minDmg_;
    unsigned int maxDmg_;
    int durability_;
    // std::string type_;

    // STAT CAPS
    static const int MAX_DMG = 99999999;
    static const int MAX_DURA = 99999999;
};

//----------------------------------------------------------------

class MagicWeapons : public Weapons
{
    friend std::ostream &operator<<(std::ostream &, const MagicWeapons &);

public:
    MagicWeapons();
    MagicWeapons(const std::string &n, const std::string &d, int value, int qtd, int mxdg, int mdg, int dura, int el, int pw);
    MagicWeapons(const Weapons &cpW, int el, int pw);
    MagicWeapons(const MagicWeapons &cpS);
    virtual ~MagicWeapons();

    // OPERATORS
    // VER DEPOIS
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

    // VIRTUAL FUNCTIONS
    std::string getStats() const;
    MagicWeapons *clone() const;
    int attack();

private:
    int element_;     // coming soon (will be usable as a modifier for the damage type)
    int power_level_; // defines the dmg multiplier (will range from 1 to 100)
};

class Swords : public Weapons
{
    friend std::ostream &operator<<(std::ostream &, const Swords &);

public:
    Swords();
    Swords(const std::string &n, const std::string &d, int value, int qtd, int mxdg, int mdg, int dura, int p);
    Swords(const Weapons &cp, int p);
    Swords(const Swords &cpP);
    ~Swords();

    // OPERATORS
    const Swords &operator=(const Swords &);
    bool operator==(const Swords &);
    bool operator!=(const Swords &);
    Swords operator!();
    // SETTERS
    void setPoder(int p);
    // GETTERS
    int getPoder() const;

    // FUNCTIONS
    // int useAbility() const;

    // VIRTUAL FUNCTIONS
    std::string getStats() const;
    Swords *clone() const;
    int attack();

    static const int MAX_PODER = 9999;

private:
    int poder_;
};

// ----------------------------------------------------------------

class Murasama : public Swords
{
    friend std::ostream &operator<<(std::ostream &, const Murasama &);

public:
    Murasama();
    Murasama(const std::string &n, const std::string &d, int value, int qtd, int mxdg, int mdg, int dura, int p, bool b, int r);
    Murasama(const Murasama &);
    ~Murasama();

    // OPERATORS
    const Murasama &operator=(const Murasama &);
    bool operator==(const Murasama &);
    bool operator!=(const Murasama &);
    Murasama operator!();

    // SETTERS
    void setRagePool(int r);
    // GETTERS
    bool getHiddenPower() const;
    // bool getBeenAcquired() const;
    int getRagePool() const;

    // FUNCTIONS
    int lingchi();
    void unlockHiddenPower();
    void lockHiddenPower();
    void decreaseRagePool();
    void increaseRagePool();

    // VIRTUAL FUNCTIONS
    std::string getStats() const;
    Murasama *clone() const;
    int attack();

private:
    bool hiddenPowerIsActive_;
    // static bool beenAcquired_;
    int ragePool_;
};

// ----------------------------------------------------------------

class Excalibur : public Swords
{
    friend std::ostream &operator<<(std::ostream &, const Excalibur &);

public:
    Excalibur();
    Excalibur(const std::string &n, const std::string &d, int value, int qtd, int mxdg, int mdg, int dura, int p, int e);
    Excalibur(const Excalibur &);
    ~Excalibur();

    // OPERATORS
    const Excalibur &operator=(const Excalibur &);
    bool operator==(const Excalibur &);
    bool operator!=(const Excalibur &);
    Excalibur operator!();

    // SETTERS
    void setEnergy(int v);
    // GETTERS
    int getEnergy() const;
    // bool getBeenAcquired() const;

    // FUNCTIONS
    void increaseEnergy();
    int excalibur();

    // VIRTUAL FUNCTIONS
    std::string getStats() const;
    Excalibur *clone() const;
    virtual int attack();

private:
    int energyPool_;
    void resetEnergy();
    // static bool beenAcquired_;
};

#endif // WEAP