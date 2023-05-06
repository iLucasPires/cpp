/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:26:12 by lucas             #+#    #+#             */
/*   Updated: 2023/04/30 19:49:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_HPP
#define UTIL_HPP

class Util
{
    public:
        Util(void);
        ~Util(void);

        static void strToUpper(std::string &str);
        static void printTerminal(std::string str, bool endLine = true);
        static bool inputTerminal(std::string &str, std::string msg);

        static bool isLooping;
        static std::string command;
};

#endif
