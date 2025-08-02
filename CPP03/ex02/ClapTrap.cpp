#include "ClapTrap.h"
#include <iostream>

ClapTrap::ClapTrap()
    : _health(_defaultDamage), _energy(_defaultEnergy), _damage(_defaultDamage)
{
    std::cout << "ClapTrap" << " Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name), _health(_defaultHealth), _energy(_defaultEnergy),
      _damage(_defaultDamage)
{
    std::cout << "ClapTrap " << _name << " String constructor called" << std::endl;
}

ClapTrap::ClapTrap(unsigned int health, unsigned int energy,
                   unsigned int damage)
    : _health(health), _energy(energy), _damage(damage)
{
    std::cout << "ClapTrap" << " Custom constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name, unsigned int health,
                   unsigned int energy, unsigned int damage)
    : _name(name), _health(health), _energy(energy), _damage(damage)
{
    std::cout << "ClapTrap " << _name << " Custom constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name), _health(other._health), _energy(other._energy),
      _damage(other._damage)
{
    std::cout << "ClapTrap " << _name << " Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " Destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& other)
{
    std::cout << "ClapTrap " << _name << " Assignation operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
        _health = other._health;
        _energy = other._energy;
        _damage = other._damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap " << _name;
    if (_health == 0) {
        std::cout << " cannot attack because it's already dead." << '\n';
    }
    else if (_energy == 0) {
        std::cout << " cannot attack because it has no energy points left."
                  << '\n';
    }
    else {
        _energy--;
        std::cout << " attacks " << target << ", causing " << _damage
                  << " points of damage!" << '\n';
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << _name;
    if (_health == 0) {
        std::cout << " cannot take more damage because it's already dead."
                  << '\n';
    }
    else if (_health <= amount) {
        _health = 0;
        std::cout << " takes " << amount << " points of damage and dies!"
                  << '\n';
    }
    else {
        _health -= amount;
        std::cout << " takes " << amount << " points of damage!" << '\n';
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << _name;
    if (_health == 0) {
        std::cout << " cannot repair itself because it's already dead." << '\n';
    }
    else if (_energy == 0) {
        std::cout
                << " cannot repair itself because it has no energy points left."
                << '\n';
    }
    else {
        _energy--;
        _health += amount;
        std::cout << " repairs itself for " << amount << " points of damage!"
                  << '\n';
    }
}
