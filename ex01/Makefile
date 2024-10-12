CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g3
RM = rm -f
FILES = main.cpp RPN.cpp 

OBJ = $(FILES:.cpp=.o)
NAME = RPN

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all