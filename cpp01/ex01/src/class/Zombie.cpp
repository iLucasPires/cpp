/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:50:53 by lucas             #+#    #+#             */
/*   Updated: 2023/05/14 00:56:58 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout << "The Zombie " << this->_name << " died" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->_name = name;
}
