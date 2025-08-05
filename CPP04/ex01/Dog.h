#ifndef DOG_H
#define DOG_H
#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {
private:
    Brain* _brain;

public:
    Dog();
    Dog(const Dog& other);
    ~Dog();

    Dog& operator=(const Dog& other);

    void makeSound() const;
    Brain* brain();
};

#endif
