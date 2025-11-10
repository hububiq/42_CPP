CC = c++
NAME = megaphone
FLAGS = -Wall -Wextra -Werror -std=c++98
CPPSRC = megaphone.cpp
OBJ = ${CPPSRC:.cpp=.o}
RM = rm -f

all: ${NAME}

%.o: %.cpp
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

