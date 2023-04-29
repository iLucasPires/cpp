/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:30:03 by lucas             #+#    #+#             */
/*   Updated: 2023/04/29 14:02:31 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/program.hpp"

Util::Util(void) {}
Util::~Util(void) {}

void Util::strToUpper(std::string &str)
{
    for (int i = 0; str[i]; i++)
        str[i] = std::toupper(str[i]);
}

void Util::printTerminal(std::string str)
{
    if (str.empty())
        return;
    std::cout << str << std::endl;
}

bool Util::inputTerminal(std::string &str)
{
    std::getline(std::cin, str);
    if (std::cin.eof())
    {
        std::cout << "\n" << EOF_ERROR << std::endl;
        std::cin.clear();
        return (false);
    }
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cout << INVALID_INPUT << std::endl;
        this->inputTerminal(str);
    }
    if (str.empty())
    {
        std::cout << INVALID_INPUT << std::endl;
        this->inputTerminal(str);
    }
    return (true);
}
