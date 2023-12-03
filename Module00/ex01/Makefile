NAME	= phoneBook
SRCS	= PhoneBook.cpp Contact.cpp main.cpp utils.cpp
SRCS	:= $(SRCS:%=srcs/%)
OBJS	= $(SRCS:%.cpp=%.o)
HEADERS	= Contact.hpp PhoneBook.hpp utils.hpp
HEADERS := $(HEADERS:%=headers/%)

CXX		= c++
CPPFLAGS= -Wall -Werror -Wextra -std=c++98
HDIR	= headers/
CXXFLAGS= -I$(HDIR)

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