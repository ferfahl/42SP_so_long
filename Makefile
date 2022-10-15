#####################INPUTS#####################

#scr functions
SRC_FILES =	close_game.c \
		destroy.c \
		open_game.c \
		main.c

#static library's name
NAME =	so_long

#directories
OBJPATH = temps
SRC_PATH = sources
LIBFT_PATH =	./libs/libft
LIBFT =			$(LIBFT_PATH)/libft.a
MLX_PATH =		./libs/minilibx-linux
MLX	 = $(MLX_PATH)/libmlx.a


#header to libft.h
INCLUDE = -I ./ -I $(LIBFT_PATH) -I $(MLX_PATH)

#compiling
CC =		gcc
FLAGS =	-Wall -Werror -Wextra -g3 -O3 #-fsanitize=leak
MLXFLAGS =	-lm -lXext -lX11

GDB = -ggdb
VAL = valgrind --trace-children=yes --leak-check=full --track-origins=yes ./$(NAME)


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

#compile so_long
$(OBJPATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#rule name - make so_long
$(NAME): $(OBJ) $(LIBFT)
		cc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(MLXFLAGS)

#complile libft
$(LIBFT):
		make -C ./libs/libft

#remove objects
clean:
		$(RM) $(OBJ)

#remove all
fclean: clean
		$(RM) $(NAME) $(RM_DIR) $(OBJPATH)

#clear all
re: fclean all

#avoids double inclusion
.PHONY: all clean fclean re

git:
		git add .
		git commit -m "$(m)"
		git push
