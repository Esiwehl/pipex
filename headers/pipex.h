/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 23:02:47 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/22 00:29:27 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/* errno */
# include <errno.h>

/* libft functions */
# include "../libft/headers/libft.h"

typedef struct s_pipex
{
	char	**envp;
	char	**argv;
	int		argc;
	int		heredoc;
	int		infile;
	int		outfile;
	int		*pipe_arr;
	int		cmd_cnt;
	int		child;
	int		*pids;
	char	**cmd_args;
	char	*cmd_p;
}		t_pipex;

/*	init.c	*/
void	blow_pipes(t_pipex *p);
t_pipex	clean_init(void);
t_pipex	init(int argc, char *argv[], char *envp[]);

/*	file_management.c	*/
void	get_files(t_pipex *p);
void	heredoc(t_pipex *p);

/*	cmd_parsing.c	*/
char	*get_cmd(char *cmd, t_pipex *pipex);

/*	ft_split_cmds.c	*/
char	**ft_split_cmds(char const *s, char c);

/*	fd_printf.c	*/
int		fd_printf(int fd, const char *format, ...);

/*	utils.c	*/
void	close_fd(t_pipex *pipex);
void	clean_up(t_pipex *pipex);
void	ft_error(t_pipex *p, char *msg, char *some_name, int exit_c);
void	free_arr(char *str, char **dd_str);
#endif