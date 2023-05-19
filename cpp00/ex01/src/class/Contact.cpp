/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:35:29 by lucas             #+#    #+#             */
/*   Updated: 2023/05/18 15:53:15 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact()
{
    this->_isEmpty = true;
    std::fill(this->_info, this->_info + MAX_INFO_SIZE, "");
}

Contact::~Contact() {}

std::string *Contact::getAllInfo(void)
{
    if (this->_isEmpty)
        return NULL;
    return this->_info;
}

void Contact::setAllInfo(std::string info[])
{
    for (int i = 0; i < MAX_INFO_SIZE; i++)
        this->_info[i] = info[i];
    this->_isEmpty = false;
}

std::string Contact::getFirstName(void) { return this->_info[FIRST_NAME]; }
std::string Contact::getLastName(void) { return this->_info[LAST_NAME]; }
std::string Contact::getNickname(void) { return this->_info[NICKNAME]; }
std::string Contact::getNumber(void) { return this->_info[NUMBER]; }
std::string Contact::getDarkestSecret(void) { return this->_info[DARKEST_SECRET]; }
