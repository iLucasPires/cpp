/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lpires-n@student.42sp.org.br>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:51:01 by lucas             #+#    #+#             */
/*   Updated: 2023/05/13 16:50:55 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int main(void)
{
    std::string _string = "HI THIS IS BRAIN";
    std::string &stringREF = _string;
    std::string *stringPTR = &_string;

    std::cout << "adress: " << &_string << '\n'
              << "value: " << _string << '\n';

    std::cout << std::string(42, '-') << '\n';

    std::cout << "ref adress: " << &stringREF << '\n'
              << "ref value: " << stringREF << '\n';

    std::cout << std::string(42, '-') << '\n';

    std::cout << "pointer adress: " << &stringPTR << "\n"
              << "pointer value: " << *stringPTR << std::endl;

    return 0;
}
