#include <iostream>

int main(const int ac, char **av)
{
    if (ac > 1) {
        for (int i = 1; i < ac; i++) {
            const char  *s = av[i];
            for (int j = 0; s[j] != '\0'; j++) {
                const char c = std::toupper(s[j]);
                std::cout << c;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
}