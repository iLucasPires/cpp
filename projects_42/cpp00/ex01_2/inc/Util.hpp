/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Util.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:53:19 by lucas             #+#    #+#             */
/*   Updated: 2023/05/11 02:11:35 by lucas            ###   ########.fr       */
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
