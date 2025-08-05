#ifndef CAT_H
#define CAT_H
#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
private:
    Brain* _brain;

public:
    Cat();
    Cat(const Cat& other);
    ~Cat();

    Cat& operator=(const Cat& other);

    void makeSound() const;
    Brain* brain();
};

#endif
