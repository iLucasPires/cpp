/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:40:48 by lucas             #+#    #+#             */
/*   Updated: 2023/05/11 14:16:40 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <iostream>
#include <string>
#include <iomanip>

#define C_RED "\033[1;31m"
#define C_GREEN "\033[1;32m"
#define C_YELLOW "\033[1;33m"
#define C_RESET "\033[0m"
#define C_BOLD "\033[1m"

#define BR '\n'

#define SEPARATOR "==============================="

#define ERROR_INPUT "Input fall or eof detected. Exiting..."
#define ERROR_COMMAND_NOT_FOUND "Command not found. Try again."
#define ERROR_COMMAND_TOO_LONG "Command can't have more than 256 characters. Try again: "
#define ERROR_COMMAND_EMPTY "Command can't be empty. Try again."
#define ERROR_COMMAND_NOT_VALID "Please, verify your input. Try again"
#define INPUT_COMMAND "Please, enter a command: "

#include "Util.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"

#endif
