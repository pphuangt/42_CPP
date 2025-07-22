#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    int N = 8;
    Zombie* zombies = zombieHorde(N, "Zombies");

    for (int i = 0; i < N; i++) {
        std::cout << i << "\t";
        zombies[i].announce();
    }
    delete[] zombies;
}