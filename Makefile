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

SRC_DIR		=	./src/push_swap
SRCS		=	$(wildcard $(SRC_DIR)/*.c)

LIBFTNAME	=	libftprintf.a
LIBFT_PATH	=	./src/ft_printf

LIBFT_ONLY	=	libft.a
LIBFT_ONLY_PATH	=	./src/libft

CC		=	cc
CFLAGS		=	-Wall -Werror -Wextra -g

OBJS		=	$(SRCS:.c=.o)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

#======================RULES=======================#

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			@echo "$(GREEN)==========================$(RESET)"
			@echo "$(GREEN) Building $(CYAN)push_swap $(GREEN)program...$(RESET)"
			@make -C $(LIBFT_ONLY_PATH)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ONLY_PATH)/$(LIBFT_ONLY) -o $(NAME)
			@echo "$(GREEN) Build complete!$(RESET)"
			@echo "$(GREEN)==========================$(RESET)"
			
pr		:	$(LIBFTNAME)

$(LIBFTNAME)	:	$(OBJS)
			@echo "$(GREEN)==========================$(RESET)"
			@echo "$(GREEN) Building $(MAGENTA)libft_printf$(GREEN)...$(RESET)"
			@make -C $(LIBFT_PATH)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)/$(LIBFTNAME) -o $(NAME)
			@echo "$(GREEN) Build complete!$(RESET)"
			@echo "$(GREEN)==========================$(RESET)"


clean		:
			@echo "$(RED)===========$(WHITE)clean$(RED)===========$(RESET)"
			@echo "$(RED)Cleaning up...$(RESET)"
			@rm -f $(OBJS)
			@cd $(LIBFT_PATH) && make clean
			@echo "$(RED)Cleaning complete!$(RESET)"
			@echo "$(RED)===========$(WHITE)clean$(RED)===========$(RESET)"

fclean		:	clean
			@echo "$(RED)===========$(CYAN)fclean$(RED)===========$(RESET)"
			@echo "$(RED)Deleting .a files...$(RESET)"
			@rm -f $(NAME)
			@cd $(LIBFT_PATH) && make fclean
			@echo "$(RED)Delete complete!$(RESET)"
			@echo "$(RED)===========$(CYAN)fclean$(RED)===========$(RESET)"

re		:	fclean	\
			all

.PHONY		:	all	\
			clean	\
			fclean	\
			re
