# Compiler
CC = cc

# Flags
CFLAGS = -Wall -Werror -Wextra -I$(MLXDIR)

# Source files
SRC = main.c draw_grid.c

# Objects
OBJ = $(SRC:.c=.o)

# Program name
NAME = fdf

# Include mlx
MLXDIR = /Users/luisf./Code/common-core/fdf/mlx
MLXLIB = $(MLXDIR)/libmlx.a

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLXLIB) -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Compiled $(NAME) successfully!"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< to $@"

clean:
	@rm -rf $(OBJ)
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Program cleaned."

re: fclean all
	@echo "Recompiled $(NAME)."

.PHONY: all clean fclean re


