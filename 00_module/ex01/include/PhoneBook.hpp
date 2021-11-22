/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:43:53 by lcouto            #+#    #+#             */
/*   Updated: 2021/11/04 17:43:06 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact		_contacts[8];
		int			_insertionIndex;

		void		_printContact(int index);
		std::string	_truncateLine(std::string line);
		void		_printFullContactInfo(int index);
		void		_fetchByIndex(void);

	public:
		void	search(void);
		void	add(void);
		void	exit(void);
		
		PhoneBook(void);
		~PhoneBook(void);
};

#endif