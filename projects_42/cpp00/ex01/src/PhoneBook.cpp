/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:52:13 by lucas             #+#    #+#             */
/*   Updated: 2023/05/09 00:00:09 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/program.hpp"

PhoneBook::PhoneBook(void)
{
    _contacts_i = 0;
    isLooping = true;
}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::searchContact(void)
{
    int index;

    if (_contacts_i >= 1)
    {
        this->_tableHeader();
        this->_tableBody();

        std::cout << SEPARATOR << "\n";
        std::cout << CHOOSE_CONTACT << std::endl;
        if (Util::inputTerminal(index))
           this->_printContactInfo(index);
    }
}

void PhoneBook::_tableHeader(void)
{
    std::cout << SEPARATOR << "\n";
    std::cout << std::setw(10) << std::right << "index" << "|";
    std::cout << std::setw(10) << std::right << "first name" << "|";
    std::cout << std::setw(10) << std::right << "last name" << "|";
    std::cout << std::setw(10) << std::right << "nickname" << "|\n";
}

void PhoneBook::_tableBody(void)
{
    std::string info[3];

    for (int i = 0; i < _contacts_i; i++)
    {
        std::cout << std::setw(10) << std::right << i << "|";
        info[0] = _contacts[i].getInfo(0);
        info[1] = _contacts[i].getInfo(1);
        info[2] = _contacts[i].getInfo(2);

        info[0] = info[0].length() > 10 ? info[0].substr(0, 9) : info[0];
        info[1] = info[1].length() > 10 ? info[1].substr(0, 9) : info[1];
        info[2] = info[2].length() > 10 ? info[2].substr(0, 9) : info[2];

        std::cout << std::setw(10) << std::right << info[0] << "|";
        std::cout << std::setw(10) << std::right << info[1] << "|";
        std::cout << std::setw(10) << std::right << info[2] << "|\n";
    }
    std::cout << SEPARATOR << "\n";
}

void PhoneBook::addContact(void)
{
    if (_contacts_i == MAX_CONTACTS - 1)
        _contacts_i = 0;
    _contacts[_contacts_i]._isValid = true;

    this->_setInfo
    this->_setInfo(_contacts[_contacts_i]._info[LAST_NAME], Util::isValidName);
    this->_setInfo(_contacts[_contacts_i]._info[NICKNAME], Util::isValidNickname);
    this->_setInfo(_contacts[_contacts_i]._info[PHONE_NUMBER], Util::isValidPhoneNumber);
    this->_setInfo(_contacts[_contacts_i].setInfo(DARKEST_SECRET), Util::isValidDarkestSecret);

    // _contacts[_contacts_i].setFirstName();
    // _contacts[_contacts_i].setLastName();
    // _contacts[_contacts_i].setNickname();
    // _contacts[_contacts_i].setPhoneNumber();
    // _contacts[_contacts_i].setDarkestSecret();

    if (_contacts[_contacts_i]._isValid)
    {
        _contacts_i++;
        std::cout << "Contact added successfully." << std::endl;
    }
}

bool PhoneBook::setInfo(std::string &info, bool (*valid)(std::string))
{
    bool isInputValid = false;
    std::string input;

    while (isInputValid == false)
    {
        if (!Util::inputTerminal(input))
        {
            return (false);
        }
        isInputValid = valid(input);
    }
    info = input;

    return (true);
}

void PhoneBook::_printContactInfo(int i)
{
    if (i >= 0 && i < _contacts_i)
    {
        std::cout << "First name: " << _contacts[i].getInfo(FIRST_NAME) << "\n";
        std::cout << "Last name: " << _contacts[i].getInfo(LAST_NAME) << "\n";
        std::cout << "Nickname: " << _contacts[i].getInfo(NICKNAME) << "\n";
        std::cout << "Phone number: " << _contacts[i].getInfo(PHONE_NUMBER) << "\n";
        std::cout << "Darkest secret: " << _contacts[i].getInfo(DARKEST_SECRET) << std::endl;
    }
    else
        std::cout << "Invalid index!" << std::endl;
}

void PhoneBook::phoneBookHeader(void)
{
    std::cout << " _____  _    _  ____  _   _ ______ ____   ____   ____  _  __ \n";
    std::cout << "|  __ \\| |  | |/ __ \\| \\ | |  ____|  _ \\ / __ \\ / __ \\| |/ / \n";
    std::cout << "| |__) | |__| | |  | |  \\| | |__  | |_) | |  | | |  | | ' / \n";
    std::cout << "|  ___/|  __  | |  | | . ` |  __| |  _ <| |  | | |  | |  < \n";
    std::cout << "| |    | |  | | |__| | |\\  | |____| |_) | |__| | |__| | . \\ \n";
    std::cout << "|_|    |_|  |_|\\____/|_| \\_|______|____/ \\____/ \\____/|_|\\_\\ \n";
}

void PhoneBook::phoneBookMenu(void)
{
    std::cout << SEPARATOR << "\n";
    std::cout << "[ ADD or 1 ]      * Add a new contact\n";
    std::cout << "[ SEARCH or 2 ]   * Search for a contact\n";
    std::cout << "[ EXIT or 3 ]     * Exit the program\n";
    std::cout << SEPARATOR << "\n";
}
