CC = c++
NAME = Bureaucrat
SRC_DIR = src
OBJDIR = obj
ASMDIR = asm
INCDIR = inc

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -I$(INCDIR)

SRC = $(SRC_DIR)/main.cpp \
      $(SRC_DIR)/Bureaucrat.cpp \
      $(SRC_DIR)/ASMForm.cpp \
      $(SRC_DIR)/PresidentialPardonForm.cpp \
      $(SRC_DIR)/RobottomyRequestForm.cpp \
      $(SRC_DIR)/ShrubberyCreation.cpp \

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJDIR)/%.o)
ASM = $(SRC:$(SRC_DIR)/%.cpp=$(ASMDIR)/%.s)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

ass: $(ASMDIR) $(ASM)

$(OBJDIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(ASMDIR)/%.s: $(SRC_DIR)/%.cpp | $(ASMDIR)
	$(CC) -S -O2 $(CFLAGS) $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(ASMDIR):
	mkdir -p $(ASMDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME) $(ASMDIR)

re: fclean all

.PHONY: all clean fclean re ass
