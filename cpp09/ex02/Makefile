NAME = PmergeMe

OBJ_DIR = obj

SRCS = main.cpp PmergeMe.cpp
BUILD_OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

all: $(NAME)

$(NAME): $(BUILD_OBJS)
	@c++ $(CFLAGS) $(BUILD_OBJS) -o $@ -I.
	@echo "link $@"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@c++ $(CFLAGS) -c $< -o $@ -I.
	@echo "compile $<"

clean:
	@rm -f $(BUILD_OBJS)
	@echo "clean"

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME) $(BUILD_OBJS)
	@echo "fclean"

re: fclean all

.PHONY: all clean fclean r
