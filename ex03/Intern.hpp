/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 07:26:51 by fmaurer           #+#    #+#             */
/*   Updated: 2025/10/08 09:26:52 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

#include <stdexcept>
#include <string>

AForm *createShrubberyCreationForm(const std::string& target);
AForm *createPresidentialPardonForm(const std::string& target);
AForm *createRobotomyRequestForm(const std::string& target);

class Intern {
  private:
    // the other part of OCF. Making them private as we will never need them.
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);

    // making this even static, because it will be the same for all interns.
    static const std::string _allowedForms[3];

    // wow! what a brainf*ck to make a constant array to functions returning
    // pointers. not exactly necessary here, but nice exercise.
    static AForm *(*const _formFuncs[3])(const std::string&);

    static const int _numOfForms;
    int              _getFormIdx(const std::string& fname) const;

  public:
    // OCF, at least the stuff we need
    Intern();
    ~Intern();

    class InexistentFormException: public std::logic_error {
      public:
        InexistentFormException(const std::string& msg);
    };

    // other funky funx
    AForm *makeForm(const std::string& fname, const std::string& target) const;
};

#endif
