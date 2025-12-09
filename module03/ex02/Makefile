CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = fragtrap
INCLUDES = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
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