NAME = libftprintf.a

RM = @rm -f
CC = clang

DIR_LIBFT= libft

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_list1.c ft_list2.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C $(addprefix ./,$(DIR_LIBFT))
	@mkdir obj
	@find -name "*.o" -exec cp {} ./obj \;
	ar rcs $@ ./obj/*.o
	@rm -rf ./obj
	
clean :
	$(RM) $(OBJ)
	make clean -C $(addprefix ./,$(DIR_LIBFT))

fclean : clean
	$(RM) $(NAME) 
	$(RM) $(addprefix ./,$(DIR_LIBFT))/libft.a

re : fclean all

.PHONY: all clean fclean re 
