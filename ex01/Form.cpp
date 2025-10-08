/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 10:57:09 by fmaurer           #+#    #+#             */
/*   Updated: 2025/10/08 11:31:23 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "utils.hpp"

#include <iostream>

long Form::_noname_form_cnt = 0;

Form::Form():
  _name("noname" + toString(this->_noname_form_cnt)), _signed(false),
  _sign_grade(150), _exec_grade(150)
{
  dbg_msg(this->_name, "Default constructor called");
}

Form::Form(const Form& other):
  _name(other._name), _signed(other._signed), _sign_grade(other._sign_grade),
  _exec_grade(other._exec_grade)
{
  dbg_msg(this->_name, "Copy constructor called");
}

// only for protocol
Form& Form::operator=(const Form& other)
{
  (void)other;
  return (*this);
};

Form::Form(const std::string& name,
    const long&               sign_grade,
    const long&               exec_grade):
  _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
  if (1 > sign_grade) {
    throw(Form::GradeTooHighException("Signing grade < 1 is to high."));
  } else if (150 < sign_grade) {
    throw(Form::GradeTooLowException("Signing grade > 150 is to low."));
  } else if (1 > exec_grade) {
    throw(Form::GradeTooHighException("Execution grade < 1 is to high."));
  } else if (150 < exec_grade) {
    throw(Form::GradeTooLowException("Execution grade > 150 is to low."));
  }
  dbg_msg(this->_name, "Direct constructor called");
}

Form::~Form() { dbg_msg(this->_name, "Destructor called"); }

Form::GradeTooHighException::GradeTooHighException(const std::string msg):
  std::logic_error("Form::GradeTooHighException: " + msg)
{}

Form::GradeTooLowException::GradeTooLowException(const std::string msg):
  std::logic_error("Form::GradeTooLowException: " + msg)
{}

void Form::beSigned(const Bureaucrat& b)
{
  if (b.getGrade() <= this->_sign_grade)
    this->_signed = true;
  else if (b.getGrade() > this->_sign_grade)
    throw(Form::GradeTooLowException("Bureaucrat's grade (" +
        toString(b.getGrade()) + ") too low for this form's sign_grade (" +
        toString(this->_sign_grade) + ")"));
}

unsigned int Form::getSignGrade() const { return (this->_sign_grade); }

unsigned int Form::getExecGrade() const { return (this->_exec_grade); }

std::string Form::getName() const { return (this->_name); }

bool Form::isSigned() const { return (this->_signed); }

std::ostream& operator<<(std::ostream& os, const Form& f)
{
  os << "{form_name: \"" << f.getName()
     << "\", sign_grade: " << f.getSignGrade()
     << ", exec_grade: " << f.getExecGrade() << ", is_signed: " << f.isSigned()
     << "}";
  return (os);
}
