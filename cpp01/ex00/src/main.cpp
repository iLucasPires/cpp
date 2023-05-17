/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:51:01 by lucas             #+#    #+#             */
/*   Updated: 2023/05/12 15:07:30 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* newZombie( std::string name );
void randomChump( std::string name );

int main(void)
{
    Zombie zombie1("Lucas");
    Zombie *zombie2 = newZombie("Rodrigo");


    zombie1.announce();
    zombie2->announce();
    randomChump("banana");

    delete zombie2;
    return 0;
}
