# Compiler
CC = cc

# Flags
CFLAGS = -Wall -Werror -Wextra -g -I/usr/include -Imlx -Im -O3

# Source files
SRC = fdf.c points.c utils/get_next_line.c utils/get_next_line_utils.c \
	utils/ft_split.c read_map.c

# Objects
OBJ = $(SRC:.c=.o)

# Program name
NAME = fdf

# Include mlx
MLXDIR = /nfs/homes/luide-ca/common-core-github/fdf/mlx
MLXLIB = $(MLXDIR)/libmlx.a

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLXLIB) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
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


