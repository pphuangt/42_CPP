#include <iostream>
#include <string>

int main()
{
    std::string s = "HI THIS IS BRAIN";
    std::string *sPTR = &s;
    std::string &sREF = s;

    std::cout << "Memory Addresses:" << std::endl;
    std::cout << "Address of string variable s: " << &s << std::endl;
    std::cout << "Address held by sPTR: " << sPTR << std::endl;
    std::cout << "Address held by sREF: " << &sREF << std::endl;
    std::cout << "Values:" << std::endl;
    std::cout << "Value of string variable s: " << s << std::endl;
    std::cout << "Value pointed to by sPTR: " << *sPTR << std::endl;
    std::cout << "Value pointed to by sREF: " << sREF << std::endl;
}