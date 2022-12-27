# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ewehl <ewehl@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 13:55:15 by ewehl         #+#    #+#                  #
#    Updated: 2022/12/27 17:36:00 by ewehl         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= ft_printf.a

FT_PRINTF		= ft_printf
HEADERF			= headers/ft_printf

SRCS			= ft_printf.c ft_putstr.c ft_putuint.c ft_puthex.c
OBJS			= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_DIR			= ../obj/ft_printf/

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
RM				= rm -f

AR				= ar rcs

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "PRINTF"
	$(AR) $@ $^

$(OBJ_DIR)%.o : %.c $(HEADERF)
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) -o $@ $<

clean :
	@$(RM) -R $(OBJ_DIR)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

norm:
	@norminette $(SRCS) $(HEADERF)

.PHONY:		all clean fclean re norm
