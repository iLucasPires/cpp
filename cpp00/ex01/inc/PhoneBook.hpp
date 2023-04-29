/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:54:08 by lucas             #+#    #+#             */
/*   Updated: 2023/04/29 14:05:54 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define MAX_CONTACTS 8

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void addContact(void);
        void searchContact(void);

        void phoneBookHeader(void);
        void phoneBookMenu(void);

        Util _util;

    private:
        int _contacts_index;
        Contact _contacts[MAX_CONTACTS];

        void _printContactList(void);
        void _getContactInfo(std::string info[INFO_SIZE]);
};

#endif
