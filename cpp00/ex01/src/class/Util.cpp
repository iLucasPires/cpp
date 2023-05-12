/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:55:23 by lucas             #+#    #+#             */
/*   Updated: 2023/05/12 13:03:42 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.hpp"

Util::Util() { this->isRunning = true; }
Util::~Util() {}

void Util::headerTable()
{
    std::cout << std::setw(10) << std::right << "Index"
              << "|" << std::setw(10) << std::right << "First name"
              << "|" << std::setw(10) << std::right << "Last name"
              << "|" << std::setw(10) << std::right << "Nickname"
              << BR;
}

void Util::bodyTable(std::string firstName, std::string lastName, std::string nickname, int index)
{
    firstName = firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName;
    lastName = lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName;
    nickname = nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname;

    std::cout << std::string(45, '-') << BR
              << std::setw(10) << std::right << index << "|"
              << std::setw(10) << std::right << firstName << "|"
              << std::setw(10) << std::right << lastName << "|"
              << std::setw(10) << std::right << nickname << BR
              << std::string(45, '-') << BR;
}

void Util::onlyContact(std::string info[])
{
    if (info == NULL)
    {
        std::cout << "Contact is empty." << BR;
        return;
    }
    std ::cout << std::string(45, '-') << BR
               << "First name: " << info[FIRST_NAME] << BR
               << "Last name: " << info[LAST_NAME] << BR
               << "Nickname: " << info[NICKNAME] << BR
               << "Phone number: " << info[NUMBER] << BR
               << "Darkest secret: " << info[DARKEST_SECRET] << BR
                << std::string(45, '-') << BR;
}

bool Util::getComand(const std::string message, std::string &value, bool (*validate)(std::string))
{
    std::string input;

    if (this->isRunning == false)
    {
        return false;
    }

    while (true)
    {
        if (message.empty() == false)
        {
            std::cout << C_RESET << message;
        }
        std::getline(std::cin, input);

        if (std::cin.eof() || std::cin.bad() || std::cin.fail())
        {
            std::cout << C_RED << ERROR_INPUT << C_RESET << BR;
            this->isRunning = false;
            return false;
        }

        if (input.length() > 256)
        {
            std::cout << C_YELLOW << ERROR_COMMAND_TOO_LONG
                      << C_RESET << BR;
            continue;
        }

        if (input.empty() == true)
        {
            std::cout << C_YELLOW << ERROR_COMMAND_EMPTY
                      << C_RESET << BR;
            continue;
        }

        if (validate != NULL)
        {
            if (validate(input) == false)
            {
                continue;
            }
        }

        value = input;
        return true;
    }
}
