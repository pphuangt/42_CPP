#ifndef HUMANB_H
#define HUMANB_H
#include "Weapon.hpp"
#include <iostream>
#include <string>

class HumanB {
private:
    std::string _name;
    Weapon* _type;

public:
    HumanB(const std::string& name);
    ~HumanB();
    void setWeapon(Weapon& type);
    void attack() const;
};

#endif
