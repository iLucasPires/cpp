/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:44:31 by lucas             #+#    #+#             */
/*   Updated: 2023/05/15 02:28:06 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/HumanB.h"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB(void) {}

void HumanB::attack(void) const
{
    std::cout << this->_name << " attacks with their "
              << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }
