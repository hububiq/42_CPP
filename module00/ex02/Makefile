CC = c++
NAME = newjob
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = Account.hpp
SRC = Account.cpp tests.cpp
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