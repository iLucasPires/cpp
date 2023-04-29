/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:15:03 by lucas             #+#    #+#             */
/*   Updated: 2023/04/29 14:05:51 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/program.hpp"

int main(void)
{
    Util util;
    PhoneBook phonebook;

    std::string command;
    phonebook.phoneBookHeader();
    while (true)
    {
        phonebook.phoneBookMenu();
        util.inputTerminal(command);
        util.strToUpper(command);

        if (command == "ADD" || command == "1")
        {
            util.printTerminal("Adding a new contact...");
            phonebook.addContact();
        }
        else if (command == "SEARCH" || command == "2")
        {
            util.printTerminal("Searching for a contact...");
            phonebook.searchContact();
        }

        else if (command == "EXIT" || command == "3")
        {
            util.printTerminal("Exiting...");
            break;
        }
        else
        {
            util.printTerminal(INVALID_COMMAND);
            continue;
        }
    }

    return (SUCCESS);
}
