/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 01:01:30 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/17 21:33:44 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed
{
	private:
		int 				m_rawBits;
		static const int	m_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed(void);
		Fixed(Fixed const &instancedObject);
		Fixed &operator=(Fixed const &rightHandSide);
		
		void	setRawBits(int const rawBits);
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &outputFile, Fixed const &value);

#endif

//                                           /
//                                    ,~~   /
//                                   <=)  _/_
//                               /I\.="==.{>
//         .-""-.                \I/-\T/-'
//        ;  .-. ;      oo           /_\
//     _.('.__.' :-..__//           // \\_
//_;_i".._'-.__.'_.._.-"__;_;_;;__ _I___ /__;_;_;;____