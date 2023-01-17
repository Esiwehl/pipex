# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ewehl <ewehl@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 13:55:15 by ewehl         #+#    #+#                  #
#    Updated: 2023/01/17 16:04:59 by ewehl         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

HEADERF	= headers/pipex.h

LIBFT			= libft
SRC_DIR			= src/
OBJ_DIR			= obj/

SRCS			= pipex.c \

OBJS			= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
IFLAGS			= -I headers/
RM				= rm -Rf

AR				= ar rcs

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "$(GREY)	Working on it..$(WHITE)"
	@@make -sC $(LIBFT)
	@$(CC) $(IFLAGS) $(CFLAGS) $(LIBFT)/libft.a $(OBJ_DIR)/pipex.o -o $@
	@echo "$(GREEN)	Pipes are up.$(WHITE)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERF)
	@mkdir -p $(@D)
	@$(CC) $(IFLAGS) $(CFLAGS) -c $< -o $@

clean :
	@echo "$(BLUE)	I just-a cleaning lady... ¯\_(ツ)_/¯ $(WHITE)"
	@make clean -sC $(LIBFT)
	@$(RM) $(OBJ_DIR)
	@echo "$(PURPLE)	I cleaned your mess, again. Fix your shit ♡눈_눈♡$(WHITE)"

fclean : clean
	@make fclean -sC $(LIBFT)
	@$(RM) $(NAME)

re : fclean all
	@make fclean -C $(LIBFT)
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