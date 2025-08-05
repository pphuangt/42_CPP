#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H
#include <string>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const std::string& s);
    WrongAnimal(const WrongAnimal& other);
    ~WrongAnimal();

    WrongAnimal& operator=(const WrongAnimal& other);

    void makeSound() const;
    const std::string& getType() const;
};

#endif
