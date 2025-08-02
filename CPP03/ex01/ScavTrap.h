#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
private:
    static const unsigned int _defaultHealth = 100;
    static const unsigned int _defaultEnergy = 50;
    static const unsigned int _defaultDamage = 20;

public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);
    ~ScavTrap();

    ScavTrap& operator=(const ScavTrap& other);

    void guardGate();
};

#endif
