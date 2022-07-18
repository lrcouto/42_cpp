/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:36:13 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/17 22:35:43 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DATA_HPP
# define DATA_HPP

# include <stdint.h>

typedef struct Data
{
    double content;
} Data;

uintptr_t   serialize(Data* pointer);
Data*       deserialize(uintptr_t rawBits);

#endif
