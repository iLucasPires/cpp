/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:34:03 by lucas             #+#    #+#             */
/*   Updated: 2023/05/10 15:13:46 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.hpp"

PhoneBook::PhoneBook() { this->_contactsCount = 0; }

PhoneBook::~PhoneBook() {}

bool PhoneBook::getComand(const std::string message, std::function<bool(std::string)> validate)
{
    if (!message.empty())
        std::cout << message;

    while (this->_isRunning)
    {
        std::getline(std::cin, this->command);
        if (std::cin.eof() || std::cin.bad() || std::cin.fail())
        {
            std::cout << "Error in input. Exiting..." << std::endl;
            this->_isRunning = false;
            return false;
        }

        if (this->command.empty())
        {
            std::cout << "Command can't be empty. Try again: ";
            this->command.clear();
            continue;
        }

        if (validate && !validate(this->command))
        {
            std::cout << "Please, verify your input. Try again: ";
            continue;
        }
        return true;
    }
    return false;
}

void PhoneBook::addNewContact()
{
    this->getComand("First name: ", NULL);
    this->_contacts[this->_contactsCount].setFirstName(this->command);

    this->getComand("Last name: ", NULL);
    this->_contacts[this->_contactsCount].setLastName(this->command);

    this->getComand("Nickname: ", NULL);
    this->_contacts[this->_contactsCount].setNickname(this->command);

    this->getComand("Number: ", NULL);
    this->_contacts[this->_contactsCount].setNumber(this->command);

    this->getComand("Darkest secret: ", NULL);
    this->_contacts[this->_contactsCount].setDarkestSecret(this->command);
}

void PhoneBook::searchContact()
{
    std::cout << std::setw(10) << std::right << "Index" << "|";
    std::cout << std::setw(10) << std::right << "First name" << "|";
    std::cout << std::setw(10) << std::right << "Last name" << "|";
    std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

}
