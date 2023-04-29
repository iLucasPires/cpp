/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 22:11:57 by lucas             #+#    #+#             */
/*   Updated: 2023/04/28 20:29:34 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/program.hpp"

Contact::Contact(void)
{
    std::fill(this->_info, this->_info + INFO_SIZE, NULL);

}

Contact::~Contact(void) {}

void Contact::setInfo(std::string info[INFO_SIZE])
{
    this->_info[FIRST_NAME] = info[FIRST_NAME];
    this->_info[LAST_NAME] = info[LAST_NAME];
    this->_info[NICKNAME] = info[NICKNAME];
    this->_info[PHONE_NUMBER] = info[PHONE_NUMBER];
    this->_info[DARKEST_SECRET] = info[DARKEST_SECRET];
}

std::string Contact::getInfo(int index)
{
    return (this->_info[index]);
}
