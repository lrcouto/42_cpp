/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 22:06:12 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/17 22:36:30 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Data.hpp"
# include <stdint.h>

uintptr_t   serialize(Data* pointer)
{
	return (reinterpret_cast<uintptr_t>(pointer));
}

Data*       deserialize(uintptr_t rawBits)
{
	return (reinterpret_cast<Data*>(rawBits));
}
