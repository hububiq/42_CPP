CC = c++
NAME = intern
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
			PresidentialPardonForm.hpp RobotomyRequestForm.hpp Intern.hpp
SRC = Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp  \
		 RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -f

all: ${NAME}

%.o: %.cpp ${INCLUDES}
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${FLAGS} $^ -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all



