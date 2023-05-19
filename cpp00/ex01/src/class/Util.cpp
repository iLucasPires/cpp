/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:55:23 by lucas             #+#    #+#             */
/*   Updated: 2023/05/18 16:00:16 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Util::Util() : isRunning(true) {}
Util::~Util() {}

void Util::headerTable()
{
    std::cout << std::setw(10) << std::right << "Index"
              << '|' << std::setw(10) << std::right << "First name"
              << '|' << std::setw(10) << std::right << "Last name"
              << '|' << std::setw(10) << std::right << "Nickname"
              << '\n';
}

void Util::bodyTable(std::string firstName, std::string lastName, std::string nickname, int index)
{
    firstName = firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName;
    lastName = lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName;
    nickname = nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname;

    std::cout << std::string(45, '-') << '\n'
              << std::setw(10) << std::right << index << '|'
              << std::setw(10) << std::right << firstName << '|'
              << std::setw(10) << std::right << lastName << '|'
              << std::setw(10) << std::right << nickname << '\n';
}

void Util::onlyContact(std::string info[])
{
    if (info == NULL)
    {
        std::cout << "Contact is empty." << '\n';
        return;
    }
    std ::cout << std::string(45, '-') << '\n'
               << "First name: " << info[FIRST_NAME] << '\n'
               << "Last name: " << info[LAST_NAME] << '\n'
               << "Nickname: " << info[NICKNAME] << '\n'
               << "Phone number: " << info[NUMBER] << '\n'
               << "Darkest secret: " << info[DARKEST_SECRET] << '\n'
               << std::string(45, '-') << '\n';
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
            std::cout << C_RED << "Input fall or eof detected. Exiting..." << C_RESET << '\n';
            this->isRunning = false;
            return false;
        }

        if (input.length() > 256)
        {
            std::cout << C_YELLOW << "Command can't have more than 256 characters. Try again: "
                      << C_RESET << '\n';
            continue;
        }

        if (input.empty() == true)
        {
            std::cout << C_YELLOW << "Command can't be empty. Try again."
                      << C_RESET << '\n';
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
