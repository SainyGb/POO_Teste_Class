#ifndef ITEM_H__
#define ITEM_H__

#include <iostream>
#include <string>

class Item
{
public:
    Item();
    Item(const std::string &n = "noName", const std::string &d = "noDescription", int value = 0, int qtd = 0);
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
};

#endif