# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ewehl <ewehl@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 13:55:15 by ewehl         #+#    #+#                  #
#    Updated: 2023/02/08 20:24:37 by ewehl         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

HEADERF	= headers/pipex.h
BONUS_HEADERF = headers/pipex_bonus.h

LIBFT			= libft
SRC_DIR			= src/
SRC_B_DIR		= bonus/
OBJ_DIR			= obj/

SRCS			= pipex.c utils.c fd_printf.c ft_split_cmds.c
SRCS_BONUS		= pipex_bonus.c $(SRCS)

OBJS			= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
BONUS_OBJS			= $(addprefix $(OBJ_DIR), $(SRCS_BONUS:.c=.o))

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
IFLAGS			= -I headers/
RM				= rm -Rf

AR				= ar rcs

GITMSG			?= "Commit by Makefile."


all : $(NAME)

$(NAME) : $(OBJS)
	@echo "$(GREY)	Working on these gdamn pipes..$(WHITE)"
	@@make -s -C $(LIBFT)
	@$(CC) $(IFLAGS) $(CFLAGS) $(LIBFT)/libft.a $(OBJS) -o $@
	@echo "$(GREEN)	Pipes are up.$(WHITE)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERF)
	@mkdir -p $(@D)
	@$(CC) $(IFLAGS) $(CFLAGS) -c $< -o $@

bonus : $(BONUS_OBJS) $(BONUS_HEADERF)
	@echo "$(GREY)	Tryharding..$(WHITE)"
	@$(CC) $(IFLAGS) $(CFLAGS) $(LIBFT)/libft.a $(BONUS_OBJS) -o $(NAME)
	@echo "$(GREEN) LETS GO $(WHITE)"
			
clean :
	@echo "$(GREY)	I just-a cleaning lady... ¯\_(ツ)_/¯ $(WHITE)"
	@make clean -s -C $(LIBFT)
	@$(RM) $(OBJ_DIR)
	@echo "$(PURPLE)	I cleaned your mess, again. Fix your shit ♡눈_눈♡$(WHITE)"

fclean : clean
	@$(RM) $(LIBFT)libft.a
	@$(RM) $(NAME)

re : fclean all
	@echo "$(YELLOW)	Pls Stop making me work this hard. ಠ_ರೃ $(WHITE)"

norm:
	@norminette $(SRCS) $(HEADERF)

sendit:
	@git add -u
	@git commit -m $(GITMSG)
	@git push

.PHONY:		all clean fclean re norm sendit

GREY	=	\033[0;30m
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
PURPLE	=	\033[0;35m
CYAN	=	\033[0;36m
WHITE	=	\033[0;37m