/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:30:03 by lucas             #+#    #+#             */
/*   Updated: 2023/05/06 00:22:08 by lucas            ###   ########.fr       */
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
    Util::printTerminal(msg, false);
    std::getline(std::cin, str);
    if (std::cin.eof() || std::cin.fail())
    {
        Util::isLooping = false;
        Util::printTerminal("\nBye bye!");
        return (false);
    }
    Util::strToUpper(str);
    return (true);
}
