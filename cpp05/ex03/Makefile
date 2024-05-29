CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 
RM = rm -f
FILES = Bureaucrat.cpp main.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp \
ShrubberyCreationForm.cpp Intern.cpp

OBJ = $(FILES:.cpp=.o)
NAME = ex03

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
