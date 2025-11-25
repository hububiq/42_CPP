CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = Weapon.hpp HumanA.hpp HumanB.hpp
NAME = violence
SRC = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp 
OBJ = ${SRC:.cpp=.o}
RM = rm -f

all: ${NAME}

%.o: %.o ${INCLUDES}
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${FLAGS} $< -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all