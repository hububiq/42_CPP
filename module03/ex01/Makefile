CC = c++
NAME = scav
FLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = ClapTrap.hpp ScavTrap.hpp
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp
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