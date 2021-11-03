/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:45:35 by lcouto            #+#    #+#             */
/*   Updated: 2021/11/03 18:42:44 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_phoneNumber;
		std::string	_nickname;
		std::string	_darkestSecret;

	public:
		void setFirstName(std::string buffer);
		void setLastName(std::string buffer);
		void setNickName(std::string buffer);
		void setPhoneNumber(std::string buffer);
		void setDarkestSecret(std::string buffer);

		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);

		Contact(void);
		~Contact(void);
};

#endif