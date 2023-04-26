NAME = megaphone

BUILD_DIR = build

SRCS = megaphone.cpp
BUILD_OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(BUILD_OBJS)
	@c++ $(CFLAGS) $(BUILD_OBJS) -o $@
	@echo "link $@"

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(BUILD_DIR)
	@c++ $(CFLAGS) -c $< -o $@
	@echo "compile $<"

clean:
	@rm -f $(BUILD_OBJS)
	@echo "clean"

fclean: clean
	@rm -rf $(BUILD_DIR)
	@rm -f $(NAME) $(BUILD_OBJS)
	@echo "fclean"

re: fclean all

.PHONY: all clean fclean re
