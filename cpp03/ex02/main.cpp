#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

static void print_header(std::string str)
{
    std::cout << "============================================================\n"
              << str << '\n'
              << "============================================================\n";
}

int main(void)
{
    print_header("CONSTRUCTORS");
    ScavTrap sentinel;
    ScavTrap sentinel2;
    FragTrap ultron("Ultron");
    FragTrap ultron2("Ultron2");
    ClapTrap clap("Clap");

    print_header("COPY CONSTRUCTORS");
    ScavTrap sentinelCopy(sentinel);

    print_header("BATLLE");
    ultron.attack(sentinel.getName());
    ultron.highFivesGuys();
    sentinel.takeDamage(ultron.getAttackDamage());
    sentinel.beRepaired(10);
    sentinel.beRepaired(10);
    sentinel.guardGate();
    sentinel2.attack(sentinelCopy.getName());
    sentinelCopy.takeDamage(sentinel2.getAttackDamage());
    sentinelCopy.beRepaired(10);
    sentinelCopy.beRepaired(10);
    sentinelCopy.guardGate();


    print_header("DESTRUCTORS");

    return (0);
}
