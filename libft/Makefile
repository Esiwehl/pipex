# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ewehl <ewehl@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 13:55:15 by ewehl         #+#    #+#                  #
#    Updated: 2023/02/26 22:15:07 by ewehl         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

HEADERF			= headers/libft.h headers/ft_printf.h headers/get_next_line.h

SRC_DIR			= src/
OBJ_DIR			= obj/

SRCS			=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
					ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
					ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_putstr_fd.c ft_split.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c \
					ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strldup.c ft_strlen.c \
					ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
					ft_tolower.c ft_toupper.c get_next_line.c ft_printf.c ft_putstr.c ft_putuint.c\
					ft_puthex.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
					ft_free_me.c ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstmap.c ft_lstsize.c

OBJS			= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
IFLAGS			= -I headers/
RM				= rm -Rf

AR				= ar rcs

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "$(CYAN)	Working on libft..$(WHITE)"
	@$(AR) $@ $^
	@echo "$(PURPLE)	Foundation laid. :D$(WHITE)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERF)
	@mkdir -p $(@D)
	@$(CC) $(IFLAGS) $(CFLAGS) -c $< -o $@

clean :
	@echo "$(CYAN)	There goes libft, schwoooopp$(WHITE)"
	@$(RM) $(OBJ_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all
	@echo "$(YELLOW)	Really... Pls Stop making me work this hard. ಠ_ರೃ $(WHITE)"

norm:
	@norminette $(SRCS) $(HEADERF)

.PHONY:		all clean fclean re norm

GREY	=	\033[0;30m
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
PURPLE	=	\033[0;35m
CYAN	=	\033[0;36m
WHITE	=	\033[0;37m

#INC_DIR =   $(shell find headers -type d)
#IFLAGS = $(foreach dir, $(INC_DIR), -I$(dir))
#@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<