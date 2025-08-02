#include "FragTrap.h"
#include <iostream>

FragTrap::FragTrap(): ClapTrap(_defaultHealth, _defaultEnergy, _defaultDamage)
{
    std::cout << "FragTrap " << _name << "Default constructor called"
              << std::endl;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name, _defaultHealth, _defaultEnergy, _defaultDamage)
{
    std::cout << "FragTrap " << _name << " String constructor called"
              << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
    std::cout << "FragTrap " << _name << " Copy constructor called"
              << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap " << _name << " Assignation operator called"
              << std::endl;
    if (this != &other) { ClapTrap::operator=(other); }
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name;
    if (_health == 0) {
        std::cout << " cannot request a high five because it's already dead."
                  << '\n';
    }
    else {
        std::cout << " requests a high five." << '\n';
    }
}
