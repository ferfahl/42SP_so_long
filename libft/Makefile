#####################INPUTS#####################

#libft source files original
SRC_FILES = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \

#source files gnl
GNL_FILES =	get_next_line.c \
		get_next_line_utils.c

#directories
OBJPATH = temps
SRC_PATH = original_functions
GNL_PATH = getnextline

#tranform into .o
OBJ = $(SRC_FILES:%.c=$(OBJPATH)/%.o)

OBJ_GNL = $(GNL_FILES:%.c=$(OBJPATH)/%.o)

#header source
HEADER = libft.h

#header to libft.h
INCLUDE = -I ./

#static library's name
NAME = libft.a

#for compliling
FLAGS = -Wall -Wextra -Werror
MLXFLAGS =	-lm -lXext -lX11

#remove files
RM = rm -f

#remove directory
RM_DIR = rm -Rf

#####################RULES#####################

#make libft.a
all: $(NAME)

#compile libft
$(OBJPATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#compile gnl
$(OBJPATH)/%.o: $(GNL_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#rule name - make library
$(NAME): $(OBJ) $(OBJ_GNL)
		ar -rcs $(NAME) $(OBJ) $(OBJ_GNL)

#remove objects
clean:
		$(RM) $(OBJ) $(OBJ_GNL)
#remove all
fclean: clean
		$(RM) $(NAME)
#clear all
re: fclean all

#avoids double inclusion
.PHONY: all clean fclean re
