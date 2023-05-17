/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:51:01 by lucas             #+#    #+#             */
/*   Updated: 2023/05/15 00:42:52 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void) {
  int N = 5;

  Zombie *horde = zombieHorde(N, "Lucas");
  delete[] horde;

  return 0;
}
