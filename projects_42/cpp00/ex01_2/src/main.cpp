/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:38:28 by lucas             #+#    #+#             */
/*   Updated: 2023/05/11 13:16:06 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.hpp"

void header()
{
    std::cout << C_BOLD << "Welcome to your phonebook!" << BR
              << C_BOLD << SEPARATOR << BR
              << C_BOLD << "[ADD or 1] add a new contact" << BR
              << C_BOLD << "[SEARCH or 2] search a contact" << BR
              << C_BOLD << "[EXIT or 3] exit the program" << BR
              << C_RESET << C_BOLD << SEPARATOR << BR;
}

int main(void)
{
    PhoneBook phone;
    std::string command;

    header();
    while (phone.util.isRunning)
    {
        if (phone.util.getComand(INPUT_COMMAND, command, NULL) == false)
            return false;

        if (command == "ADD" || command == "1")
        {
            phone.addNewContact();
            continue;
        }

        if (command == "SEARCH" || command == "2")
        {
            phone.searchContact();
            continue;
        }

        if (command == "EXIT" || command == "3")
        {
            std::cout << C_GREEN << "Remember not to have any backups, bye!" << C_RESET << std::endl;
            return 0;
        }
    }
    return 0;
}
