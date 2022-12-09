SRCS			=	sources/ft_calloc.c \
					sources/ft_flags.c \
					sources/ft_isdigit.c \
					sources/ft_len.c \
					sources/ft_print_hex.c \
					sources/ft_print_pointer.c \
					sources/ft_print_u_int.c \
					sources/ft_printf.c \
					sources/ft_tolower.c \
					sources/ft_valids.c	\
					sources/ft_strjoin.c \
					sources/ft_convert_base.c \
					sources/ft_flags2.c \
					sources/ft_itoa.c \
					sources/ft_print_char.c \
					sources/ft_print_int.c \
					sources/ft_print_string.c \
					sources/ft_print_width.c \
					sources/ft_strdup.c \
					sources/ft_u_itoa.c \
					sources/ft_ftoa.c \
					sources/ft_print_float.c \
					sources/ft_strlcat.c
					
OBJS			=	$(SRCS:.c=.o)

HEADER_DIR		=	includes/
CC				=	gcc
RM				=	rm -f
LIBC			=	ar rcs
CFLAGS			=	-Wall -Wextra -Werror 

NAME			=	libftprintf.a

%.o: %.c $(HEADER_DIR) Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR)

all:			$(NAME)

$(NAME):		$(OBJS) 
				$(LIBC) $(NAME) $(OBJS)

bonus: all

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re