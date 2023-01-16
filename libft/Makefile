# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ewehl <ewehl@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 13:55:15 by ewehl         #+#    #+#                  #
#    Updated: 2022/12/27 17:47:52 by ewehl         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

HEADERF			= headers/libft.h headers/ft_printf.h headers/get_next_line.h

SRCS			=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
					ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
					ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_putstr_fd.c ft_split.c ft_strchr.c ft_strcpy.c ft_strdup.c ft_striteri.c \
					ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strldup.c ft_strlen.c ft_strmapi.c \
					ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
					ft_toupper.c get_next_line.c ft_printf.c ft_putstr.c ft_putuint.c ft_puthex.c
OBJS			= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_DIR			= obj/

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
RM				= rm -f

AR				= ar rcs

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "$(YELLOW)WORKIN ON IT -.- $(WHITE)"
	@$(AR) $@ $^
	@echo "$(GREEN)COMPILED LIBFT :D$(WHITE)"

$(OBJ_DIR)%.o : %.c $(HEADERF)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) -R $(OBJ_DIR)
	@echo "$(BLUE)I just-a cleaning lady... :shrug:$(WHITE)"

fclean : clean
	@$(RM) $(NAME)

re : fclean all

norm:
	@norminette $(SRCS) $(HEADERF)

.PHONY:		all clean fclean re norm

GREY	=	$'\e[30m
RED		=	$'\e[31m
GREEN	=	$'\e[32m
YELLOW	=	$'\e[33m
BLUE	=	$'\e[34m
PURPLE	=	$'\e[35m
CYAN	=	$'\e[36m
WHITE	=	$'\e[37m