#include "ClapTrap.hpp"

static void print_header(std::string str)
{
    std::cout << "============================================================\n"
              << str << '\n'
              << "============================================================\n";
}

int main(void)
{
    print_header("CONSTRUCTORS");

    ClapTrap emily("Emily");
    ClapTrap nico("Nico");

    print_header("BATTLE 1");
    emily.attack(nico.getName());
    nico.takeDamage(emily.getAttackDamage());
    nico.beRepaired(10);
    nico.attack(emily.getName());
    emily.takeDamage(nico.getAttackDamage());
    emily.beRepaired(10);

    print_header("COPY CONSTRUCTOR");
    ClapTrap emily2(emily);
    ClapTrap nico2(nico);

    print_header("BATTLE 2");
    emily2.attack(nico2.getName());
    nico2.takeDamage(emily2.getAttackDamage());
    nico2.beRepaired(10);
    nico2.attack(emily2.getName());
    emily2.takeDamage(nico2.getAttackDamage());
    emily2.beRepaired(10);

    print_header("DESTRUCTORS");
    return (0);
}
