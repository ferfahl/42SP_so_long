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
		ft_toupper.c

#source files other functions
OTHER_FILES =	ft_hex_itoa.c \
		ft_pointer_itoa.c \
		ft_uitoa.c \

#source files gnl
GNL_FILES =	get_next_line.c \
		get_next_line_utils.c

#source files ft_printf
PRINTF_FILES =	ft_printf.c \
		auxiliar_functions.c \
		auxiliar_functions_more.c

#header source
HEADER = libft.h

#static library's name
NAME = libft.a

#header to libft.h
INCLUDE = -I ./

#directories
OBJPATH = temps
SRC_PATH = original_functions
OTHER_PATH = other_functions
GNL_PATH = getnextline
PRINTF_PATH = printf

#tranform into .o
OBJ = $(SRC_FILES:%.c=$(OBJPATH)/%.o)
OBJ_OTHER = $(OTHER_FILES:%.c=$(OBJPATH)/%.o)
OBJ_GNL = $(GNL_FILES:%.c=$(OBJPATH)/%.o)
OBJ_PRINTF = $(PRINTF_FILES:%.c=$(OBJPATH)/%.o)

#for compliling
FLAGS = -Wall -Wextra -Werror

GDB = -ggdb
VAL = valgrind --trace-children=yes --leak-check=full --track-origins=yes ./$(NAME)

#remove
RM = rm -f
RM_DIR = rm -Rf

#####################RULES#####################

#make libft.a
all: $(OBJPATH) $(NAME)

#make folder for temps
$(OBJPATH):
		@mkdir -p $(OBJPATH)

#compile libft
$(OBJPATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#compile other functions
$(OBJPATH)/%.o: $(OTHER_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#compile gnl
$(OBJPATH)/%.o: $(GNL_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#compile ft_printf
$(OBJPATH)/%.o: $(PRINTF_PATH)/%.c $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#rule name - make library
$(NAME): $(OBJ) $(OBJ_GNL) $(OBJ_PRINTF) $(OBJ_OTHER)
		ar -rcs $(NAME) $(OBJ) $(OBJ_GNL) $(OBJ_PRINTF) $(OBJ_OTHER)

#tester
main:
		cc $(FLAGS) main.c $(NAME) && clear && ./a.out

#remove objects
clean:
		$(RM) $(OBJ) $(OBJ_GNL) $(OBJ_PRINTF) $(OBJ_OTHER)

#remove all
fclean: clean
		$(RM) $(NAME)

#clear all
re: fclean all

#avoids double inclusion
.PHONY: all clean fclean re
