/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:26:12 by lucas             #+#    #+#             */
/*   Updated: 2023/04/29 14:02:27 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_HPP
#define UTIL_HPP

class Util
{
    public:
        Util(void);
        ~Util(void);


        void strToUpper(std::string &str);
        void printTerminal(std::string str);
        bool inputTerminal(std::string &str);

};

#endif
