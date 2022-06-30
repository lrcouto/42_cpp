/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:59:33 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/30 02:32:04 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.hpp"

class Intern
{
    private:
        Form        *createShrubberyCreationForm(std::string target);
        Form        *createRobotomyRequestForm(std::string target);
        Form        *createPresidentialPardonForm(std::string target);

    public:
        Intern(void);
        ~Intern(void);
        Intern(Intern const& instancedObject);
        Intern	&operator=(Intern const &rightHandSide);

        Form	*makeForm(std::string formName, std::string target);
    
        class FormDoesntExistException : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return ("\033[1;31mException: couldn't find the requested form\033[0m");
                }
        };
};

#endif
