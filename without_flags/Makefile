OBJ_DIR			=	.objs

SRCS			=	sources/ft_len.c \
					sources/ft_printf.c \
					sources/ft_put.c \
					sources/ft_puthex.c

OBJS			=	$(patsubst sources%.c, $(OBJ_DIR)%.o, $(SRCS))

HEADER_DIR		=	includes/
CC				=	gcc
RM				=	rm -f
LIBC			=	ar rc
CFLAGS			=	-Wall -Wextra -Werror

NAME			=	libftprintf.a

GREEN			=	\033[1;32m
BLUE			=	\033[1;34m
DEFAULT			=	\033[0m

$(OBJ_DIR)/%.o: sources/%.c $(HEADER_DIR) Makefile
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)Compiling $<$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR)

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(LIBC) $(NAME) $(OBJS)
				@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re