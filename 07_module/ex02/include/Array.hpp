/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:44:50 by lcouto            #+#    #+#             */
/*   Updated: 2022/07/18 22:12:57 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
    private:
        unsigned int    m_n;
        T               *m_content;
    public:
        Array(void): m_n(0), m_content(0) {};
        Array(unsigned int n)
        {
            this->m_n = n;
            this->m_content = new T[n]();
        }
        ~Array(void) {if (this->m_content) delete[] this->m_content;};
        Array(Array const &instance): m_n(instance.getSize()), m_content(new T[this->m_n]())
		{
			*this = instance;
		};
		Array &operator=(Array const &rightHandSide)
		{
			try
			{
				for(unsigned int i = 0; i < rightHandSide.getSize(); i++)
				{
					if (i >= this->m_n)
						throw OutsideArrayException();
					this->m_content[i] = rightHandSide.m_content[i];
				}
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			return (*this);
		}
        unsigned int getSize(void) const {return(this->m_n);};

        T &operator[](unsigned int i) const
		{
			if ((i < 0) || (i >= this->m_n))
				throw OutsideArrayException();
			return (m_content[i]);
		}
    
        class OutsideArrayException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("\e[0;31mException: Operation is outside the array's boundaries\e[0m");
                }
        };
};

#endif
