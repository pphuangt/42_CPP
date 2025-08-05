#ifndef ANIMAL_H
#define ANIMAL_H
#include "Brain.h"
#include <string>

class Animal {
protected:
    Animal();
    Animal(const std::string& s);
    Animal(const Animal& other);

    Animal& operator=(const Animal& other);

    std::string type;

public:
    virtual ~Animal();

    virtual void makeSound() const = 0;
    virtual Brain* brain();
    const std::string& getType() const;
};

#endif
