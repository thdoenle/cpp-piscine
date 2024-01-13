NAME	= ex01
SRCS	= main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJS	= $(SRCS:%.cpp=%.o)
HEADERS	= Animal.hpp Dog.hpp Cat.hpp Brain.hpp

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