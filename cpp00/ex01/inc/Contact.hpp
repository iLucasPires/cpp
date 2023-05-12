/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:37:52 by lucas             #+#    #+#             */
/*   Updated: 2023/05/11 12:55:53 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# define MAX_INFO_SIZE 5

enum infoIndex
{
    FIRST_NAME,
    LAST_NAME,
    NICKNAME,
    NUMBER,
    DARKEST_SECRET
};

class Contact
{
    private:
        bool _isEmpty;
        std::string _info[MAX_INFO_SIZE];


    public:
        void setAllInfo(std::string info[]);
        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNickname(void);
        std::string getNumber(void);
        std::string getDarkestSecret(void);
        std::string *getAllInfo(void);


        Contact();
        ~Contact();
};

#endif
