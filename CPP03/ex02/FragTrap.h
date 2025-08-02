#ifndef FRAGTRAP_H
#define FRAGTRAP_H
#include "ClapTrap.h"

class FragTrap : public ClapTrap {
private:
    static const unsigned int _defaultHealth = 100;
    static const unsigned int _defaultEnergy = 100;
    static const unsigned int _defaultDamage = 30;

public:
    FragTrap();
    FragTrap(const std::string& name);
    FragTrap(const FragTrap& other);
    ~FragTrap();

    FragTrap& operator=(const FragTrap& other);

    void highFivesGuys();
};

#endif
