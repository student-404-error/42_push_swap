# ANSI COLOR CODE
RED		:=	\033[31m
GREEN		:=	\033[32m
YELLOW		:=	\033[33m
BLUE		:=	\033[34m
MAGENTA		:=	\033[35m
CYAN		:=	\033[36m
WHITE		:=	\033[37m
RESET		:=	\033[0m

NAME		=	push_swap

INCLUDES	=	./include

SRC_DIR		=	./src/push_swap
SRCS		=	$(wildcard $(SRC_DIR)/*.c)
BONUS_DIR	=	./src/bonus
BONUS_SRCS	=	$(wildcard $(BONUS_DIR)/*.c)

LIBFTNAME	=	libftprintf.a
LIBFT_PATH	=	./src/ft_printf

CC		=	cc
CFLAGS		=	-Wall -Werror -Wextra -g -I$(INCLUDES)

OBJS		=	$(SRCS:.c=.o)
B_OBJS		=	$(BONUS_SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

#======================RULES=======================#

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			@echo "$(GREEN)==========================$(RESET)"
			@echo "$(GREEN) Building $(MAGENTA)libft_printf$(GREEN)...$(RESET)"
			@make -C $(LIBFT_PATH)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)/$(LIBFTNAME) -o $(NAME)
			@echo "$(GREEN) Build complete!$(RESET)"
			@echo "$(GREEN)==========================$(RESET)"

bonus		:	$(B_OBJS)
			@echo "$(GREEN)==========================$(RESET)"
			@echo "$(GREEN) Building $(BLUE)checker$(GREEN)...$(RESET)"
			@make -C $(LIBFT_PATH)
			@$(CC) $(CFLAGS) $(B_OBJS) $(LIBFT_PATH)/$(LIBFTNAME) -o checker
			@echo "$(GREEN) Build complete!$(RESET)"
			@echo "$(GREEN)==========================$(RESET)"

clean		:
			@echo "$(RED)===========$(WHITE)clean$(RED)===========$(RESET)"
			@echo "$(RED)Cleaning up...$(RESET)"
			@rm -f $(OBJS) $(B_OBJS)
			@cd $(LIBFT_PATH) && make clean
			@echo "$(RED)Cleaning complete!$(RESET)"
			@echo "$(RED)===========$(WHITE)clean$(RED)===========$(RESET)"

fclean		:	clean
			@echo "$(RED)===========$(CYAN)fclean$(RED)===========$(RESET)"
			@echo "$(RED)Deleting .a files...$(RESET)"
			@rm -f $(NAME) checker
			@cd $(LIBFT_PATH) && make fclean
			@echo "$(RED)Delete complete!$(RESET)"
			@echo "$(RED)===========$(CYAN)fclean$(RED)===========$(RESET)"

re		:	fclean	\
			all

.PHONY		:	all	\
			clean	\
			fclean	\
			bonus	\
			re
