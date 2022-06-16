/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:01:30 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/16 02:35:29 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int 				m_rawBits;
		static const int	m_fractionalBits;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const &instancedObject);
		Fixed &operator=(Fixed const &rightHandSide);

		void	setRawBits(int const rawBits);
		int		getRawBits(void) const;
};

#endif

//                                           /
//                                    ,~~   /
//                                   <=)  _/_
//                               /I\.="==.{>
//         .-""-.                \I/-\T/-'
//        ;  .-. ;      oo           /_\
//     _.('.__.' :-..__//           // \\_
//_;_i".._'-.__.'_.._.-"__;_;_;;__ _I___ /__;_;_;;____