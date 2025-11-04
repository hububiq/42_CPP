CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook
RM = rm -f
INCLUDES = Phonebook.Class.hpp Contact.class.hpp
CPPSRC = Phonebook.Class.cpp Contact.class.cpp main.cpp
OBJ = ${CPPSRC:.cpp=.o}

all: ${NAME}

%.o: %.cpp ${INCLUDES}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

RE:
	fclean all