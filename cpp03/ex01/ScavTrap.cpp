#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "[ScavTrap] " << this->_name << " default constructor called\n";
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[ScavTrap] " << this->_name << " constructor called\n";
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	std::cout << "[ScavTrap] copy constructor called\n";
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] " << this->_name << " destructor called\n";
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
	std::cout << "[ScavTrap] ";
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " has no energy to attack! [HP = " << this->_hitPoints
				  << "] [EP = " << this->_energyPoints << "]\n";
		return;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead! [HP = " << this->_hitPoints
				  << "] [EP = " << this->_energyPoints << "]\n";
		return;
	}
	std::cout << this->_name << " attacks " << target
			  << " causing " << this->_attackDamage << " points of damage! [HP = "
			  << this->_hitPoints << "] [EP = " << this->_energyPoints
			  << "]\n";

	this->_energyPoints--;
}

void ScavTrap::guardGate(void)
{
	std::cout << "[ScavTrap] ";
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead! [HP = " << this->_hitPoints
				  << "] [EP = " << this->_energyPoints << "]\n";
		return;
	}

	std::cout << this->_name << " has entered Gate keeper mode [HP = "
			  << this->_hitPoints << "] [EP = " << this->_energyPoints
			  << "]\n";
}
