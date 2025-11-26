CC = c++
NAME = streams
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
OBJ = ${SRC:.cpp=.o}
INCLUDES = 
RM = rm -f

all: ${NAME}

%o: %.cpp
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${FLAGS} $^ -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all