CC == c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = easyfind
SRC = main.cpp
INCLUDES = easyfind.hpp easyfind.tpp
OBJ = ${SRC:.cpp=.o}
RM = rm -f 

all: ${NAME}

%.o: %.c ${INCLUDES}
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${FLAGS} $^ -o $@

clean:
	${RM} ${OBJ}

fclean:
	${RM} ${NAME}

re: fclean all