/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TypeConversion.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 00:06:24 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/05 02:31:33 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TYPECONVERSION_HPP
# define TYPECONVERSION_HPP

# include <iostream>

class TypeConversion
{
    private:
        std::string m_inputString;
        std::string m_type;

        TypeConversion  getInputString(void);
        TypeConversion  getType(void);

    public:
        TypeConversion(std::string inputString);
        ~TypeConversion(void);
        TypeConversion(TypeConversion const &instancedObject);
        TypeConversion &operator=(TypeConversion const &rightHandSide);
};

std::ostream &operator<<(std::ostream &output, TypeConversion const &instance);

#endif
