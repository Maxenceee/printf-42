OBJ_DIR			=	.objs
MANDATORY_DIR	=	mandatory
BONUS_DIR		=	bonus

SRCS			=	$(MANDATORY_DIR)/sources/ft_len.c \
					$(MANDATORY_DIR)/sources/ft_printf.c \
					$(MANDATORY_DIR)/sources/ft_put.c \
					$(MANDATORY_DIR)/sources/ft_puthex.c

OBJS			=	$(patsubst  $(MANDATORY_DIR)/sources/%.c, $(OBJ_DIR)/$(MANDATORY_DIR)/%.o, $(SRCS))

SRCS_BONUS		=	$(BONUS_DIR)/sources/ft_bzero_bonus.c \
					$(BONUS_DIR)/sources/ft_calloc_bonus.c \
					$(BONUS_DIR)/sources/ft_convert_base_bonus.c \
					$(BONUS_DIR)/sources/ft_flags_bonus.c \
					$(BONUS_DIR)/sources/ft_flags2_bonus.c \
					$(BONUS_DIR)/sources/ft_ftoa_bonus.c \
					$(BONUS_DIR)/sources/ft_isdigit_bonus.c \
					$(BONUS_DIR)/sources/ft_itoa_bonus.c \
					$(BONUS_DIR)/sources/ft_len_bonus.c \
					$(BONUS_DIR)/sources/ft_pow_bonus.c \
					$(BONUS_DIR)/sources/ft_print_char_bonus.c \
					$(BONUS_DIR)/sources/ft_print_float_bonus.c \
					$(BONUS_DIR)/sources/ft_print_hex_bonus.c \
					$(BONUS_DIR)/sources/ft_print_int_bonus.c \
					$(BONUS_DIR)/sources/ft_print_pointer_bonus.c \
					$(BONUS_DIR)/sources/ft_print_string_bonus.c \
					$(BONUS_DIR)/sources/ft_print_u_int_bonus.c \
					$(BONUS_DIR)/sources/ft_print_width_bonus.c \
					$(BONUS_DIR)/sources/ft_printf_bonus.c \
					$(BONUS_DIR)/sources/ft_strcat_bonus.c \
					$(BONUS_DIR)/sources/ft_strdup_bonus.c \
					$(BONUS_DIR)/sources/ft_strjoin_bonus.c \
					$(BONUS_DIR)/sources/ft_strlcat_bonus.c \
					$(BONUS_DIR)/sources/ft_tolower_bonus.c \
					$(BONUS_DIR)/sources/ft_u_itoa_bonus.c \
					$(BONUS_DIR)/sources/ft_valids_bonus.c
					
OBJS_BONUS		=	$(patsubst  $(BONUS_DIR)/sources/%.c, $(OBJ_DIR)/$(BONUS_DIR)/%.o, $(SRCS_BONUS))

HEADER_DIR		=	$(MANDATORY_DIR)/includes/
HEADERBONUS_DIR	=	$(BONUS_DIR)/includes/
CC				=	gcc
RM				=	rm -f
LIBC			=	ar rcs
CFLAGS			=	-g3 #-Wall -Wextra -Werror

NAME			=	libftprintf.a
# NAME_BONUS		=	libftprintf_bonus.a

GREEN			=	\033[1;32m
BLUE			=	\033[1;34m
RED				=	\033[1;31m
YELLOW      	=	\033[1;33m
DEFAULT			=	\033[0m
UP				=	"\033[A"
CUT				=	"\033[K"

$(OBJ_DIR)/$(MANDATORY_DIR)/%.o: $(MANDATORY_DIR)/sources/%.c $(HEADER_DIR) Makefile
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling [$<]$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER_DIR)
	@printf ${UP}${CUT}

$(OBJ_DIR)/$(BONUS_DIR)/%.o: $(BONUS_DIR)/sources/%.c $(HEADERBONUS_DIR) Makefile
	@mkdir -p $(@D)
	@echo "$(YELLOW)Compiling [$<]$(DEFAULT)"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERBONUS_DIR)
	@printf ${UP}${CUT}

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"

bonus: $(OBJS_BONUS)
	@$(LIBC) $(NAME) $(OBJS_BONUS)
	@echo "$(GREEN)$(NAME) compiled!$(DEFAULT)"

# bonus: $(NAME_BONUS)

# $(NAME_BONUS): $(OBJS_BONUS)
# 	@$(LIBC) $(NAME_BONUS) $(OBJS_BONUS)
# 	@echo "$(GREEN)$(NAME_BONUS) compiled!$(DEFAULT)"

clean:
	@echo "$(RED)Cleaning build folder$(DEFAULT)"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Cleaning $(NAME)$(DEFAULT)"
	@$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus