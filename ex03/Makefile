# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmaurer <fmaurer42@posteo.de>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/01 11:45:58 by fmaurer           #+#    #+#              #
#    Updated: 2025/10/08 12:04:25 by fmaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Simple skeleton Makefile

NAME 		= cpp05-03

VPATH 	= .
SRC			= main.cpp Bureaucrat.cpp AForm.cpp utils.cpp \
					ShrubberyCreationForm.cpp RobotomyRequestForm.cpp \
					PresidentialPardonForm.cpp Intern.cpp
OBJDIR	= obj
OBJS		= $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRC))
CFLAGS	= -Wall -Werror -Wextra -std=c++98
CPP			= c++
HDR			= Bureaucrat.hpp AForm.hpp utils.hpp ShrubberyCreationForm.hpp \
					RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

# will never try to compile HDR or any other prequesite specified after `%.c`.
# this is because the `%.o` and matched against all .c-files in the current dir.
$(OBJDIR)/%.o: %.cpp $(HDR) | $(OBJDIR)
	$(CPP) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) -o $@ $^

nodebug: CFLAGS += -DDEBUG=0
nodebug:
	$(CPP) $(CFLAGS) -o $(NAME) $(SRC)

debug: CFLAGS += -g
debug:
	$(CPP) $(CFLAGS) -o $(NAME) $(SRC)

bear: fclean
	bear -- make

run: nodebug
	./$(NAME)

run-debug: debug
	./$(NAME)

run-val: nodebug
	valgrind -- ./$(NAME)

clean:
	rm -rf $(OBJDIR)
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re nodebug debug bear run run-debug run-val
