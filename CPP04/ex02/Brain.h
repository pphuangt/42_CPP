#ifndef BRAIN_H
#define BRAIN_H
#include <iostream>
#include <string>

class Brain {
private:
    std::string ideas[100];
    int _index;

public:
    Brain();
    Brain(const Brain& other);
    ~Brain();

    Brain& operator=(const Brain& other);

    void add_idea(const std::string& idea);
    std::string get_idea(int index) const;

    static const int brain_size = 100;
};

std::ostream& operator<<(std::ostream& os, const Brain& brain);

#endif
