/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:53:04 by lucas             #+#    #+#             */
/*   Updated: 2023/05/18 16:14:14 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Weapon.h"

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon(void) {}

void Weapon::setType(std::string type) { this->_type = type; }

const std::string &Weapon::getType(void) const { return (this->_type); }
