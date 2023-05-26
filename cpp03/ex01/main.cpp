#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "----- Default constructor -----\n";
    ScavTrap sentinel;
    ScavTrap sentinel2;

    std::cout << "\n----- Name constructor -----\n";
    ScavTrap ultron("Ultron");

    std::cout << "\n----- Copy -----\n";
    ScavTrap sentinelCopy(sentinel);

    std::cout << "\n----- Battle -----\n";
    ultron.attack(sentinel.getName());
    sentinel.takeDamage(ultron.getAttackDamage());
    sentinel.beRepaired(10);
    sentinel.beRepaired(10);
    sentinel.guardGate();
    sentinel2.attack(sentinelCopy.getName());
    sentinelCopy.takeDamage(sentinel2.getAttackDamage());
    sentinelCopy.beRepaired(10);
    sentinelCopy.beRepaired(10);
    sentinelCopy.guardGate();


    std::cout << "\n----- Destructors -----\n";

    return (0);
}
