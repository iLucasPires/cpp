#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("r2d2"), _hitPoints(10),
					   _attackDamage(0), _energyPoints(10)
{
	std::cout << "[ClapTrap] " << this->_name << " default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
									   _attackDamage(0), _energyPoints(10)
{
	std::cout << "[ClapTrap] " << this->_name << " constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "[ClapTrap] copy constructor called\n";
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] " << this->_name << " destructor called\n";
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "[ClapTrap] assignation operator called\n";
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
	}
	return *this;
}

void ClapTrap::attack(std::string const &target)
{
	std::cout << "[ClapTrap] ";
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
	this->_energyPoints--;
	std::cout << this->_name << " attacks " << target
			  << " causing " << this->_attackDamage << " points of damage! [HP = "
			  << this->_hitPoints << "] [EP = " << this->_energyPoints
			  << "]\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "[ClapTrap] ";
	if (this->_hitPoints > 0)
	{
		this->_hitPoints -= amount;
		std::cout << this->_name << " take damage " << amount
				  << " points! [HP = " << this->_hitPoints << "] [EP = "
				  << this->_energyPoints << "]\n";
		return;
	}
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead! [HP = " << this->_hitPoints
				  << "] [EP = " << this->_energyPoints << "]\n";
		return;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "[ClapTrap] ";
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead! [HP = " << this->_hitPoints
				  << "] [EP = " << this->_energyPoints << "]\n";
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " has no energy to repair! [HP = " << this->_hitPoints
				  << "] [EP = " << this->_energyPoints << "]\n";
		return;
	}
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << this->_name << " be repaired " << amount << " points"
			  << "! [HP = " << this->_hitPoints << "] [EP = "
			  << this->_energyPoints << "]\n";
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}
