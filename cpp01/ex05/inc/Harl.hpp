/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 22:13:31 by lucas             #+#    #+#             */
/*   Updated: 2023/05/17 00:02:43 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HARL_H__
#define __HARL_H__

#include <iostream>

class Harl
{
    private:
        void _debug(void);
        void _info(void);
        void _warning(void);
        void _error(void);
        std::string _level[4];
        void (Harl::*_ptr[4])(void);

    public:
        Harl();
        ~Harl();

        void complain(std::string level);
};

#endif // __HARL_H__
