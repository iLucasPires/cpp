/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:15:15 by lucas             #+#    #+#             */
/*   Updated: 2023/05/17 00:06:56 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    this->_level[0] = "DEBUG";
    this->_level[1] = "INFO";
    this->_level[2] = "WARNING";
    this->_level[3] = "ERROR";

    this->_ptr[0] = &Harl::_debug;
    this->_ptr[1] = &Harl::_info;
    this->_ptr[2] = &Harl::_warning;
    this->_ptr[3] = &Harl::_error;
};

Harl::~Harl(){};

void Harl::complain(std::string level)
{
    for (int i = 0; i < 4; i++)
    {
        if (level == this->_level[i])
            (this->*this->_ptr[i])();
    }
};

void Harl::_debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::_info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::_warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
