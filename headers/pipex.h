/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 14:27:44 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/29 22:16:44 by ewehl         ########   odam.nl         */
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

/*to perror*/
# include <stdio.h>

/* errno */
# include <errno.h>

/*to libft*/
# include "../libft/headers/libft.h"

// /* to get_next_line */
// # include "get_next_line.h"

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PATH "Path not found.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

typedef struct s_pipex
{
	pid_t	pid;
	int		pipe[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_p;
	char	**cmds_args;
	char	*cmd;
}			t_pipex;

int			ft_error(void);
int			fd_printf(int fd, const char *format, ...);
void		ft_free(t_pipex *pipex, char c);
void		close_pipes(t_pipex *pipex);
char		*get_cmd(char **paths, char *cmd);
char		*find_path(char **envp);
char		*get_path(char **env);
int			check_cmd(char *cmd);
void		child(t_pipex pipex, char **av, char **envp);
void		parent(t_pipex pipex, char **av, char **envp);

#endif