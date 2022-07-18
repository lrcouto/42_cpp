/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:28:10 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/18 02:44:30 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void    swap(T &first, T &second)
{
    T temp;

    temp = first;
    first = second;
    second = temp;
}

template<typename T>
T   min(T first, T second)
{
    if (first < second)
        return (first);
    return (second);
}

template<typename T>
T max(T first, T second)
{
    if (first > second)
        return (first);
    return (second);
}

#endif
