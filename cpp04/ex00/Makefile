NAME = program

BIN_DIR = bin

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
BUILD_OBJS = $(SRCS:%.cpp=$(BIN_DIR)/%.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(BUILD_OBJS)
	@c++ $(CFLAGS) $(BUILD_OBJS) -o $@
	@echo "link $@"

$(BIN_DIR)/%.o: %.cpp
	@mkdir -p $(BIN_DIR)
	@c++ $(CFLAGS) -c $< -o $@
	@echo "compile $<"

clean:
	@rm -f $(BUILD_OBJS)
	@echo "clean"

fclean: clean
	@rm -rf $(BIN_DIR)
	@rm -f $(NAME) $(BUILD_OBJS)
	@echo "fclean"

re: fclean all

.PHONY: all clean fclean re
