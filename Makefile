#####################INPUTS#####################

#scr functions
MANDATORY_FILES =	click_hook.c \
		destroy.c \
		open_game.c \
		start_window.c \
		key_hook.c \
		sprites_load.c \
		map.c \
		verification.c \
		path.c \
		main.c

BONUS_FILES =	click_hook_bonus.c \
		destroy_bonus.c \
		6_open_game_bonus.c \
		5_start_window_bonus.c \
		9_key_hook_bonus.c \
		8_sprites_load_bonus.c \
		7_xpm_load.c \
		3_map_bonus.c \
		2_verification_bonus.c \
		4_path_bonus.c \
		1_main_bonus.c \
		villain_moves.c

#static library's name
NAME =	so_long
B_NAME = so_long_bonus

#directories
OBJPATH = temps
MANDATORY_PATH = sources
BONUS_PATH = bonus
LIBFT_PATH =	./libs/libft
LIBFT =			$(LIBFT_PATH)/libft.a
MLX_PATH =		./libs/minilibx-linux
MLX	 = $(MLX_PATH)/libmlx.a

MAP = ./assets/maps/test.ber
BMAP = ./assets/maps/bonus_map1.ber

#header to libft.h
INCLUDE = -I ./ -I $(LIBFT_PATH) -I $(MLX_PATH)

#compiling
CC =		gcc
FLAGS =	-Wall -Werror -Wextra -g3 -O3 #-fsanitize=leak
MLXFLAGS =	-lm -lXext -lX11
GDB = -ggdb
VAL = valgrind --leak-check=full --track-origins=yes

# clean
RM =		-rm -f
RM_DIR =	rm -rf

#tranform into .o
OBJ_MANDATORY = $(MANDATORY_FILES:%.c=$(OBJPATH)/%.o)
OBJ_BONUS = $(BONUS_FILES:%.c=$(OBJPATH)/%.o)

#####################RULES#####################

#make
all: $(OBJPATH) $(NAME)

#make bonus
bonus: $(OBJPATH) $(B_NAME)

#make folder for temps
$(OBJPATH):
		@mkdir -p $(OBJPATH)

#make libft
$(LIBFT):
		make -C $(LIBFT_PATH)

#make mlx
$(MLX):
		make -C $(MLX_PATH)

#rule name - make so_long
$(NAME): $(LIBFT) $(MLX) $(OBJ_MANDATORY)
		cc $(FLAGS) -o $(NAME) $(OBJ_MANDATORY) $(LIBFT) $(MLX) $(MLXFLAGS)

#rule name - make so_long_bonus
$(B_NAME): $(LIBFT) $(MLX) $(OBJ_BONUS)
		cc $(FLAGS) -o $(B_NAME) $(OBJ_BONUS) $(LIBFT) $(MLX) $(MLXFLAGS)

#compile MANDATORY
$(OBJPATH)/%.o: $(MANDATORY_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#compile BONUS
$(OBJPATH)/%.o: $(BONUS_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#mcheck
mem:
		$(VAL) ./$(NAME) $(MAP)

#mcheck_bonus
bmem:
		$(VAL) ./$(B_NAME) $(BMAP)

#run so_long
so:
		make && clear && ./$(NAME) $(MAP)

#run so_long_bonus
so_bonus:
		make && clear && ./$(B_NAME) $(BMAP)

#remove objects
clean:
		make clean -C $(LIBFT_PATH)
		$(RM) $(OBJ_MANDATORY) $(OBJ_BONUS)

#remove all
fclean: clean
		make fclean -C $(LIBFT_PATH)
		$(RM) $(NAME) $(B_NAME) $(RM_DIR) $(OBJPATH)

#clear all
re: fclean all

#avoids double inclusion
.PHONY: all clean fclean re bonus

git:
		git add .
		git commit -m "$(m)"
		git push
