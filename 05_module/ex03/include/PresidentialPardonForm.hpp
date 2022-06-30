/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcouto <lcouto@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 03:15:58 by lcouto            #+#    #+#             */
/*   Updated: 2022/06/29 03:16:28 by lcouto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
    private:
        bool					execute(Bureaucrat const &executor) const;

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const& instance);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rightHandSide);
};

std::ostream &operator<<(std::ostream &output, PresidentialPardonForm const &instance);

#endif
