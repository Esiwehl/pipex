/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 19:19:53 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/28 15:06:19 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	free_arr(char *str, char **dd_str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	if (dd_str)
		dd_str = free_me(dd_str);
}

static void	kill_mario(t_pipex *pipex)
{
	int	idx;

	idx = 0;
	while (idx < (pipex->cmd_cnt - 1) * 2)
	{
		close(pipex->pipe_arr[idx]);
		idx++;
	}
}

void	close_fd(t_pipex *pipex)
{
	if (pipex->infile != -1)
		close(pipex->infile);
	if (pipex->outfile != -1)
		close(pipex->outfile);
	kill_mario(pipex);
}

void	clean_up(t_pipex *pipex, int exit_c)
{
	if (pipex)
	{
		close_fd(pipex);
		if (pipex->pipe_arr)
			free(pipex->pipe_arr);
		if (pipex->pids)
			free(pipex->pids);
		if (pipex->cmd_p || pipex->cmd_args)
			free_arr(pipex->cmd_p, pipex->cmd_args);
		if (pipex->heredoc == 1)
			unlink(".heredoc.tmp");
	}
	exit(exit_c);
}

void	ft_error(t_pipex *p, char *msg, char *some_name, int exit_c)
{
	if (some_name)
		fd_printf(2, "pipex: %s: %s\n", msg, some_name);
	else if (!ft_strcmp(msg, "here_doc"))
		fd_printf(2, "usage: ./pipex here_doc LIMITER cmd1 ... cmdn outfile\n");
	else if (!ft_strcmp(msg, "standard"))
		fd_printf(2, "usage: ./pipex infile cmd1 ... cmdn outfile\n");
	else if (!p && !msg && !some_name)
		exit(exit_c);
	else if (p && msg)
		fd_printf(2, "pipex: %s\n", msg);
	clean_up(p, exit_c);
}
