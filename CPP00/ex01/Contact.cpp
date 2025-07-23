#include "Contact.h"

Contact::Contact() {}

Contact::~Contact() {}

std::string Contact::getFirstName()
{
    return (_firstName);
}

std::string Contact::getLastName()
{
    return (_lastName);
}

std::string Contact::getNickname()
{
    return (_nickname);
}

std::string Contact::getDarkestSecret()
{
    return (_darkestSecret);
}

std::string Contact::getPhoneNumber()
{
    return (_phoneNumber);
}

void Contact::setFirstName(const std::string &firstName)
{
    _firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
    _lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
    _nickname = nickname;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
    _darkestSecret = darkestSecret;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
    _phoneNumber = phoneNumber;
}
