CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 
RM = rm -f
FILES = Bureaucrat.cpp main.cpp Form.cpp

OBJ = $(FILES:.cpp=.o)
NAME = ex01

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
