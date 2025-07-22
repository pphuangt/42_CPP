#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.h"
#include <iomanip>
#include <iostream>

class PhoneBook {
private:
    int index;
    Contact contacts[8];
    void _display() const;
    static std::string _truncateField(const std::string& str);
    static bool _getInput(const std::string& prompt, std::string& input);

public:
    PhoneBook();
    PhoneBook(const PhoneBook& other);
    PhoneBook& operator=(const PhoneBook& other);
    ~PhoneBook();
    void add();
    void search();
};

#endif
