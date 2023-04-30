/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:54:28 by lucas             #+#    #+#             */
/*   Updated: 2023/04/30 17:13:23 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#define INFO_SIZE 5

enum
{
    FIRST_NAME,
    LAST_NAME,
    NICKNAME,
    PHONE_NUMBER,
    DARKEST_SECRET
};

class Contact
{
    public:
        Contact(void);
        ~Contact(void);

        std::string getInfo(int index);
        void setInfo(std::string info[INFO_SIZE]);

        bool setFirstName(void);
        bool setLastName(void);
        bool setNickname(void);
        bool setPhoneNumber(void);
        bool setDarkestSecret(void);

        Util *util;

    private:
        bool _is_empty;
        std::string _info[INFO_SIZE];
};

#endif
