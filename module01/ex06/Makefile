CC = c++
NAME = harlFilter
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = Harl.hpp
SRC = Harl.cpp main.cpp
OBJ = ${SRC:.cpp=.o}
RM = rm -f

all: ${NAME}

%o: %.cpp ${INCLUDES}
	${CC} ${FLAGS} -o $< -c $@

${NAME}: ${OBJ}
	${CC} ${FLAGS} $^ -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all