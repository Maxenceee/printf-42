SRCS			=	sources/ft_len.c \
					sources/ft_printf.c \
					sources/ft_put.c \
					sources/ft_puthex.c

OBJS			=	$(SRCS:.c=.o)

HEADER_DIR		=	includes/
CC				=	gcc
RM				=	rm -f
LIBC			=	ar rc
CFLAGS			=	-Wall -Wextra -Werror -I $(HEADER_DIR)

NAME			=	libftprintf.a

%.o: %.c $(HEADER_DIR) Makefile
	$(CC) -c $< -o $@ -I $(HEADER_DIR)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(LIBC) $(NAME) $(OBJS)

bonus: all
b: 
	$(CC) $(OBJS) -o printf

m:	all b

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)
				$(RM) printf

re:				fclean $(NAME)

.PHONY:			all clean fclean re