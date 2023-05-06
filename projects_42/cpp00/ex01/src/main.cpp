/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:15:03 by lucas             #+#    #+#             */
/*   Updated: 2023/05/06 00:22:13 by lucas            ###   ########.fr       */
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
        if (!Util::inputTerminal(Util::command, "Enter a command: "))
            break;
        if (Util::command == "ADD" || Util::command == "1")
        {
            std::cout << "Adding a new contact..." << std::endl;
            phonebook.addContact();
        }
        else if (Util::command == "SEARCH" || Util::command == "2")
        {
            std::cout << "Searching for a contact..." << std::endl;
            phonebook.searchContact();
        }
        else if (Util::command == "EXIT" || Util::command == "3")
        {
            std::cout << "Bye bye!" << std::endl;
            Util::isLooping = false;
        }
        else
            std::cout << "Invalid command!" << std::endl;
    }

    return (SUCCESS);
}
