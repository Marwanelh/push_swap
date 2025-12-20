NAME            = push_swap
BONUS_NAME      = checker

SRCS_DIR        = srcs
OBJS_DIR        = objs
INCS_DIR        = includes
LIBFT_DIR       = libft

CC              = cc
CFLAGS          = -Wall -Wextra -Werror -I$(INCS_DIR) -I$(LIBFT_DIR)/includes

# Header file for dependency tracking
HEADER          = $(INCS_DIR)/push_swap.h

COMMON_SRCS     =   srcs/lst/ft_stack_new.c srcs/lst/ft_stackadd_front.c \
                    srcs/lst/ft_stack_size.c srcs/lst/ft_stacklast.c \
                    srcs/lst/ft_stackadd_back.c srcs/lst/ft_stack_clear.c \
                    srcs/lst/ft_print_stack.c \
                    srcs/instructions/push.c srcs/instructions/swap.c \
                    srcs/instructions/rotate.c srcs/instructions/r_rotate.c \
                    srcs/utils/ft_parse.c srcs/utils/ft_error.c \
                    srcs/utils/ft_validate.c srcs/utils/ft_check_sorted.c \
                    srcs/utils/ft_sort.c srcs/utils/ft_small_sort.c \
                    srcs/utils/ft_rank.c srcs/utils/ft_cost.c \
                    srcs/utils/ft_move.c srcs/utils/ft_sort_utils.c \
                    srcs/gnl/get_next_line.c srcs/gnl/get_next_line_utils.c

# Main program sources
SRCS            =   $(COMMON_SRCS) srcs/main.c

# Bonus program sources
BONUS_SRCS      =   $(COMMON_SRCS) srcs/bonus/checker.c

OBJS            =   $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
BONUS_OBJS      =   $(BONUS_SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

LIBFT           =   $(LIBFT_DIR)/libft.a

# --- Rules ---

all:            $(NAME)

# Compile Libft (Added --no-print-directory)
$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory

# Compile Push_swap
$(NAME):        $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(NAME) created successfully."

# Bonus Rule
bonus:          $(BONUS_NAME)

# Compile Checker (Bonus)
$(BONUS_NAME):  $(LIBFT) $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@echo "$(BONUS_NAME) created successfully."

# Compile Objects
$(OBJS_DIR)/%.o:    $(SRCS_DIR)/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean Rules (Added --no-print-directory)
clean:
	@make clean -C $(LIBFT_DIR) --no-print-directory
	@rm -rf $(OBJS_DIR)
	@echo "Object files removed."

fclean:         clean
	@make fclean -C $(LIBFT_DIR) --no-print-directory
	@rm -f $(NAME) $(BONUS_NAME)
	@echo "$(NAME) and $(BONUS_NAME) removed."

re:             fclean all

.PHONY:         all clean fclean re bonus