/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook_utils.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:10:05 by claudia           #+#    #+#             */
/*   Updated: 2025/06/24 17:39:41 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_UTILS_HPP

#define PHONEBOOK_UTILS_HPP

#include <iostream>
#include "Contact.hpp"

std::string fix_spaces(int n);
std::string fix_width(std::string str, long unsigned max);

int show_table(Contact contacts[8]);

#endif