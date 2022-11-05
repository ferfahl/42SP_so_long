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

#static library's name
NAME =	so_long

#directories
OBJPATH = temps
MANDATORY_PATH = sources
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
OBJ_MANDATORY = $(MANDATORY_FILES:%.c=$(OBJPATH)/%.o)

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
$(NAME): $(LIBFT) $(MLX) $(OBJ_MANDATORY) $(OBJ_BACK)
		cc $(FLAGS) -o $(NAME) $(OBJ_MANDATORY) $(LIBFT) $(MLX) $(MLXFLAGS)

#compile MANDATORY
$(OBJPATH)/%.o: $(MANDATORY_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#mcheck
mem:
		$(VAL) ./$(NAME) $(MAP)

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
