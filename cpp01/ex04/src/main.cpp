/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:51:01 by lucas             #+#    #+#             */
/*   Updated: 2023/05/16 21:53:01 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void replaceString(std::string &line, const std::string &target, const std::string &replacement)
{
    std::string::size_type pos = 0;

    while (true)
    {
        pos = line.find(target, pos);
        if (pos == std::string::npos)
            break;
        else
        {
            line.erase(pos, target.length());
            line.insert(pos, replacement);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Usage: ./replace [filename] [replaceTarget] [replaceBy]" << std::endl;
        return 0;
    }

    std::ifstream file(argv[1]);
    if (file.fail())
    {
        std::cout << "Error: file " << argv[1]
                  << " does not exist." << std::endl;
        return 0;
    }

    std::ofstream newFile((std::string(argv[1]) + ".replace").c_str());
    std::string line;

    while (std::getline(file, line))
    {
        replaceString(line, argv[2], argv[3]);
        newFile << line << '\n';
    }

    file.close();
    newFile.close();

    return 0;
}
