NAME = fractol

SRC_NAME = main.c ft_verif.c ft_help.c ft_create_picture.c ft_color_julia.c ft_color_mandelbrot.c ft_color_fractol.c \
	ft_exit.c ft_change.c ft_refresh.c ft_reset.c ft_clear_picture.c ft_iteration.c ft_mouse_hook_julia.c ft_color.c ft_print_info.c

SRC_PATH = ./srcs/

OBJ_PATH = ./objs/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH),$(SRC_NAME:.c=.o))

LIBFT_PATH = ./libft/

LIBFT = -L./libft/ -lft

MLX_SRC = mlx_in

MLX = -L./minilibx/ -lmlx

MLX_PATH = ./minilibx/

MLX_NAME = ./minilibx/libmlx.a

INC_MLX = -I./minilibx/

INC_LIBFT = -I./libft/includes/

LIBFT_NAME = ./libft/libft.a

INC_PATH = ./includes/

INC = -I./includes/

APPKIT = -framework Appkit

OPENGL = -framework Opengl

CC = clang

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX_PATH)
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) $(APPKIT) $(OPENGL) -o $(NAME)
	@echo "Create :\n$(NAME)\ndone!\n"

$(addprefix $(OBJ_PATH),%.o) : $(addprefix $(SRC_PATH),%.c)
	@mkdir -p $(OBJ_PATH) 2> /dev/null
	@$(CC) $(CFLAGS) -c $< $(INC) $(INC_LIBFT) $(INC_MLX) -o $@

clean:
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)
	@rm -rf $(OBJ_PATH)
	@echo "Delete :\n$(OBJ)\ndone!!\n"

fclean: clean
	@rm -rf $(MLX_NAME)
	@rm -rf $(OBJ_PATH)
	@rm -rf $(NAME)
	@rm -rf $(LIBFT_NAME)
	@echo "Delete :\n$(NAME)\ndone!!\n"

re: fclean all

norme:
	@norminette $(SRC_PATH) $(INC_PATH)
	@make norme -C $(LIBFT_PATH)
