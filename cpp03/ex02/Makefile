NAME = claptrap

CFLAGS = -Wall -Wextra -Werror -std=c++98 

SRCS =ClapTrap.cpp\
main.cpp\
ScavTrap.cpp\
FragTrap.cpp


OBJS = $(SRCS:.cpp=.o)
all: $(NAME)

%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) 
	c++ $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re