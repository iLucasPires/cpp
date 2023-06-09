/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:53:19 by lucas             #+#    #+#             */
/*   Updated: 2023/05/17 20:10:40 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_HPP
#define UTIL_HPP

class Util
{
    public:
        Util();
        ~Util();

        bool isRunning;

        void headerTable(void);
        void bodyTable(std::string firstName, std::string lastName, std::string nickname, int index);
        void onlyContact(std::string info[]);
        bool getComand(const std::string message, std::string &value, bool (*validate)(std::string));
};

#endif
