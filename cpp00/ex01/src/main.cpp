/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:38:28 by lucas             #+#    #+#             */
/*   Updated: 2023/05/12 13:04:50 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.hpp"

int main(void)
{
    PhoneBook phone;
    std::string command;

    std::cout << C_BOLD << C_GREEN << "Welcome to your phonebook!" << C_RESET << BR
              << std::string(45, '-') << BR
              << "[ADD] add a new contact" << BR
              << "[SEARCH] search a contact" << BR
              << "[EXIT] exit the program" << BR
              << C_RESET << std::string(45, '-') << BR;
    while (phone.util.isRunning)
    {
        if (phone.util.getComand(INPUT_COMMAND, command, NULL) == false)
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
            std::cout << C_RED << ERROR_COMMAND_NOT_FOUND << C_RESET << BR;
            continue;
        }
    }
    return 0;
}
