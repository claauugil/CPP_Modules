/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:27:11 by claudia           #+#    #+#             */
/*   Updated: 2025/06/17 17:07:29 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact{
    private:
        std::string _fst_name;
        std::string _lst_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _secret;

    public:
        Contact(void);
        ~Contact(void);
    
        // get and set
        std::string get_fst_name(void)const;
        std::string get_lst_name(void)const;
        std::string get_nickname(void)const;
        std::string get_phone_num(void)const;
        std::string get_secret(void)const;
        void        set_fst_name(std::string str);
        void        set_lname(std::string str);
        void        set_nick_name(std::string str);
        void        set_phone_num(std::string str);
        void        set_secret(std::string str);
};

#endif