/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 21:05:18 by fmaurer           #+#    #+#             */
/*   Updated: 2025/09/08 21:26:50 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <cstdint>
#include <stdexcept>
#include <string>

class Bureaucrat
{
  private:
    uint8_t           grade;
    const std::string name;

  public:
    // OCF
    Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // exceptions...  chossing logic_error because so far there is no user input
    // during runtime involved. therefore these exceptions must be raised by
    // code we write (specifying too high or too low grades)
    class GradeTooHighException: public std::logic_error
    {
      public:
        // FIXME move this to the cpp file as it is a function definition
        // strictly speaking?!
        GradeTooHighException(const std::string msg): std::logic_error(msg) {};
    };

    class GradeTooLowException: public std::logic_error
    {
      public:
        // FIXME move this to the cpp file as it is a function definition
        // strictly speaking?!
        GradeTooLowException(const std::string msg): std::logic_error(msg) {};
    };

    // other funky funx
};

#endif
