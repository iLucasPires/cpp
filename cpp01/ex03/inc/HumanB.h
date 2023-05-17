/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 02:02:37 by lucas             #+#    #+#             */
/*   Updated: 2023/05/15 14:01:35 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANB_H__
#define __HUMANB_H__

#include "Weapon.h"

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void attack(void) const;
        void setWeapon(Weapon &weapon);


    private:
        std::string _name;
        Weapon *_weapon;
};


#endif // __HUMANB_H__
