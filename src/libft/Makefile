# ANSI COLOR CODE
RED		:=	\033[31m
GREEN		:=	\033[32m
YELLOW		:=	\033[33m
BLUE		:=	\033[34m
MAGENTA		:=	\033[35m
CYAN		:=	\033[36m
RESET		:=	\033[0m

SRCS		=	ft_atoi.c		\
			ft_bzero.c		\
			ft_calloc.c		\
			ft_isalnum.c		\
			ft_isalpha.c		\
			ft_isascii.c		\
			ft_isdigit.c		\
			ft_isprint.c		\
			ft_itoa.c		\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memmove.c		\
			ft_memset.c		\
			ft_putchar_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_putstr_fd.c		\
			ft_strchr.c		\
			ft_strdup.c		\
			ft_striteri.c		\
			ft_strjoin.c		\
			ft_strlcat.c		\
			ft_strlcpy.c		\
			ft_strlen.c		\
			ft_strmapi.c		\
			ft_strncmp.c		\
			ft_strnstr.c		\
			ft_strrchr.c		\
			ft_strstr.c		\
			ft_strtrim.c		\
			ft_substr.c		\
			ft_split.c		\
			ft_tolower.c		\
			ft_toupper.c		\
			ft_lstsize_bonus.c	\
			ft_lstnew_bonus.c	\
			ft_lstlast_bonus.c	\
			ft_lstadd_front_bonus.c	\
			ft_lstadd_back_bonus.c	\

INCLUDES	=	../../include
CC		=	cc

CFLAGS		=	-Wall -Werror -Wextra -I$(INCLUDES)

OBJS		=	${SRCS:.c=.o}

NAME		=	libft.a

AR		=	ar

ARFLAGS		=	rsc

RM		=	rm -f

# ------------ RULE ------------ #

%.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

all		:	$(NAME)

$(NAME)		:	$(OBJS)
			@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean		:
			@$(RM) $(OBJS)
			
fclean		:	clean
			@$(RM) $(NAME)

re		:	fclean	\
			all

.PHONY		:	all	\
			fclean	\
			clean	\
			re
