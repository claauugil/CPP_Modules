NAME = phonebook

SRC = main.cpp Phonebook.cpp Contact.cpp Phonebook_utils.cpp

OBJ = $(SRC:.cpp=.o)


CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


GREEN = \033[1;32m
YELLOW = \033[1;33m
MAGENTA=\033[0;35m
RESET=\033[0m


%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Compiled ✅$(RESET)"

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)Fully cleaned$(RESET)"

re: fclean all

.PHONY: all clean fclean re