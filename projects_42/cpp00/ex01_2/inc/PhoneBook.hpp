/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:39:08 by lucas             #+#    #+#             */
/*   Updated: 2023/05/11 02:30:48 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook
{
    private:
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
