/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:44:40 by lucas             #+#    #+#             */
/*   Updated: 2023/05/15 02:10:42 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/HumanA.h"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {}

HumanA::~HumanA(void) {}

void HumanA::attack(void) const
{
    std::cout << this->_name << " attacks with their "
              << this->_weapon.getType() << std::endl;
}
