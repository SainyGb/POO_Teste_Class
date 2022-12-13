#include <iostream>
#include <string>

#include "item.h"

class Pocoes : public Item
{
    friend std::ostream &operator<<(std::ostream &, const Pocoes &);

public:
    Pocoes();
    Pocoes(std::string &n, std::string &dp, int v, int q, int p, int d);
    Pocoes(const Pocoes &);
    virtual ~Pocoes();

    // OPERATORS
    const Pocoes &operator=(const Pocoes &);
    bool operator==(const Pocoes &);
    bool operator!=(const Pocoes &);
    // Pocoes operator!();

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
    PocaoCura(std::string &n, std::string &dp, int v, int q, int p, int d, int vc);
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
    PocaoDef(std::string &n, std::string &dp, int v, int q, int p, int d, int df);
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