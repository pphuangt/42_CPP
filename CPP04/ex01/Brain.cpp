#include "Brain.h"

Brain::Brain(): _index(0)
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other): _index(0)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < brain_size; ++i) { ideas[i] = other.ideas[i]; }
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << '\n';
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other) {
        for (int i = 0; i < brain_size; ++i) { ideas[i] = other.ideas[i]; }
        _index = other._index;
    }
    return *this;
}

void Brain::add_idea(const std::string& idea)
{
    ideas[_index] = idea;
    _index = (_index + 1) % brain_size;
}

std::string Brain::get_idea(int index) const
{
    if (index >= brain_size || index < 0) { return ""; }
    return ideas[index];
}