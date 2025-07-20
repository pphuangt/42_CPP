#include "Contact.h"

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact(const Contact& other)
    : _firstName(other._firstName), _lastName(other._lastName),
      _nickname(other._nickname), _darkestSecret(other._darkestSecret),
      _phoneNumber(other._phoneNumber)
{}

Contact& Contact::operator=(const Contact& other)
{
    if (this != &other) {
        this->_firstName = other._firstName;
        this->_lastName = other._lastName;
        this->_nickname = other._nickname;
        this->_darkestSecret = other._darkestSecret;
        this->_phoneNumber = other._phoneNumber;
    }
    return *this;
}

std::string Contact::getFirstName(void)
{
    return (this->_firstName);
}

std::string Contact::getLastName(void)
{
    return (this->_lastName);
}

std::string Contact::getNickname(void)
{
    return (this->_nickname);
}

std::string Contact::getDarkestSecret(void)
{
    return (this->_darkestSecret);
}

std::string Contact::getPhoneNumber(void)
{
    return (this->_phoneNumber);
}

void Contact::setFirstName(const std::string &firstName)
{
    this->_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
    this->_lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
    this->_nickname = nickname;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
    this->_darkestSecret = darkestSecret;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
    this->_phoneNumber = phoneNumber;
}
