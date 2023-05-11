/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:34:03 by lucas             #+#    #+#             */
/*   Updated: 2023/05/11 02:40:18 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.hpp"

PhoneBook::PhoneBook() { this->_contactsCount = 0; }

PhoneBook::~PhoneBook() {}

bool PhoneBook::_validateName(std::string name)
{
    int len = name.length();

    if (len < 3 || len > 20)
    {
        std::cout << "Name must have between 3 and 20 characters." << std::endl;
        return false;
    }

    for (int i = 0; i < len; i++)
    {
        if (!std::isalpha(name[i]))
        {
            std::cout << "Name must have only letters." << std::endl;
            return false;
        }
    }
    return true;
}

bool PhoneBook::_validateNickname(std::string nickname)
{
    int len = nickname.length();

    if (len < 3 || len > 20)
    {
        std::cout << "Nickname must have between 3 and 20 characters." << std::endl;
        return false;
    }

    for (int i = 0; i < len; i++)
    {
        if (!std::isalnum(nickname[i]))
        {
            std::cout << "Nickname must have only letters and numbers." << std::endl;
            return false;
        }
    }
    return true;
}

bool PhoneBook::_validateNumber(std::string number)
{
    int len = number.length();

    if (len < 3 || len > 20)
    {
        std::cout << "Number must have between 3 and 20 characters." << std::endl;
        return false;
    }

    for (int i = 0; i < len; i++)
    {
        if (!std::isdigit(number[i]))
        {
            std::cout << "Number must have only numbers." << std::endl;
            return false;
        }
    }
    return true;
}

bool PhoneBook::_validateIndex(std::string index)
{
    if (index[0] < '0' || index[0] > '7' || index.length() > 1)
    {
        std::cout << "Index must be between 0 and 7." << std::endl;
        return false;
    }

    return true;
}

void PhoneBook::addNewContact()
{
    std::string info[MAX_INFO_SIZE];

    if (this->util.getComand("First name: ", info[FIRST_NAME], this->_validateName) &&
        this->util.getComand("Last name: ", info[LAST_NAME], this->_validateName) &&
        this->util.getComand("Nickname: ", info[NICKNAME], this->_validateNickname) &&
        this->util.getComand("Number: ", info[NUMBER], this->_validateNumber) &&
        this->util.getComand("Darkest secret: ", info[DARKEST_SECRET], NULL))
    {
        this->_contacts[this->_contactsCount].setAllInfo(info);
        this->_contactsCount++;
    }
}

void PhoneBook::searchContact()
{
    this->util.headerTable();

    for (int i = 0; i < this->_contactsCount; i++)
    {
        this->util.bodyTable(
            this->_contacts[i].getFirstName(),
            this->_contacts[i].getLastName(),
            this->_contacts[i].getNickname(),
            i);
    }
    std::string input;

    if (this->util.getComand("Select a contact: [0-7] ", input, this->_validateIndex) &&
        input[0] - '0' < this->_contactsCount)
    {
        this->util.onlyContact(this->_contacts[input[0] - '0'].getAllInfo());
    }
    else if (this->util.isRunning)
    {
        std::cout << "Invalid index or contact not found." << std::endl;
    }
}