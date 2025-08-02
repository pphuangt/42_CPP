#include "FragTrap.h"
#include <iostream>

int main()
{
    FragTrap frag1("Frag1");
    FragTrap frag2("Frag2");
    FragTrap frag3(frag1);

    frag1.takeDamage(50);
    frag1.takeDamage(60);
    frag1.takeDamage(10);
    frag1.takeDamage(0);

    frag1.beRepaired(5);
    frag1.beRepaired(0);
    frag2.beRepaired(5);
    frag2.beRepaired(6);
    frag2.beRepaired(0);

    frag1.attack("Target1");
    frag2.attack("Target2");
    frag2.attack("Target3");
    frag2.attack("Target4");
    frag2.attack("Target5");
    frag2.attack("Target6");
    frag2.attack("Target7");
    frag2.attack("Target8");
    frag2.attack("Target9");
    frag2.attack("Target10");

    frag1.highFivesGuys();
    frag2.highFivesGuys();

    frag2 = frag1;
    frag2.attack("Target3");

    return 0;
}