/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:34:03 by lucas             #+#    #+#             */
/*   Updated: 2023/05/11 23:14:14 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.hpp"

PhoneBook::PhoneBook()
{
    this->_contactsIndex = 0;
    this->_contactsCount = 0;
}

PhoneBook::~PhoneBook() {}

bool PhoneBook::_validateName(std::string name)
{
    int len = name.length();

    if (len < 3 || len > 20)
    {
        std::cout << C_YELLOW << "Name must have between 3 and 20 characters." << BR;
        return false;
    }

    for (int i = 0; i < len; i++)
    {
        if (!std::isalpha(name[i]))
        {
            std::cout << C_YELLOW << "Name must have only letters." << BR;
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
        std::cout << C_YELLOW << "Nickname must have between 3 and 20 characters." << BR;
        return false;
    }

    for (int i = 0; i < len; i++)
    {
        if (!std::isalnum(nickname[i]))
        {
            std::cout << C_YELLOW << "Nickname must have only letters and numbers." << BR;
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
        std::cout << C_YELLOW << "Number must have between 3 and 20 characters." << BR;
        return false;
    }

    for (int i = 0; i < len; i++)
    {
        if (!std::isdigit(number[i]))
        {
            std::cout << C_YELLOW << "Number must have only numbers." << BR;
            return false;
        }
    }
    return true;
}

bool PhoneBook::_validateIndex(std::string index)
{
    if (index[0] < '0' || index[0] > '7' || index.length() > 1)
    {
        std::cout << C_YELLOW << "Index must be between 0 and 7." << BR;
        return false;
    }

    return true;
}

void PhoneBook::addNewContact()
{
    std::string info[MAX_INFO_SIZE];
    if (this->_contactsIndex == 8)
    {
        this->_contactsIndex = 0;
    }
    if (this->util.getComand("First name: ", info[FIRST_NAME], this->_validateName) &&
        this->util.getComand("Last name: ", info[LAST_NAME], this->_validateName) &&
        this->util.getComand("Nickname: ", info[NICKNAME], this->_validateNickname) &&
        this->util.getComand("Number: ", info[NUMBER], this->_validateNumber) &&
        this->util.getComand("Darkest secret: ", info[DARKEST_SECRET], NULL))
    {
        this->_contacts[this->_contactsIndex].setAllInfo(info);
        if (this->_contactsCount < 8)
            this->_contactsCount++;
        this->_contactsIndex++;
    }
}

void PhoneBook::searchContact()
{
    if (this->_contactsIndex == 0)
    {
        std::cout << "No contacts found." << BR;
        return;
    }

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

    if (this->util.getComand("Select a contact: [0-7] ", input, this->_validateIndex))
    {
        this->util.onlyContact(this->_contacts[input[0] - '0'].getAllInfo());
    }
}
