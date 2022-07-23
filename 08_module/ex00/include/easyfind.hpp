/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:18:26 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/23 16:08:26 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <map>

class TargetNotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("\e[0;31mException: target number not found in this collection\e[0m");
		}
};

template<typename T>
typename T::iterator easyfind(T &container, int number)
{
	typename T::iterator target = std::find(container.begin(), container.end(), number);
	if (target == container.end())
		throw TargetNotFoundException();
	return (target);
}

template<typename keyT, typename valT>
typename std::map<keyT, valT>::iterator easyfind(std::map<keyT, valT> &container, int value)
{
	typename std::map<keyT, valT>::iterator target = container.begin();
	while (target != container.end())
    {
		if (target->second == value)
			return (target);
		target++;
    }
	throw TargetNotFoundException();
}

#endif
