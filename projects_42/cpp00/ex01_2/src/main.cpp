/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:38:28 by lucas             #+#    #+#             */
/*   Updated: 2023/05/10 00:00:13 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.hpp"

void header()
{
    std::cout << "Welcome to your phone book! \n";
    std::cout << "[ADD or 1]: to add a new contact \n";
    std::cout << "[SEARCH or 2]: to search a contact \n";
    std::cout << "[EXIT or 3]: to exit the program \n";
}

int main(void)
{
    PhoneBook phone;

    header();
    while (phone._isRunning)
    {
        if (phone.getComand("Please, enter a command:", NULL) == false)
            return false;

        if (phone.command == "ADD" || phone.command == "1")
        {
            phone.addNewContact();
            continue;
        }

        if (phone.command == "SEARCH" || phone.command == "2")
        {
            phone.searchContact();
            continue;
        }

        if (phone.command == "EXIT" || phone.command == "3")
        {
            std::cout << "Exiting..." << std::endl;
            phone._isRunning = false;
            continue;
        }
    }
    return 0;
}
