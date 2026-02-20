NAME = animal

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =main.cpp\
Animal.cpp\
Dog.cpp\
Cat.cpp\
WrongCat.cpp\
WrongAnimal.cpp

OBJS = $(SRCS:.cpp=.o)
all: $(NAME)


$(NAME) : $(OBJS) 
	c++ $(CFLAGS) $(OBJS) -o $(NAME)
	 
%.o: %.cpp
	c++ $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re