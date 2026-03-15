CC = c++
NAME = RPN
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = RPN.hpp
SRC = RPN.cpp main.cpp
OBJ = ${SRC:.cpp=.o}
RM = rm -f

all: ${NAME}

%.o: %.cpp ${INCLUDES}
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${FLAGS} $^ -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all
