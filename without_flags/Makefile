SRCS			=	sources/ft_len.c \
					sources/ft_printf.c \
					sources/ft_put.c \
					sources/ft_puthex.c

OBJS			=	$(SRCS:.c=.o)

HEADER_DIR		=	includes/
CC				=	gcc
RM				=	rm -f
LIBC			=	ar rc
CFLAGS			=	-Wall -Wextra -Werror

NAME			=	libftprintf.a

%.o: %.c $(HEADER_DIR) Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(LIBC) $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re