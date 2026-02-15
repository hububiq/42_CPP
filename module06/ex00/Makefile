CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = types
INCLUDES = .hpp
SRC = .cpp
OBJ = ${SRC:.cpp=.o}
RM = -rm -f

all: ${NAME}

%.o: $.cpp ${INCLUDES}
	${CC} ${FLAGS} -c $< -o $@

%{NAME}: ${OBJ}
	${CC} ${FLAGS} $^ -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all 