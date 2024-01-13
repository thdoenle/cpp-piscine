NAME	= ex02
SRCS	= main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS	= $(SRCS:%.cpp=%.o)
HEADERS	= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

CXX		= c++
CPPFLAGS= -Wall -Werror -Wextra -std=c++98 -g

RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CPPFLAGS) $^ -o $@

$(OBJS): $(HEADERS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all