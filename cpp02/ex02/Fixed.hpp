/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:38:41 by lucas             #+#    #+#             */
/*   Updated: 2023/05/22 22:46:50 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <string>

class Fixed
{
public:
	Fixed();
	Fixed(Fixed const &src);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();

	Fixed &operator=(Fixed const &rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;

private:
	int _raw;
	static const int _bits = 8;
};
std::ostream &operator<<(std::ostream &out, const Fixed &self);

#endif
