# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ewehl <ewehl@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 13:55:15 by ewehl         #+#    #+#                  #
#    Updated: 2022/12/27 17:48:56 by ewehl         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= gnl.a

GNL				= gnl
HEADERF			= headers/get_next_line.h

SRCS			= get_next_line.c get_next_line_utils.c
OBJS			= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
OBJ_DIR			= ../obj/gnl/

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
RM				= rm -f

AR				= ar rcs

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "GNL"
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
