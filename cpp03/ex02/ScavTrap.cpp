#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called\n";
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called\n";
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called\n";
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
	}
	return *this;
}

void ScavTrap::attack(std::string const &target)
{
	std::cout << "ScavTrap ";
	if (!this->checkIsAlive() || !this->cheackHasEnergy())
		return;

	std::cout << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage!\n";

	this->_energyPoints--;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap ";
	if (this->checkIsAlive() == false)
		return;

	std::cout << this->_name << " has entered Gate keeper mode\n";
}
