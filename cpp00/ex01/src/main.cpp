/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:15:03 by lucas             #+#    #+#             */
/*   Updated: 2023/04/30 17:52:34 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/program.hpp"

int main(void)
{
    PhoneBook phonebook;

    phonebook.phoneBookHeader();
    while (Util::isLooping)
    {
        phonebook.phoneBookMenu();
        phonebook.util->inputTerminal(Util::command, "Enter a command: ");
        phonebook.util->strToUpper(Util::command);
        if (Util::command == "ADD" || Util::command == "1")
        {
            phonebook.util->printTerminal("Adding a new contact...");
            phonebook.addContact();
        }
        else if (Util::command == "SEARCH" || Util::command == "2")
        {
            phonebook.util->printTerminal("Searching for a contact...");
            phonebook.searchContact();
        }

        else if (Util::command == "EXIT" || Util::command == "3")
        {
            phonebook.util->printTerminal("Exiting...");
            phonebook.util->isLooping = false;
        }
        else
        {
            phonebook.util->printTerminal(INVALID_COMMAND);
            continue;
        }
    }

    return (SUCCESS);
}
