# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ewehl <ewehl@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 13:55:15 by ewehl         #+#    #+#                  #
#    Updated: 2023/02/27 07:15:49 by ewehl         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

HEADERF	= headers/pipex.h
BONUS_HEADERF = headers/pipex_bonus.h

LIBFT			= libft
SRC_DIR			= src/
OBJ_DIR			= obj/

SRCS			= init.c cmd_parsing.c fd_printf.c ft_split_cmds.c
SRCS_MAN		= pipex.c file_management.c utils.c $(SRCS)
SRCS_BONUS		= pipex_bonus.c file_management_bonus.c utils_bonus.c $(SRCS)

MAN_OBJS		= $(addprefix $(OBJ_DIR), $(SRCS_MAN:.c=.o))
BONUS_OBJS		= $(addprefix $(OBJ_DIR), $(SRCS_BONUS:.c=.o))

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
IFLAGS			= -I headers/
RM				= rm -Rf

AR				= ar rcs

GITMSG			?= "Commit by Makefile."

ifdef WITH_BONUS
OBJS			= $(BONUS_OBJS)
else
OBJS			= $(MAN_OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJS)
	@echo "$(GREY)	Working on these gdamn pipes..$(WHITE)"
	@@make -s -C $(LIBFT)
	@$(CC) $(IFLAGS) $(CFLAGS) $(LIBFT)/libft.a $(OBJS) -o $@
	@echo "$(GREEN)	Pipes are up.$(WHITE)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERF)
	@mkdir -p $(@D)
	@$(CC) $(IFLAGS) $(CFLAGS) -c $< -o $@

bonus :
	@$(MAKE) WITH_BONUS=true all
	
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
	@norminette $(addprefix $(SRC_DIR), $(SRCS)) $(addprefix $(SRC_DIR), $(SRCS_BONUS)) $(HEADERF)

sendit:
	@git add -u
	@git commit -m $(GITMSG)
	@git push

.PHONY:		all clean fclean re norm sendit bonus

GREY	=	\033[0;30m
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
PURPLE	=	\033[0;35m
CYAN	=	\033[0;36m
WHITE	=	\033[0;37m