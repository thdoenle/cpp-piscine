NAME	= ex00
SRCS	= main.cpp
OBJS	= $(SRCS:%.cpp=%.o)
HEADERS	= template.hpp

CXX		= c++
CPPFLAGS= -Wall -Werror -Wextra -std=c++98

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