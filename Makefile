#####################INPUTS#####################

#scr functions
SRC_FILES =	close_game.c \
		destroy.c \
		open_game.c \
		main.c \
		map.c

#static library's name
NAME =	so_long

#directories
OBJPATH = temps
SRC_PATH = sources
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
OBJ = $(SRC_FILES:%.c=$(OBJPATH)/%.o)

#####################RULES#####################

#make
all: $(OBJPATH) $(NAME)

#make folder for temps
$(OBJPATH):
		@mkdir -p $(OBJPATH)

#make libft
$(LIBFT): 
		make -C $(LIBFT_PATH)

#rule name - make so_long
$(NAME): $(LIBFT) $(OBJ) 
		cc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(MLXFLAGS)

#compile so_long
$(OBJPATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#mcheck
mem:
		valgrind ./$(NAME) $(MAP)

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
