#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include <string>

class ClapTrap {
private:
    static const unsigned int _defaultHealth = 10;
    static const unsigned int _defaultEnergy = 10;
    static const unsigned int _defaultDamage = 0;

protected:
    std::string _name;
    unsigned int _health;
    unsigned int _energy;
    unsigned int _damage;

public:
    ClapTrap();
    ClapTrap(const std::string& name);
    ClapTrap(unsigned int health, unsigned int energy, unsigned int damage);
    ClapTrap(const std::string& name, unsigned int health, unsigned int energy,
             unsigned int damage);
    ClapTrap(const ClapTrap& other);
    ~ClapTrap();

    ClapTrap& operator=(ClapTrap const& other);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
