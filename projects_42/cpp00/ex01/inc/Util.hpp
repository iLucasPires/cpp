/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:26:12 by lucas             #+#    #+#             */
/*   Updated: 2023/05/08 23:33:12 by lucas            ###   ########.fr       */
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
        static bool inputTerminal(std::string &str);
        static bool inputTerminal(int &num);

        static bool isLooping;
        static std::string command;
};

#endif