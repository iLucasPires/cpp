NAME = phoneBook

OBJ_DIR = obj
SRC_DIR = src

SRC = $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/PhoneBook.cpp \
	$(SRC_DIR)/Contact.cpp \
	$(SRC_DIR)/Util.cpp

OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	@c++ $(CFLAGS) $(OBJ) -o $@
	@echo "link $@"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	@c++ $(CFLAGS) -c $< -o $@
	@echo "compile $<"

clean:
	@rm -f $(OBJ)
	@echo "clean"

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME) $(OBJ)
	@echo "fclean"

re: fclean all

.PHONY: all clean fclean re
