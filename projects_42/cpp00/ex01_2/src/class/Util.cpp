/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:55:23 by lucas             #+#    #+#             */
/*   Updated: 2023/05/11 02:32:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.hpp"

Util::Util() {}
Util::~Util() {}

void Util::headerTable()
{
    std::cout << C_BOLD << SEPARATOR << "\n"
              << std::setw(10) << std::right << "Index"
              << "|" << std::setw(10) << std::right << "First name"
              << "|" << std::setw(10) << std::right << "Last name"
              << "|" << std::setw(10) << std::right << "Nickname"
              << "|" << std::endl;
}

void Util::bodyTable(std::string firstName, std::string lastName, std::string nickname, int index)
{

    std::cout << "----------|----------|----------|----------\n"
              << std::setw(10) << std::right << index << "|"
              << std::setw(10) << std::right << firstName << "|"
              << std::setw(10) << std::right << lastName << "|"
              << std::setw(10) << std::right << nickname << "|" << std::endl;
}

void Util::onlyContact(std::string info[])
{
    if (this->isRunning == false)
    {
        return;
    }

    std ::cout << C_BOLD << SEPARATOR << "\n"
               << "First name: " << info[FIRST_NAME] << "\n"
               << "Last name: " << info[LAST_NAME] << "\n"
               << "Nickname: " << info[NICKNAME] << "\n"
               << "Phone number: " << info[NUMBER] << "\n"
               << "Darkest secret: " << info[DARKEST_SECRET] << "\n"
               << SEPARATOR << std::endl;
}

bool Util::getComand(const std::string message, std::string &value, bool (*validate)(std::string))
{
    std::string input;

    if (this->isRunning == false)
    {
        return false;
    }

    if (message.empty() == false)
    {
        std::cout << message;
    }

    while (true)
    {
        std::getline(std::cin, input);

        if (std::cin.eof() || std::cin.bad() || std::cin.fail())
        {
            std::cout << C_RED << ERROR_INPUT << std::endl;
            this->isRunning = false;
            return false;
        }

        if (input.length() > 256)
        {
            std::cout << ERROR_COMMAND_TOO_LONG;
            continue;
        }

        if (input.empty() == true)
        {
            std::cout << ERROR_COMMAND_EMPTY;
            continue;
        }

        if (validate != NULL && validate(input) == false)
        {
            std::cout << ERROR_COMMAND_NOT_VALID;
            continue;
        }

        value = input;
        return true;
    }
}
