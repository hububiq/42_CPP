CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = bonus
INCLUDES = AMateria.hpp IMateriaSource.hpp ICharacter.hpp Cure.hpp Ice.hpp Character.hpp
SRC = AMateria.cpp Cure.cpp Ice.cpp Character.cpp
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


