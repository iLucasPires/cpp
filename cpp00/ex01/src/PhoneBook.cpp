/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:52:13 by lucas             #+#    #+#             */
/*   Updated: 2023/04/29 14:05:29 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/program.hpp"

PhoneBook::PhoneBook(void)
{
    this->_contacts_index = 0;
}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::searchContact(void) {}

void PhoneBook::_getContactInfo(std::string info[INFO_SIZE])
{
    std::cin.clear();

    this->_util.printTerminal("First name: ");
    this->_util.inputTerminal(info[FIRST_NAME]);

    this->_util.printTerminal("Last name: ");
    this->_util.inputTerminal(info[LAST_NAME]);

    this->_util.printTerminal("Nickname: ");
    this->_util.inputTerminal(info[NICKNAME]);

    this->_util.printTerminal("Phone number: ");
    this->_util.inputTerminal(info[PHONE_NUMBER]);

    this->_util.printTerminal("Darkest secret: ");
    this->_util.inputTerminal(info[DARKEST_SECRET]);
    this->_util.printTerminal("\nContact added successfully!\n");
}

void PhoneBook::addContact(void)
{
    if (this->_contacts_index == MAX_CONTACTS)
        this->_contacts_index = 0;
    std::string info[INFO_SIZE];
    this->_getContactInfo(info);
    this->_contacts[this->_contacts_index].setInfo(info);
    this->_contacts_index++;
}

void PhoneBook::_printContactList(void)
{
    for (int i = 0; i < this->_contacts_index; i++)
    {
        std::cout << "\n-------------------------------------------------------------";
        std::cout << this->_contacts[i].getInfo(FIRST_NAME) << "*";
        std::cout << this->_contacts[i].getInfo(LAST_NAME) << "*";
        std::cout << this->_contacts[i].getInfo(NICKNAME) << "*";
        std::cout << this->_contacts[i].getInfo(PHONE_NUMBER) << "*";
        std::cout << this->_contacts[i].getInfo(DARKEST_SECRET) << "*";
        std::cout << "\n-------------------------------------------------------------";
    }
    std::cout << std::endl;
}

void PhoneBook::phoneBookHeader(void)
{
    std::cout << "-------------------------------------------------------------\n";
    std::cout << " _____  _    _  ____  _   _ ______ ____   ____   ____  _  __ \n";
    std::cout << "|  __ \\| |  | |/ __ \\| \\ | |  ____|  _ \\ / __ \\ / __ \\| |/ / \n";
    std::cout << "| |__) | |__| | |  | |  \\| | |__  | |_) | |  | | |  | | ' / \n";
    std::cout << "|  ___/|  __  | |  | | . ` |  __| |  _ <| |  | | |  | |  < \n";
    std::cout << "| |    | |  | | |__| | |\\  | |____| |_) | |__| | |__| | . \\ \n";
    std::cout << "|_|    |_|  |_|\\____/|_| \\_|______|____/ \\____/ \\____/|_|\\_\\ \n";
    std::cout << "-------------------------------------------------------------\n";
}

void PhoneBook::phoneBookMenu(void)
{
    std::cout << "[ ADD or 1 ]      * Add a new contact\n";
    std::cout << "[ SEARCH or 2 ]   * Search for a contact\n";
    std::cout << "[ EXIT or 3 ]     * Exit the program\n";
    std::cout << "-------------------------------------------------------------\n";
    std::cout << "Enter a command: ";
}
