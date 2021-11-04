/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 22:43:53 by lcouto            #+#    #+#             */
/*   Updated: 2021/11/04 01:40:33 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <Contact.hpp>

class	PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_insertionIndex;

	public:
		void	search(void);
		
		PhoneBook(void);
		~PhoneBook(void);
};

#endif