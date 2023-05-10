/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:11:57 by lucas             #+#    #+#             */
/*   Updated: 2023/05/08 23:54:35 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/program.hpp"

Contact::Contact(void)
{
    std::fill(this->_info, this->_info + INFO_SIZE, NULL);
}

Contact::~Contact(void) {}

bool Contact::_validName(std::string name)
{
    if (name.empty())
    {
        std::cout << "Please, no empty names. \n";
        std::cout << "Invalid name, try again." << std::endl;
        return (false);
    }
    for (int i = 0; i < (int)name.length(); i++)
    {
        if (!std::isalpha(name[i]))
        {
            std::cout << "Please, use only letters. \n";
            std::cout << "Invalid name, try again." << std::endl;
            return (false);
        }
    }
    return (true);
}

bool Contact::_validPhoneNumber(std::string phone_number)
{
    for (int i = 0; i < (int)phone_number.length(); i++)
    {
        if (!std::isdigit(phone_number[i]))
        {
            std::cout << "Please, use only numbers. \n";
            std::cout << "Invalid phone number, try again." << std::endl;
            return (false);
        }
    }
    return (true);
}

bool Contact::_validNickname(std::string nickname)
{
    if (nickname.empty())
    {
        std::cout << "Please, no empty nicknames. \n";
        std::cout << "Invalid nickname, try again." << std::endl;
        return (false);
    }
    for (int i = 0; i < (int)nickname.length(); i++)
    {
        if (!std::isalpha(nickname[i]))
        {
            std::cout << "Please, use only letters. \n";
            std::cout << "Invalid nickname, try again." << std::endl;
            return (false);
        }
    }
    return (true);
}

void Contact::setInfo(std::string info, int index)
{
    this->_info[index] = info;
}

std::string Contact::getInfo(int index)
{
    return (this->_info[index]);
}
