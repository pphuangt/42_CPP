#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout << "destructor zombie " << this->name << std::endl;
}

void Zombie::announce() const
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." <<std::endl;
}

void Zombie::setName(const std::string& name)
{
    this->name = name;
}
