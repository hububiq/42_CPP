CC = c++
NAME = span
INCLUDES = Span.hpp
FLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Span.cpp main.cpp 
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
