/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:55:48 by lucas             #+#    #+#             */
/*   Updated: 2023/05/08 14:46:47 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#define FAILURE 1
#define SUCCESS 0

#define EOF_ERROR "EOF detected. Exiting..."
#define INVALID_INPUT "Invalid input. Try again: "
#define INVALID_COMMAND "Invalid command. Try again: "
#define INVALID_INDEX "Invalid index. Try again: "
#define NO_CONTACTS "No contacts to show."
# define CHOOSE_CONTACT "Choose a contact to see more information[0-7]:"

#define SEPARATOR "==============================================="

#include <iostream>
#include <string>
#include <iomanip>

#include "Util.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"

#endif
