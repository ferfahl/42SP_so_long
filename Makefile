#####################INPUTS#####################

#scr functions
SRC_FILES =


#static library's name
NAME =	so_long.a

#directories
LIBFT_PATH =	./libs/libft
LIBFT =			$(LIBFT_PATH)/libft.a
MLX_PATH =		./libs/minilibx-linux
MLX	 = $(MLX_PATH)/libmlx.a
OBJPATH = temps

#header to libft.h
INCLUDE = -I ./ -I $(LIBFT_PATH) -I $(MLX_PATH)

#compiling
CC =		gcc
FLAGS =	-Wall -Werror -Wextra -g -O3 #-fsanitize=leak
MLXFLAGS =	-lm -lXext -lX11

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

#tester
main:
		make -C ./libs/libft
		cc $(FLAGS) main.c $(LIBFT) $(MLX) $(INCLUDE) $(MLXFLAGS) 

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
		git commit -m 