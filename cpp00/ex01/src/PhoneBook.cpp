/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:52:13 by lucas             #+#    #+#             */
/*   Updated: 2023/04/30 17:44:12 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/program.hpp"

PhoneBook::PhoneBook(void)
{
    this->util = new Util();
    this->_contacts_index = 0;
    for (int i = 0; i < MAX_CONTACTS; i++)
    {
        this->_contacts[i].util = this->util;
    }
}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::searchContact(void) {}

void PhoneBook::_getContactInfo(void)
{
    this->_contacts[this->_contacts_index].setFirstName();
    this->_contacts[this->_contacts_index].setLastName();
    this->_contacts[this->_contacts_index].setNickname();
    this->_contacts[this->_contacts_index].setPhoneNumber();
    this->_contacts[this->_contacts_index].setDarkestSecret();
}

void PhoneBook::addContact(void)
{
    std::string info[INFO_SIZE];

    if (this->_contacts_index == MAX_CONTACTS - 1)
        this->_contacts_index = 0;

    this->_getContactInfo();
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
    std::cout << " _____  _    _  ____  _   _ ______ ____   ____   ____  _  __ \n";
    std::cout << "|  __ \\| |  | |/ __ \\| \\ | |  ____|  _ \\ / __ \\ / __ \\| |/ / \n";
    std::cout << "| |__) | |__| | |  | |  \\| | |__  | |_) | |  | | |  | | ' / \n";
    std::cout << "|  ___/|  __  | |  | | . ` |  __| |  _ <| |  | | |  | |  < \n";
    std::cout << "| |    | |  | | |__| | |\\  | |____| |_) | |__| | |__| | . \\ \n";
    std::cout << "|_|    |_|  |_|\\____/|_| \\_|______|____/ \\____/ \\____/|_|\\_\\ \n";
}

void PhoneBook::phoneBookMenu(void)
{
    std::cout << "-------------------------------------------------------------\n";
    std::cout << "[ ADD or 1 ]      * Add a new contact\n";
    std::cout << "[ SEARCH or 2 ]   * Search for a contact\n";
    std::cout << "[ EXIT or 3 ]     * Exit the program\n";
    std::cout << "-------------------------------------------------------------\n";
}
