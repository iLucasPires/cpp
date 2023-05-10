/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:15:03 by lucas             #+#    #+#             */
/*   Updated: 2023/05/08 23:33:24 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/program.hpp"

int main(void)
{
    PhoneBook phonebook;
    std::string comannd;

    phonebook.phoneBookHeader();
    while (phonebook.isLooping)
    {
        phonebook.phoneBookMenu();
        std::cout << "Enter a command:";
        if (!Util::inputTerminal(comannd))
        {
            phonebook.isLooping = false;
            break ;
        }
        Util::strToUpper(comannd);
        if (comannd == "ADD" || comannd == "1")
        {
            phonebook.addContact();
        }
        else if (comannd == "SEARCH" || comannd == "2")
        {
            phonebook.searchContact();
        }
        else if (comannd == "EXIT" || comannd == "3")
        {
            std::cout << "Bye bye!" << std::endl;
            phonebook.isLooping = false;
        }
        else
            std::cout << "Invalid command!" << std::endl;
    }

    return (SUCCESS);
}
