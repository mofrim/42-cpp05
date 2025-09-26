/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:56:17 by fmaurer           #+#    #+#             */
/*   Updated: 2025/09/26 10:09:37 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

#include <stdexcept>
#include <string>

class AForm
{
private:
    static long _noname_form_cnt;
    const std::string _name;
    bool _signed;
    const unsigned int _sign_grade;
    const unsigned int _exec_grade;

    // making this private as we need to have it BUT there is no sense in
    // assigning Forms to eachother if they have only const attributes execept
    // the `_signed` bool.
    AForm& operator=(const AForm& other);

    // the one thing making this class abstract
    virtual bool _executeFormAction() const = 0;

public:
    // the rest of OCF
    AForm();
    AForm(const AForm& other);

    //
    virtual ~AForm();

    AForm(const std::string& name, const long& sign_grade,
          const long& exec_grade);

    // the exceptions
    class GradeTooHighException : public std::logic_error
    {
    public:
        GradeTooHighException(const std::string msg);
    };
    class GradeTooLowException : public std::logic_error
    {
    public:
        GradeTooLowException(const std::string msg);
    };
    class FormNotSignedException : public std::logic_error
    {
    public:
        FormNotSignedException(const std::string msg);
    };
    class FormActionFailedException : public std::logic_error
    {
    public:
        FormActionFailedException(const std::string msg);
    };

    void beSigned(const Bureaucrat& b);

    // getters
    unsigned int getSignGrade() const;
    unsigned int getExecGrade() const;
    std::string getName() const;
    bool isSigned() const;

    bool execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
