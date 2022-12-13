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
    virtual ~Item();

    // OPERATORS
    const Item &operator=(const Item &);
    bool operator==(const Item &);
    bool operator!=(const Item &);

    // VER DEPOIS
    // Item operator!();

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

    // PURE VIRTUAL FUNCTIONS
    /**
     * Utilizada para copiar objetos de maneira mais pratica no inventario
     */
    virtual Item *clone() const = 0;
    /**
     * Utilizada para printar stats dos itens de maneira organizada
     */
    virtual std::string getStats() const = 0;

private:
    std::string name_;
    std::string description_;
    int value_;
    int qtd_;

    // STAT CAPS
    static const int MAX_NAME_LENGTH = 16;
    static const int MAX_DESC_LENGTH = 500;
    static const int MAX_VALUE = 9999999;
    static const int MAX_QTD = 1;
};

// ----------------------------------------------------------------

// ----------------------------------------------------------------
class Armors : public Item
{
    friend std::ostream &operator<<(std::ostream &, const Armors &);

public:
    Armors();
    Armors(const std::string &n, const std::string &d, int value, int qtd, int arm);
    Armors(const Item &cp, int arm);
    Armors(const Armors &cpA);
    virtual ~Armors();

    // OPERATORS
    // VOLTAR DPS
    const Armors &operator=(const Armors &);
    bool operator==(const Armors &);
    bool operator!=(const Armors &);
    Armors operator!();
    // SETTERS
    void setArmor(int arm);
    // GETTERS
    int getArmor() const;

    // FUNCTIONS
    // int durabilityDmg();
    // void breakArmor();

    // VIRTUAL FUNCTIONS
    std::string getStats() const;
    virtual Armors *clone() const;

    static const int MAX_ARMOR = 9999;

private:
    int armor_;
};

// ----------------------------------------------------------------

#endif