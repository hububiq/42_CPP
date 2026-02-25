CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = array
SRC = main.cpp
INCLUDES = Array.hpp Array.tpp
OBJ = ${SRC:.cpp=.o}
RM = rm -f

all: ${NAME}

%.o: %.c ${INCLUDES}
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${FLAGS} $^ -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all 