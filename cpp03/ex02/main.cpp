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
    print_header("CONSTRUCTORS CLAPTRAP");
    ClapTrap emily("Emily");
    ClapTrap nico("Nico");

    print_header("CONSTRUCTORS SCAVTRAP");
    ScavTrap luffy("Luffy");
    ScavTrap zoro("Zoro");

    print_header("CONSTRUCTORS FRAGTRAP");
    FragTrap sanji("Sanji");
    FragTrap chopper("Chopper");

    print_header("BATTLE CLAPTRAP");
    emily.attack(nico.getName());
    nico.takeDamage(emily.getAttackDamage());
    nico.beRepaired(10);
    nico.attack(emily.getName());
    emily.takeDamage(nico.getAttackDamage());
    emily.beRepaired(10);

    print_header("BATTLE SCAVTRAP");
    luffy.attack(zoro.getName());
    zoro.takeDamage(luffy.getAttackDamage());
    zoro.beRepaired(10);
    zoro.guardGate();

    zoro.attack(luffy.getName());
    luffy.takeDamage(zoro.getAttackDamage());
    luffy.beRepaired(10);
    luffy.guardGate();

    print_header("COPY CONSTRUCTOR CLAPTRAP");
    ClapTrap emily2(emily);
    ClapTrap nico2(nico);

    print_header("BATTLE 2 CLAPTRAP");
    emily2.attack(nico2.getName());
    nico2.takeDamage(emily2.getAttackDamage());
    nico2.beRepaired(10);
    nico2.attack(emily2.getName());
    emily2.takeDamage(nico2.getAttackDamage());
    emily2.beRepaired(10);

    print_header("COPY CONSTRUCTOR SCAVTRAP");
    ScavTrap luffy2(luffy);
    ScavTrap zoro2(zoro);

    print_header("BATTLE 2 SCAVTRAP");
    luffy2.attack(zoro2.getName());
    zoro2.takeDamage(luffy2.getAttackDamage());
    zoro2.beRepaired(10);
    zoro2.guardGate();

    zoro2.attack(luffy2.getName());
    luffy2.takeDamage(zoro2.getAttackDamage());
    luffy2.beRepaired(10);
    luffy2.guardGate();


    print_header("BATTLE FRAGTRAP");
    sanji.attack(chopper.getName());
    chopper.takeDamage(sanji.getAttackDamage());
    chopper.beRepaired(10);
    chopper.highFivesGuys();

    chopper.attack(sanji.getName());
    sanji.takeDamage(chopper.getAttackDamage());
    sanji.beRepaired(10);
    sanji.highFivesGuys();

    print_header("COPY CONSTRUCTOR FRAGTRAP");
    FragTrap sanji2(sanji);
    FragTrap chopper2(chopper);

    print_header("BATTLE 2 FRAGTRAP");
    sanji2.attack(chopper2.getName());
    chopper2.takeDamage(sanji2.getAttackDamage());
    chopper2.beRepaired(10);
    chopper2.highFivesGuys();

    chopper2.attack(sanji2.getName());
    sanji2.takeDamage(chopper2.getAttackDamage());
    sanji2.beRepaired(10);
    sanji2.highFivesGuys();

    print_header("DESTRUCTORS");
    return (0);
}
