/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:46:35 by fmaurer           #+#    #+#             */
/*   Updated: 2025/09/29 06:32:27 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "utils.hpp"

#include <cstdlib>
#include <iostream>

int main()
{
  print_test_section_header("ShrubberyCreationForm");
  {
    print_test_topic("execution");
    {
      Bureaucrat            at("at", 42);
      ShrubberyCreationForm s("bla");
      ShrubberyCreationForm sc("everywhere");
      std::cout << s << std::endl;
      std::cout << sc << std::endl;
      s.beSigned(at);
      sc.beSigned(at);
      std::cout << s << std::endl;
      std::cout << sc << std::endl;
      at.executeForm(s);
      at.executeForm(sc);

      const std::string cmd("cat ./bla_shrubbery");
      print_test_file_header(cmd);
      if (std::system(cmd.c_str()) != 0)
        std::cout << "couldn't output shrubbery-file!" << std::endl;
      print_test_file_header("---");

      const std::string cmdc("cat ./everywhere_shrubbery");
      print_test_file_header(cmdc);
      if (std::system(cmd.c_str()) != 0)
        std::cout << "couldn't output shrubbery-file!" << std::endl;
      print_test_file_header("---");
    }

    print_test_topic("exceptions");
    {
      Bureaucrat            at0("at0", 150);
      Bureaucrat            at1("at1", 1);
      ShrubberyCreationForm s("moon");
      try {
        s.beSigned(at0);
      } catch (const AForm::GradeTooLowException& e) {
        std::cout << "cannot sign form: " << e.what() << std::endl;
      }

      try {
        at1.executeForm(s);
      } catch (const AForm::FormNotSignedException& e) {
        std::cout << "cannot execute form: " << e.what() << std::endl;
      }
    }
  }

  return (0);
}
