#ifndef ANIMAL_H
#define ANIMAL_H
#include "Brain.h"
#include <string>

class Animal {
protected:
    std::string type;

public:
    Animal();
    Animal(const std::string& s);
    Animal(const Animal& other);
    virtual ~Animal();

    Animal& operator=(const Animal& other);

    virtual void makeSound() const;
    virtual Brain* brain();
    const std::string& getType() const;
};

#endif
