/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/29 20:53:40 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/07 12:55:28 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

int	ft_error(void)
{
	char	*msg;

	msg = strerror(errno);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(errno);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

void	ft_free(t_pipex *pipex, char flag)
{
	size_t	idx;

	idx = 0;
	if (flag == 'p')
		close_pipes(pipex);
	while (pipex->cmd_p[idx])
	{
		free(pipex->cmd_p[idx]);
		idx++;
	}
	free(pipex->cmd_p);
}

int	check_cmd(char *cmd)
{
	if (access(cmd, F_OK) < 0)
	{
		fd_printf(2, "pipex: %s: command not found\n", cmd);
		exit(126);
	}
	if (access(cmd, X_OK) < 0)
	{
		fd_printf(2, "pipex: %s: Permission denied\n", cmd);
		exit(126);
	}
	return (1);
}

char	*get_path(char **env)
{
	char	*path;
	size_t	idx;

	idx = 0;
	while (env[idx] && ft_strncmp(env[idx], "PATH", 4))
		idx++;
	if (env[idx] == NULL)
	{
		path = "/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin:/bin:/sbin:.";
		return (path);
	}
	path = ft_strdup(ft_strtrim(env[idx], "PATH="));
	return (path);
}
