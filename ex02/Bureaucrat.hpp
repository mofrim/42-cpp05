/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:05:18 by fmaurer           #+#    #+#             */
/*   Updated: 2025/09/26 09:38:57 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>

class AForm;

class Bureaucrat {
  private:
    static long       _noname_bureaucrat_count;
    unsigned int      _grade;
    const std::string _name;

  public:
    // OCF
    Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    Bureaucrat(const std::string& name, const long& grade);

    class GradeTooHighException: public std::logic_error {
      public:
        GradeTooHighException(const std::string msg);
    };
    class GradeTooLowException: public std::logic_error {
      public:
        GradeTooLowException(const std::string msg);
    };

    Bureaucrat  operator++(int);
    Bureaucrat& operator++();
    Bureaucrat  operator--(int);
    Bureaucrat& operator--();

    unsigned int       getGrade() const;
    const std::string& getName() const;
    void               setGrade(const long& grade);
    void               signForm(AForm& f) const;
    void               executeForm(const AForm& f) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
