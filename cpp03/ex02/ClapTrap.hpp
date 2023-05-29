#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string _name;
	int _hitPoints;
	int _attackDamage;
	int _energyPoints;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap();

	ClapTrap &operator=(ClapTrap const &rhs);

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	bool checkIsAlive(void) const;
	bool cheackHasEnergy(void) const;

	std::string getName(void) const;
	int getAttackDamage(void) const;
};

#endif
