/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:46:35 by fmaurer           #+#    #+#             */
/*   Updated: 2025/09/26 11:22:08 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "utils.hpp"

#include <iostream>

int main()
{
    print_test_section_header("basic stuff");
    {
        print_test_topic("tryting things...");
        {
            Bureaucrat            at("at", 42);
            ShrubberyCreationForm s("bla");
            std::cout << s << std::endl;
            s.beSigned(at);
            std::cout << s << std::endl;
            at.executeForm(s);
        }
    }

    return (0);
}
