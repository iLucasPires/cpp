#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "[FragTrap] " << this->_name << " default constructor called\n";
	this->_name = "r2d2";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "[FragTrap] " << this->_name << " constructor called\n";
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << "[FragTrap] copy constructor called\n";
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] " << this->_name << " destructor called\n";
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_attackDamage = rhs._attackDamage;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
	}
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "[FragTrap] ";
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead! [HP = " << this->_hitPoints
				  << "] [EP = " << this->_energyPoints << "]\n";
		return;
	}
	std::cout << this->_name << " high fives guys [HP = " << this->_hitPoints
			  << "] [EP = " << this->_energyPoints << "]\n";
}
