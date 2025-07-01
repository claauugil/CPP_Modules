/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 18:57:53 by claudia           #+#    #+#             */
/*   Updated: 2025/06/24 17:39:35 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook_utils.hpp"

std::string fix_spaces(int n)
{
    std::string str;

    while (n--)
        str.append(" "); 
    return (str);
}

std::string fix_width(std::string str, long unsigned max)
{
    if (str.size() > max)
    {
        str.resize(max);
        str[str.size() - 1] = '.';
    }
    return (str);
}

int show_table(Contact contacts[8])
{
    char        c;
    int         i;
    std::string str;

    std::cout << " ___________________________________________ " << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;
    c = '0';
    i = 0;
    while (++c <= '8')
    {
        if (contacts[c - 1 - '0'].get_fst_name().size() && ++i)
        {
            str = c;
            str = fix_width(str, 10);
            std::cout << "|" << fix_spaces(10 - str.size()) << str;
            str = fix_width(contacts[c - 1 - '0'].get_fst_name(), 10);
            std::cout << "|" << fix_spaces(10 - str.size()) << str;
            str = fix_width(contacts[c - 1 - '0'].get_lst_name(), 10);
            std::cout << "|" << fix_spaces(10 - str.size()) << str;
            str = fix_width(contacts[c - 1 - '0'].get_nickname(), 10);
            std::cout << "|" << fix_spaces(10 - str.size()) << str;
            std::cout << "|" << std::endl;
        }
    }
    std::cout << " ------------------------------------------- " << std::endl;
    return (i);
}