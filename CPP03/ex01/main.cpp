#include "ScavTrap.h"

int main()
{
    ScavTrap scav1("Scav1");
    ScavTrap scav2("Scav2");
    ScavTrap scav3(scav1);

    scav1.takeDamage(50);
    scav1.takeDamage(60);
    scav1.takeDamage(10);
    scav1.takeDamage(0);

    scav1.beRepaired(5);
    scav1.beRepaired(0);
    scav2.beRepaired(5);
    scav2.beRepaired(6);
    scav2.beRepaired(0);

    scav1.attack("Target1");
    scav2.attack("Target2");
    scav2.attack("Target3");
    scav2.attack("Target4");
    scav2.attack("Target5");
    scav2.attack("Target6");
    scav2.attack("Target7");
    scav2.attack("Target8");
    scav2.attack("Target9");
    scav2.attack("Target10");

    scav1.guardGate();
    scav2.guardGate();

    scav2 = scav1;
    scav2.attack("Target3");

    return 0;
}