/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:35:29 by lucas             #+#    #+#             */
/*   Updated: 2023/05/09 20:55:16 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.hpp"

Contact::Contact()
{
    this->_firstName = "";
    this->_lastName = "";
    this->_nickname = "";
    this->_number = "";
    this->_darkest_secret = "";
}

Contact::~Contact() {}

void Contact::setFirstName(std::string firstName) { this->_firstName = firstName; }

void Contact::setLastName(std::string lastName) { this->_lastName = lastName; }

void Contact::setNickname(std::string nickname) { this->_nickname = nickname; }

void Contact::setNumber(std::string number) { this->_number = number; }

void Contact::setDarkestSecret(std::string darkestSecret) { this->_darkest_secret = darkestSecret; }
