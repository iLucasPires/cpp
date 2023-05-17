/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 00:53:42 by lucas             #+#    #+#             */
/*   Updated: 2023/05/15 14:01:38 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HUMANA_H__
#define __HUMANA_H__

#include "Weapon.h"

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void attack(void) const;

    private:
        std::string const _name;
        Weapon &_weapon;
};

#endif // __HUMANA_H__
