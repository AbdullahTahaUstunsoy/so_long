NAME := so_long

CC := cc

CFLAGS := -Wall -Wextra -Werror

SOURCE := main.c control1.c control2.c map_dfs.c create_window.c error_and_free.c display_moves.c
GNL_SRC := get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
LIBFT := libft/libft.a
FT_PRINTF := ft_printf/libftprintf.a
MLX_DIR := minilibx-linux
MLX := minilibx-linux/libmlx_Linux.a
LIBRARY := -I minilibx-linux -L minilibx-linux -lmlx -lX11 -lXext -lm

OBJS = $(SOURCE:.c=.o)
GNL_OBJS = $(GNL_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(LIBFT) $(FT_PRINTF) $(MLX)
		@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) $(LIBRARY) -o $(NAME)

%.o: %.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		@$(MAKE) -C libft

$(FT_PRINTF):
		@$(MAKE) -C ft_printf

$(MLX):
		@$(MAKE) -C $(MLX_DIR)

clean:
		@rm -rf $(OBJS) $(GNL_OBJS)
		@$(MAKE) -C libft clean
		@$(MAKE) -C ft_printf clean
		@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
		@rm -rf $(NAME)
		@$(MAKE) -C libft fclean 
		@$(MAKE) -C ft_printf fclean 

re: fclean all

.PHONY: all clean fclean re