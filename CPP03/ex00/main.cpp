#include "ClapTrap.h"

int main()
{
    ClapTrap clap1("Clap1");
    ClapTrap clap2("Clap2");
    ClapTrap clap3(clap1);

    clap1.takeDamage(5);
    clap1.takeDamage(6);
    clap1.takeDamage(1);
    clap1.takeDamage(0);

    clap1.beRepaired(5);
    clap1.beRepaired(0);
    clap2.beRepaired(5);
    clap2.beRepaired(6);
    clap2.beRepaired(0);

    clap1.attack("Target1");
    clap2.attack("Target2");
    clap2.attack("Target3");
    clap2.attack("Target4");
    clap2.attack("Target5");
    clap2.attack("Target6");
    clap2.attack("Target7");
    clap2.attack("Target8");
    clap2.attack("Target9");
    clap2.attack("Target10");

    clap2 = clap1;
    clap2.attack("Target3");

    return 0;
}
