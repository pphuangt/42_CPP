#include "Dog.h"
#include <iostream>

Dog::Dog(): Animal("Dog"), _brain(new Brain())
{
    std::cout << type << " constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other), _brain(new Brain(*other._brain))
{
    std::cout << type << " copy constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << type << " destructor called" << std::endl;
    delete _brain;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << type << " copy assignment operator called." << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *_brain = *other._brain;
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Woof!" << '\n';
}

Brain* Dog::brain()
{
    return _brain;
}