/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:38:28 by lucas             #+#    #+#             */
/*   Updated: 2023/05/18 15:53:04 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phone;
    std::string command;

    std::cout << C_BOLD << C_GREEN << "Welcome to your phonebook!" << C_RESET << '\n'
              << std::string(45, '-') << '\n'
              << "[ADD] add a new contact" << '\n'
              << "[SEARCH] search a contact" << '\n'
              << "[EXIT] exit the program" << '\n'
              << C_RESET << std::string(45, '-') << '\n';
    while (phone.util.isRunning)
    {
        if (phone.util.getComand("enter a command: ", command, NULL) == false)
            return false;

        if (command == "ADD")
        {
            phone.addNewContact();
            continue;
        }

        if (command == "SEARCH")
        {
            phone.searchContact();
            continue;
        }

        if (command == "EXIT")
        {
            std::cout << C_GREEN << "Remember not to have any backups, bye!" << C_RESET << std::endl;
            return 0;
        }

        else
        {
            std::cout << C_RED << "Command not found. Try again." << C_RESET << '\n';
            continue;
        }
    }
    return 0;
}
