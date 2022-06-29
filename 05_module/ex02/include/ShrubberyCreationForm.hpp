/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 20:46:55 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/29 02:44:32 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
    private:
        bool					execute(Bureaucrat const &executor) const;

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const& instance);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rightHandSide);
};

std::ostream &operator<<(std::ostream &output, ShrubberyCreationForm const &instance);

#endif
