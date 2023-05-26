#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("r2d2"), _hitPoints(10),
					   _attackDamage(0), _energyPoints(10)
{
	std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
									   _attackDamage(0), _energyPoints(10)
{
	std::cout << "ClapTrap name constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap copy constructor called\n";

	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "ClapTrap assignation operator called\n";

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
	std::cout << "ClapTrap";

	if (!this->checkIsAlive() || !this->cheackHasEnergy())
		return;

	std::cout << this->_name << " attacks " << target
			  << '\n';

	this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap ";

	if (this->_hitPoints > 0)
	{
		this->_hitPoints -= amount;
		std::cout << this->_name << " takes "
				  << amount << " points of damage! "
				  << this->_hitPoints << " hit points, "
				  << this->_energyPoints << " energy points\n";
	}

	this->checkIsAlive();
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap ";

	if (!this->checkIsAlive() || !this->cheackHasEnergy())
		return;

	this->_hitPoints += amount;
	this->_energyPoints--;

	std::cout << this->_name << " is repaired for "
			  << amount << " points of health! "
			  << this->_hitPoints << " hit points, "
			  << this->_energyPoints << " energy points\n";
}

bool ClapTrap::checkIsAlive(void) const
{
	if (this->_hitPoints > 0)
		return (true);
	else
	{
		std::cout << this->_name << " is dead\n";
		return (false);
	}
}

bool ClapTrap::cheackHasEnergy(void) const
{
	if (this->_energyPoints > 0)
		return (true);
	else
	{
		std::cout << this->_name << " has no energy\n";
		return (false);
	}
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}
int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}
