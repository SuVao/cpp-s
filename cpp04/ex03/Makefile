CC = c++
NAME = AMatirial
SRC = main.cpp \
	  AMateria.cpp \
	  Ice.cpp \
	  Cure.cpp	\
	  ICharacter.cpp \
	  IMaterialSource.cpp
OBJ = $(SRC:.cpp=.o)
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
