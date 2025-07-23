#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.h"
#include <iomanip>
#include <iostream>

class PhoneBook {
private:
    int _index;
    Contact _contacts[8];
    bool _readInput(const std::string& prompt, std::string& s);
    void _displayList();
    void _displayContact(int index);
    std::string _trim(const std::string& s);
    std::string _truncateField(const std::string& s);

public:
    PhoneBook();
    ~PhoneBook();
    bool add();
    bool search();
};

#endif
