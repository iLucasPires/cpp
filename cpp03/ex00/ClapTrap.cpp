#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("r2d2"), _hitPoints(10),
					   _attackDamage(0), _energyPoints(10)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10),
									   _attackDamage(0), _energyPoints(10)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "ClapTrap assignation operator called" << std::endl;
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
	if (this->_energyPoints <= 0)
	{
		showStatus("has no energy");
		return;
	}
	if (this->_hitPoints <= 0)
	{
		showStatus("is dead");
		return;
	}
	showStatus("attacks " + target);
	--this->_energyPoints;
}

void ClapTrap::showStatus(std::string state)
{
	std::cout << "ClapTrap " << this->_name << " " << state << "!"
			  << " [AD = " << this->_attackDamage << "]"
			  << " [HP = " << this->_hitPoints << "]"
			  << " [EP = " << this->_energyPoints << "]"
			  << '\n';
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0)
	{
		showStatus("take damege");
		this->_hitPoints -= amount;
	}
	if (this->_hitPoints <= 0)
	{
		showStatus("is dead");
		return;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		showStatus("is dead");
		return;
	}
	if (this->_energyPoints <= 0)
	{
		showStatus("has no energy");
		return;
	}
	this->_hitPoints += amount;
	--this->_energyPoints;
	showStatus("be repaired");
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

std::ostream &operator<<(std::ostream &out, ClapTrap const &self)
{
	out << self.getName();
	return out;
}
