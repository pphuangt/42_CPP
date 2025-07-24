#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout << "destructor zombie " << _name << std::endl;
}

void Zombie::announce() const
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." <<std::endl;
}

void Zombie::setName(const std::string& name)
{
    _name = name;
}
