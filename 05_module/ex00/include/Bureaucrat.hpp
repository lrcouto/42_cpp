/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:56:15 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/25 01:54:32 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    protected:
        std::string const m_name;
        unsigned int m_grade;
    
    public:
        Bureaucrat(void);
        Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat const &instancedObject);
        Bureaucrat &operator=(Bureaucrat const &rightHandSide);

        std::string	getName(void) const;
		int			getGrade(void) const;
		void		incrementGrade(void);
		void		decrementGrade(void);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("\033[1;31mException: Bureaucrat grade is too high - Maximum is 1.\033[0m");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("\033[1;31mException: Bureaucrat grade is too low - Minimum is 150\033[0m");
                }
        };
};

std::ostream &operator<<(std::ostream &outputFile, Bureaucrat const &i);

#endif
