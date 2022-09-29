#source files
SRC = 	ft_atoi.c \
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


#directory of objects
OBJPATH = temps

#tranform into .o
OBJ = $(SRC:%.c=$(OBJPATH)/%.o)

#header source
HEADER = libft.h

#directories with *.c
VPATH = original_functions getnextline other_functions

#header to libft.h
INCLUDE = -I ./

#static library's name
NAME = libft.a

#for compliling
FLAGS = -Wall -Wextra -Werror

#remove files
RM = rm -f

##RULES
#compile 
$(OBJ)/%.o: $(SRC) $(HEADER)
		cc $(FLAGS) -c $< -o $@ $(INCLUDE)

#rule name - make library
$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)

#make libft.a
all: $(NAME)

#remove objects
clean: 
		$(RM) $(OBJ)
#remove all
fclean: clean
		$(RM) $(NAME)
#clear all
re: fclean all

#avoids double inclusion
.PHONY: all clean fclean re