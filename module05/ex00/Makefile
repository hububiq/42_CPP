CC = c++
NAME = bureaucrat
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = Bureaucrat.hpp
SRC = Bureaucrat.cpp GradeTooLowException.cpp GradeTooHighException.cpp main.cpp
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



