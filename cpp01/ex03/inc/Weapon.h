/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:54:07 by lucas             #+#    #+#             */
/*   Updated: 2023/05/15 14:01:07 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <iostream>

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon(void);

        void setType(std::string type);
        const std::string &getType(void) const;

    private:
        std::string _type;
};

#endif // __WEAPON_H__
