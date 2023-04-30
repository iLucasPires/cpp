/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:11:57 by lucas             #+#    #+#             */
/*   Updated: 2023/04/30 17:21:11 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/program.hpp"

Contact::Contact(void)
{
    std::fill(this->_info, this->_info + INFO_SIZE, NULL);
}

Contact::~Contact(void) {}

bool Contact::setFirstName(void)
{
    this->util->inputTerminal(this->util->command, "First name: ");
    for (int i = 0; i < (int)this->util->command.length(); i++)
    {
        if (!std::isalpha(this->util->command[i]))
        {
            this->util->printTerminal("Invalid first name, try again.");
            this->setFirstName();
            return (false);
        }
    }
    this->_info[FIRST_NAME] = this->util->command;
    return (true);
}

bool Contact::setLastName(void)
{
    this->util->inputTerminal(this->util->command, "Last name: ");
    for (int i = 0; i < (int)this->util->command.length(); i++)
    {
        if (!std::isalpha(this->util->command[i]))
        {
            this->util->printTerminal("Invalid last name, try again.");
            this->setLastName();
            return (false);
        }
    }
    this->_info[LAST_NAME] = this->util->command;
    return (true);
}

bool Contact::setNickname(void)
{
    this->util->inputTerminal(this->util->command, "Nickname: ");
    for (int i = 0; i < (int)this->util->command.length(); i++)
    {
        if (!std::isalpha(this->util->command[i]))
        {
            this->util->printTerminal("Invalid nickname, try again.");
            this->setNickname();
            return (false);
        }
    }
    this->_info[NICKNAME] = this->util->command;
    return (true);
}

bool Contact::setPhoneNumber(void)
{
    this->util->inputTerminal(this->util->command, "Phone number: ");
    for (int i = 0; i < (int)this->util->command.length(); i++)
    {
        if (!std::isdigit(this->util->command[i]))
        {
            this->util->printTerminal("Invalid phone number, try again.");
            this->setPhoneNumber();
            return (false);
        }
    }
    this->_info[PHONE_NUMBER] = this->util->command;
    return (true);
}

bool Contact::setDarkestSecret(void)
{
    this->util->inputTerminal(this->util->command, "Darkest secret: ");
    this->_info[DARKEST_SECRET] = this->util->command;
    return (true);
}


std::string Contact::getInfo(int index)
{
    return (this->_info[index]);
}
