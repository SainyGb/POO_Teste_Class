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
    Armors(const std::string &n, const std::string &d, int value, int qtd, int arm, int dbt);
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
    void setDurability(int dbrt);
    // GETTERS
    int getArmor() const;
    int getDurability() const;

    void durabilityDmg();
    void breakArmor();

    // VIRTUAL FUNCTIONS
    std::string getStats() const;
    virtual Armors *clone() const;

    static const int MAX_ARMOR = 9999;

private:
    int armor_;
    int durability_;
};

//----------------------------------------------------------------

class Pocoes : public Item
{

public:
    Pocoes();
    Pocoes(const std::string &n, const std::string &dp, int v, int q, int p, int d);
    Pocoes(const Pocoes &);
    virtual ~Pocoes();

    // SETTERS
    void setPoder(int p);
    void setDuracao(int d);
    // GETTERS
    int getPoder() const;
    int getDuracao() const;

    // FUNCTIONS
    int duracaoTotal() const;

    // VIRTUAL FUNCTIONS
    Item *clone() const = 0;
    std::string getStats() const = 0;

private:
    int poder_; // efetividade da poção
    int duracao_;
};

class PocaoCura : public Pocoes
{
    friend std::ostream &operator<<(std::ostream &, const PocaoCura &);

public:
    PocaoCura();
    PocaoCura(const std::string &n, const std::string &dp, int v, int q, int p, int d, int vc);
    PocaoCura(const PocaoCura &);
    ~PocaoCura();

    // OPERATORS
    const PocaoCura &operator=(const PocaoCura &);
    bool operator==(const PocaoCura &);
    bool operator!=(const PocaoCura &);
    PocaoCura operator!();

    // SETTERS
    void setValorCura(int v);
    // GETTERS
    int getValorCura() const;

    // FUNCTIONS
    int curaTotal() const;

    // VIRTUAL FUNCTIONS
    PocaoCura *clone() const;
    std::string getStats() const;

private:
    int valorCura_;
    static const int HP_CAP = 9999999;
};

class PocaoDef : public Pocoes
{
    friend std::ostream &operator<<(std::ostream &, const PocaoDef &);

public:
    PocaoDef();
    PocaoDef(const std::string &n, const std::string &dp, int v, int q, int p, int d, int df);
    PocaoDef(const PocaoDef &);
    ~PocaoDef();

    // OPERATORS
    const PocaoDef &operator=(const PocaoDef &);
    bool operator==(const PocaoDef &);
    bool operator!=(const PocaoDef &);
    PocaoDef operator!();

    // SETTERS
    void setValorDef(int v);
    // GETTERS
    int getValorDef() const;

    // FUNCTIONS
    int defTotal() const;

    // VIRTUAL FUNCTIONS
    PocaoDef *clone() const;
    std::string getStats() const;

private:
    int valorDef_;
    static const int DEF_CAP = 9999999;
};
// ----------------------------------------------------------------

#endif