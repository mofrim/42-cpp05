/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:57:09 by fmaurer           #+#    #+#             */
/*   Updated: 2025/09/26 11:24:24 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "utils.hpp"

#include <iostream>

long AForm::_noname_form_cnt = 0;

AForm::AForm()
    : _name("noname" + toString(this->_noname_form_cnt))
    , _signed(false)
    , _sign_grade(150)
    , _exec_grade(150)
{
    dbg_msg(this->_name, "Default constructor called");
}

AForm::AForm(const AForm& other)
    : _name(other._name)
    , _signed(other._signed)
    , _sign_grade(other._sign_grade)
    , _exec_grade(other._exec_grade)
{
    dbg_msg(this->_name, "Copy constructor called");
}

// only for protocol
AForm& AForm::operator=(const AForm& other)
{
    (void)other;
    return (*this);
};

AForm::~AForm() {}

AForm::AForm(const std::string& name, const long& sign_grade,
             const long& exec_grade)
    : _name(name)
    , _signed(false)
    , _sign_grade(sign_grade)
    , _exec_grade(exec_grade)
{
    if (1 > sign_grade)
    {
        throw(AForm::GradeTooHighException("Signing grade < 1 is to high."));
    }
    else if (150 < sign_grade)
    {
        throw(AForm::GradeTooLowException("Signing grade > 150 is to low."));
    }
    else if (1 > exec_grade)
    {
        throw(AForm::GradeTooHighException("Execution grade < 1 is to high."));
    }
    else if (150 < exec_grade)
    {
        throw(AForm::GradeTooLowException("Execution grade > 150 is to low."));
    }
    dbg_msg(this->_name, "Direct constructor called");
}

AForm::GradeTooHighException::GradeTooHighException(const std::string msg)
    : std::logic_error("AForm::GradeTooHighException: " + msg)
{
}

AForm::GradeTooLowException::GradeTooLowException(const std::string msg)
    : std::logic_error("AForm::GradeTooLowException: " + msg)
{
}

AForm::FormNotSignedException::FormNotSignedException(const std::string msg)
    : std::logic_error("AForm::FormNotSignedException: " + msg)
{
}

AForm::FormActionFailedException::FormActionFailedException(
    const std::string msg)
    : std::logic_error("AForm::FormActionFailedException: " + msg)
{
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= this->_sign_grade)
        this->_signed = true;
    else if (b.getGrade() > this->_sign_grade)
        throw(AForm::GradeTooLowException(
            "Bureaucrat's grade (" + toString(b.getGrade())
            + ") too low for this form's sign_grade ("
            + toString(this->_sign_grade) + ")"));
}

unsigned int AForm::getSignGrade() const { return (this->_sign_grade); }

unsigned int AForm::getExecGrade() const { return (this->_exec_grade); }

std::string AForm::getName() const { return (this->_name); }

bool AForm::isSigned() const { return (this->_signed); }

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "{form_name: \"" << f.getName()
       << "\", sign_grade: " << f.getSignGrade()
       << ", exec_grade: " << f.getExecGrade()
       << ", is_signed: " << f.isSigned() << "}";
    return (os);
}

// check for correct grades and signedness the finally execute the
// to-be-implemented _executeFormAction func.
bool AForm::execute(Bureaucrat const& executor) const
{
    if (!this->isSigned())
        throw(AForm::FormNotSignedException(this->_name + " not signed!"));
    if (this->getExecGrade() < executor.getGrade())
        throw(AForm::GradeTooLowException(
            "Executor" + executor.getName() + "'s grade ("
            + toString(executor.getGrade()) + ") is too low to execute "
            + this->_name));

    return (this->_executeFormAction());
}
