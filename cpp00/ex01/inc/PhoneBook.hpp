/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:39:08 by lucas             #+#    #+#             */
/*   Updated: 2023/05/18 15:55:18 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

#define C_RED "\033[0;31m"
#define C_GREEN "\033[0;32m"
#define C_YELLOW "\033[0;33m"
#define C_RESET "\033[0m"
#define C_BOLD "\033[1m"

#include "Util.hpp"
#include "Contact.hpp"

class PhoneBook
{
    private:
        int _contactsIndex;
        int _contactsCount;

        Contact _contacts[8];

        static bool _validateName(std::string name);
        static bool _validateNickname(std::string nickname);
        static bool _validateNumber(std::string number);
        static bool _validateIndex(std::string index);

    public:
        Util util;

        PhoneBook();
        ~PhoneBook();

        void addNewContact(void);
        void searchContact(void);
};

#endif
