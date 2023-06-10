NAME = program

OBJ_DIR = obj

SRCS = main.cpp Intern.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
BUILD_OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(BUILD_OBJS)
	@c++ $(CFLAGS) $(BUILD_OBJS) -o $@
	@echo "link $@"

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@c++ $(CFLAGS) -c $< -o $@
	@echo "compile $<"

clean:
	@rm -f $(BUILD_OBJS)
	@echo "clean"

fclean: clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME) $(BUILD_OBJS)
	@echo "fclean"

re: fclean all

.PHONY: all clean fclean re
