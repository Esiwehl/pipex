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

LIBFT			= libft
GNL				= gnl
FT_PRINTF		= ft_printf
HEADERF			= headers

SRCS			=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
					ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
					ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
					ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
					ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
OBJS			= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_DIR			= obj/libft/

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
RM				= rm -f

AR				= ar rcs

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C $(GNL)
	@mv gnl/gnl.a ft_printf/ft_printf.a
	@make -C $(FT_PRINTF)
	@mv ft_printf/ft_printf.a $(NAME)
	@$(AR) $@ $^
	@echo "COMPILED _COMPLETE_ LIBFT :D"

$(OBJ_DIR)%.o : %.c $(HEADERF)
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean :
	@$(RM) -R $(OBJ_DIR)
	@make clean -C $(GNL)
	@make clean -C $(FT_PRINTF)
	@echo "I just-a cleaning lady... :shrug:"

fclean : clean
	@$(RM) $(NAME)
	@make fclean -C $(GNL)
	@make fclean -C $(FT_PRINTF)
	@$(RM) $(LIBFT)/libft.a

re : fclean all

norm:
	@norminette $(SRCS) $(HEADERF)

.PHONY:		all clean fclean re norm
