/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:10:08 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/18 21:37:39 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstdlib>
# include <unistd.h>

template<typename T>
void iter(T *address, size_t len, void (fn)(T &element))
{
	for(size_t i = 0; i < len; i++)
		fn(address[i]);
}

template<typename T>
void iter(T const *address, size_t len, void (fn)(T const &element))
{
	for(size_t i = 0; i < len; i++)
		fn(address[i]);
}

template<typename T>
void    inc(T &element)
{
    element += 1;
}

template<typename T>
void    dec(T &element)
{
    element -= 1;
}

template<typename T>
void    print(T &element)
{
    std::cout << element << " ";
}

template<typename T>
void    rainbowfy(T &element)
{
    std::srand((unsigned int)time(NULL));
    std::string colors[8] = {"\e[0;30m", "\e[0;31m", "\e[0;32m", "\e[0;33m", "\e[0;34m", "\e[0;35m", "\e[0;36m", "\e[0;37m"};
	int random = rand() % 8;

    std::cout << colors[random] << element << " " << "\e[0m";
    usleep(1000000);
}

#endif
