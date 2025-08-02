#include "ScavTrap.h"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap(_defaultHealth, _defaultEnergy, _defaultDamage)
{
    std::cout << "ScavTrap " << _name << "Default constructor called"
              << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name, _defaultHealth, _defaultEnergy, _defaultDamage)
{
    std::cout << "ScavTrap " << _name << " String constructor called"
              << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
    std::cout << "ScavTrap " << _name << " Copy constructor called"
              << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " Destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap " << _name << " Assignation operator called"
              << std::endl;
    if (this != &other) { ClapTrap::operator=(other); }
    return *this;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name;
    if (_health == 0) {
        std::cout
                << " cannot go into Gate keeper mode because it's already dead."
                << '\n';
    }
    else {
        std::cout << " is now in Gate keeper mode." << '\n';
    }
}
