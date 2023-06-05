#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{

public:
	Brain();
	Brain(Brain const &src);
	~Brain();

	Brain &operator=(Brain const &rhs);

	void setIdeas(std::string idea);
	std::string getIdea(int index) const;

private:
	std::string ideas[100];
};

std::ostream &operator<<(std::ostream &o, Brain const &rhs);

#endif
