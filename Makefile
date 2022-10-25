#####################INPUTS#####################

#scr functions
FRONT_FILES =	click_hook.c \
		destroy.c \
		open_game.c \
		start_window.c \
		key_hook.c \
		sprites_load.c

BACK_FILES =	map.c \
		verification.c \
		path.c \
		main.c

#static library's name
NAME =	so_long

#directories
OBJPATH = temps
FRONT_PATH = sources
BACK_PATH = verification
LIBFT_PATH =	./libs/libft
LIBFT =			$(LIBFT_PATH)/libft.a
MLX_PATH =		./libs/minilibx-linux
MLX	 = $(MLX_PATH)/libmlx.a

MAP = ./assets/maps/test.ber

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
OBJ_FRONT = $(FRONT_FILES:%.c=$(OBJPATH)/%.o)

OBJ_BACK = $(BACK_FILES:%.c=$(OBJPATH)/%.o)

#####################RULES#####################

#make
all: $(OBJPATH) $(NAME)

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
$(NAME): $(LIBFT) $(MLX) $(OBJ_FRONT) $(OBJ_BACK)
		cc $(FLAGS) -o $(NAME) $(OBJ_BACK) $(OBJ_FRONT) $(LIBFT) $(MLX) $(MLXFLAGS)

#compile front
$(OBJPATH)/%.o: $(FRONT_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#compile back
$(OBJPATH)/%.o: $(BACK_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)
#mcheck
mem:
		$(VAL) --show-leak-kinds=all ./$(NAME) $(MAP)

#run so_long
so:
		make && clear && ./so_long $(MAP)

#remove objects
clean:
		make clean -C $(LIBFT_PATH)
		$(RM) $(OBJ)

#remove all
fclean: clean
		make fclean -C $(LIBFT_PATH)
		$(RM) $(NAME) $(RM_DIR) $(OBJPATH)

#clear all
re: fclean all

#avoids double inclusion
.PHONY: all clean fclean re

git:
		git add .
		git commit -m "$(m)"
		git push
