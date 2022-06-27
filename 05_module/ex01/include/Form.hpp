/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:42:06 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/27 01:42:09 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const   m_name;
        int const           m_gradeRequiredToExecute;
        int const           m_gradeRequiredToSign;
        bool                m_isFormSigned;

    public:
        Form(void);
        Form(std::string name, int gradeRequiredToExecute, int gradeRequiredToSign);
		~Form(void);
		Form(Form const &instancedObject);
        Form &operator=(Form const &rightHandSide);

        void        validateGrade(int grade) const;
		std::string	getName(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		int			getSignedStatus(void) const;
		void		beSigned(Bureaucrat signatory);
    
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("\033[1;31mException: Form grade is too high - Maximum is 1.\033[0m");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("\033[1;31mException: Form grade is too low - Minimum is 150\033[0m");
                }
        };

        class RequiredGradeToSignTooLowException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("\033[1;31mException: Bureaucrat grade is too low to sign this form\033[0m");
                }
        };

        class FormAlreadySignedException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("\033[1;31mException: this form has already been signed\033[0m");
                }
        };
};

std::ostream &operator<<(std::ostream &output, Form const &instance);

#endif
