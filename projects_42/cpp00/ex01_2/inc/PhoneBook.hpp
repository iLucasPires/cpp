/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:39:08 by lucas             #+#    #+#             */
/*   Updated: 2023/05/10 15:08:52 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook
{
    private:
        int _contactsCount;
        Contact _contacts[8];

        bool _validateName(std::string name);
        bool _validateNickname(std::string nickname);
        bool _validateNumber(std::string number);

    public:
        bool _isRunning;
        std::string command;

        PhoneBook();
        ~PhoneBook();

        void addNewContact(void);
        void searchContact(void);
        bool getComand(const std::string message, std::function<bool(std::string)> validate);
};

#endif
