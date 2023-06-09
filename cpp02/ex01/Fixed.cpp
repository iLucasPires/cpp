/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:38:35 by lucas             #+#    #+#             */
/*   Updated: 2023/05/23 16:37:15 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw = (1 << this->_bits) * number;
}

Fixed::Fixed(const float number)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw = roundf((1 << this->_bits) * number);
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_raw = rhs.getRawBits();
	}
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

void Fixed::setRawBits(int const raw)
{
	this->_raw = raw;
}

int Fixed::toInt(void) const
{
	return this->_raw / (1 << this->_bits);
}

float Fixed::toFloat(void) const
{
	return this->_raw / (float)(1 << this->_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &self)
{
	return out << self.toFloat();
}
