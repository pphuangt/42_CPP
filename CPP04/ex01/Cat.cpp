#include "Cat.h"
#include <iostream>

Cat::Cat(): Animal("Cat"), _brain(new Brain())
{
    std::cout << type << " constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other), _brain(new Brain(*other._brain))
{
    std::cout << type << " copy constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << type << " destructor called" << std::endl;
    delete _brain;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << type << " copy assignment operator called." << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        *_brain = *other._brain;
    }
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

Brain* Cat::brain()
{
    return _brain;
}
