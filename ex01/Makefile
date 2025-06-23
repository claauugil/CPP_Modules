SRC = Phonebook.cpp Contact.cpp Phonebook_utils.cpp main.cpp
NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
OBJS = $(SRC:.cpp=.o)

all: $(NAME)

includes: Phonebook_utils.hpp Phonebook.hpp Contact.hpp

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@echo "fully cleaned"

re: fclean all