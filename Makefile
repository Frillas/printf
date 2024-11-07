NAME = libftprintf.a

RM = @rm -f
CC = cc

DIR_LIBFT= libft

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_list1.c ft_list2.c
SRCLIB = ./libft/ft_atoi.c ./libft/ft_bzero.c ./libft/ft_calloc.c ./libft/ft_isalnum.c ./libft/ft_isalpha.c ./libft/ft_isascii.c ./libft/ft_isdigit.c \
./libft/ft_isprint.c ./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_memset.c ./libft/ft_strchr.c \
./libft/ft_strdup.c ./libft/ft_strlcat.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c ./libft/ft_strncmp.c ./libft/ft_strnstr.c \
./libft/ft_strrchr.c ./libft/ft_tolower.c ./libft/ft_toupper.c ./libft/ft_substr.c ./libft/ft_strjoin.c ./libft/ft_strtrim.c \
./libft/ft_split.c ./libft/ft_itoa.c ./libft/ft_strmapi.c ./libft/ft_striteri.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c \
./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c \

OBJ = $(SRC:.c=.o)
OBJLIB = $(SRCLIB:.c=.o)

SRCS = $(SRC) $(SRCLIB)
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(addprefix ./,$(DIR_LIBFT))
	@mkdir obj
	cp $(OBJ) ./obj
	cp $(OBJLIB) ./obj
	@ar rcs $@ $(OBJS)
	@rm -rf ./obj	
	
clean :
	$(RM) $(OBJ)
	make clean -C $(addprefix ./,$(DIR_LIBFT))

fclean : clean
	$(RM) $(NAME) 
	$(RM) $(addprefix ./,$(DIR_LIBFT))/libft.a

re : fclean all

.PHONY: all clean fclean re 
