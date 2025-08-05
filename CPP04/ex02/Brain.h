#ifndef BRAIN_H
#define BRAIN_H
#include <iostream>
#include <string>

class Brain {
private:
    static const int brain_size = 100;
    std::string ideas[brain_size];
    int _index;

public:
    Brain();
    Brain(const Brain& other);
    ~Brain();

    Brain& operator=(const Brain& other);

    void add_idea(const std::string& idea);
    std::string get_idea(int index) const;
};

#endif
