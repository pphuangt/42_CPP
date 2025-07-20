#ifndef PHONEBOOK_H
#define PHONEBOOK_H
# include <iostream>
# include <iomanip>
# include "Contact.h"

class PhoneBook {
private:
    int index;
    Contact contacts[8];
    std::string _truncateField(const std::string& str, size_t width);

public:
    PhoneBook(void);
    ~PhoneBook(void);
    void add();
    void search();
};

#endif
