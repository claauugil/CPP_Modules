/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:33:45 by claudia           #+#    #+#             */
/*   Updated: 2025/06/18 15:38:31 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
//#include "Phonebook_utls.hpp"

class   Phonebook
{
    private:
        Contact _contacts[8];
        int     _index;
    public:
        Phonebook(void);
        ~Phonebook(void);
        void    add(void);
        void    search(void);
        void    print(Contact contact);

        // getters
        Contact get_contact(int index);
};

#endif