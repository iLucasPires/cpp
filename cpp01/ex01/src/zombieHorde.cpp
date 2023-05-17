/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:31:53 by lucas             #+#    #+#             */
/*   Updated: 2023/05/15 00:42:56 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
  if (N <= 0) {
    std::cout << "the number of zombies must be greater than 0" << std::endl;
    return (NULL);
  }

  Zombie *zombie = new Zombie[N];

  for (int i = 0; i < N; i++) {
    zombie[i].setName(name);
    zombie[i].announce();
  }

  return zombie;
}
