/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:38:44 by fmaurer           #+#    #+#             */
/*   Updated: 2025/09/25 08:28:25 by fmaurer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

#ifndef DEBUG
#define DEBUG 1
#endif

void        dbg_msg(const std::string& name, const std::string& msg);
void        newline();
void        print_test_section_header(const std::string& title);
std::string toString(long num);
void        print_test_topic(const std::string& what);

#endif
