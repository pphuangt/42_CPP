#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.h"

class PhoneBook {
private:
    int index;
    Contact contacts[8];

public:
    PhoneBook(void);
    ~PhoneBook(void);
    void add();
    void search();
};

#endif
