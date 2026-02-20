NAME = phonebook

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = PhoneBook.cpp\
Contact.cpp\
main.cpp

OBJS = $(SRCS:.cpp=.o)
all: $(NAME)

$(NAME) : $(OBJS) 
	c++ $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re