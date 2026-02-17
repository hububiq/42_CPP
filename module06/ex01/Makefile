CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = serialization
INCLUDES = Serializer.hpp
SRC = Serializer.cpp main.cpp
OBJ = ${SRC:.cpp=.o}
RM = -rm -f

all: ${NAME}

%.o: $.cpp ${INCLUDES}
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${FLAGS} $^ -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all 