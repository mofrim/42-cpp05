/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:56:17 by fmaurer           #+#    #+#             */
/*   Updated: 2025/09/25 14:42:12 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <stdexcept>
#include <string>

class Form {
  private:
    static long        _noname_form_cnt;
    const std::string  _name;
    bool               _signed;
    const unsigned int _sign_grade;
    const unsigned int _exec_grade;

    // making this private as we need to have it BUT there is no sense in
    // assigning Forms to eachother if they have only const attributes execept
    // the `_signed` bool.
    Form& operator=(const Form& other);

  public:
    // the rest of OCF
    Form();
    Form(const Form& other);
    ~Form();

    Form(const std::string& name,
         const long&        sign_grade,
         const long&        exec_grade);

    // the exceptions
    class GradeTooHighException: public std::logic_error {
      public:
        GradeTooHighException(const std::string msg);
    };
    class GradeTooLowException: public std::logic_error {
      public:
        GradeTooLowException(const std::string msg);
    };

    void beSigned(const Bureaucrat& b);

    // getters
    unsigned int getSignGrade() const;
    unsigned int getExecGrade() const;
    std::string  getName() const;
    bool         isSigned() const;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
