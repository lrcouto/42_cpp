/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:45:35 by lcouto            #+#    #+#             */
/*   Updated: 2021/11/04 18:20:28 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

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
		void setNickname(std::string buffer);
		void setPhoneNumber(std::string buffer);
		void setDarkestSecret(std::string buffer);

		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickname(void);
		std::string getPhoneNumber(void);
		std::string getDarkestSecret(void);

		bool isEmpty(void);

		Contact(void);
		~Contact(void);
};

#endif