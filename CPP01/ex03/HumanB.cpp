#include "HumanB.hpp"

HumanB::HumanB(const std::string& name): _name(name), _type(nullptr) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& type)
{
    _type = &type;
}

void HumanB::attack() const
{
    std::cout << _name << " attacks with their "
        << (_type ? _type->getType() : "hand") << std::endl;
}
