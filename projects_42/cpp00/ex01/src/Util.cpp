/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:30:03 by lucas             #+#    #+#             */
/*   Updated: 2023/05/08 23:32:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/program.hpp"

bool Util::isLooping = true;
std::string Util::command = "";

Util::Util(void) {}

Util::~Util(void) {}

void Util::strToUpper(std::string &str)
{
    for (int i = 0; str[i]; i++)
        str[i] = std::toupper(str[i]);
}

bool Util::inputTerminal(std::string &str)
{
    std::getline(std::cin, str);
    if (std::cin.eof() || std::cin.fail())
    {
        std::cout << "\nBye bye!" << std::endl;
        return (false);
    }
    return (true);
}

bool Util::inputTerminal(int &num)
{
    std::cin >> num;
    if (std::cin.eof() || std::cin.fail())
    {
        std::cout << "\nBye bye!" << std::endl;
        return (false);
    }
    std::cin.ignore();
    return (true);
}
