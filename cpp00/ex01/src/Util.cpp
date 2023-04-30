/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:30:03 by lucas             #+#    #+#             */
/*   Updated: 2023/04/30 02:32:31 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/program.hpp"

Util::Util(void)
{
    this->isLooping = true;
}

Util::~Util(void) {}

void Util::strToUpper(std::string &str)
{
    for (int i = 0; str[i]; i++)
        str[i] = std::toupper(str[i]);
}

void Util::printTerminal(std::string str, bool endLine)
{
    if (str.empty())
        return;
    if (endLine)
        std::cout << str << std::endl;
    else
        std::cout << str;
}

bool Util::inputTerminal(std::string &str, std::string msg)
{

    this->printTerminal(msg, false);
    std::getline(std::cin, str);
    if (std::cin.eof())
    {
        this->isLooping = false;
        this->printTerminal(EOF_ERROR, true);
        return (false);
    }
    if (std::cin.fail())
    {

        this->printTerminal(INVALID_INPUT, true);
        this->inputTerminal(str, msg);
    }
    if (str.empty())
    {
        this->printTerminal(INVALID_INPUT, true);
        this->inputTerminal(str, msg);
    }
    return (true);
}
