/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 14:23:02 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/22 21:03:22 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	free_pipe(t_pipex *pipex, char flag)
{
	size_t	idx;

	idx = 0;
	if(flag == 'p')
		close_pipes(pipex);
	while(pipex->cmd_p[idx])
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
		ft_error();
	}
	if (access(cmd, X_OK) < 0)
	{
		ft_putstr_fd("Permissions denied, weeb", 2);
		exit(126);
	}
	return (1);
}

char *get_path(char **env)
{
	char *path;
	size_t idx;

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

char *get_cmd(char **paths, char *cmd)
{
	char	*the_way;
	char	*tmp;
	size_t	idx;

	idx = 0;
	while (paths[idx])
	{
		tmp = ft_strappend(paths[idx], "/"); //at some point use va list for strappend?
		the_way = ft_strappend(paths[idx], cmd);
		free(tmp);
		if (check_cmd(the_way) == 1)
			return (the_way);
		free(the_way);
		idx++;
	}
	return (NULL);
}

int	ft_fork(t_pipex pipex, char **argv, char **envp)
{
	pipex.pid = fork();
	if (pipex.pid == 0)
		child(pipex, argv, envp);
	else
		parent(pipex, argv, envp);
	return (pipex.pid);
}

void	child(t_pipex pipex, char **argv, char **env)
{
	pipex.infile = open(argv[1], O_RDONLY);
	if (access(argv[1], F_OK) < 0)
		ft_error();
	if (access(argv[1], R_OK) < 0)
		ft_error();
	dup2(pipex.pipe[1], 1);
	close(pipex.pipe[0]);
	dup2(pipex.infile, 0);
	pipex.cmds_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_p, pipex.cmds_args[0]);
	if (!pipex.cmd)
	{
		ft_free(&pipex, 'c');
		ft_error();
		//ft_putstr_fd("Command not found\n", 2);
		//exit(127);
	}
	execve(pipex.cmd, pipex.cmds_args, env);
	exit(1);
}

void	parent(t_pipex pipex, char **argv, char **env)
{
	pipex.outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (access(argv[4], W_OK) < 0)
	{
		ft_error();
		//ft_putstr_fd("permission denied\n", 2);
		//exit(1);
	}
	dup2(pipex.pipe[0], 0);
	close(pipex.pipe[1]);
	dup2(pipex.outfile, 1);
	pipex.cmds_args = ft_split(argv[3], ' ');
	if (pipex.cmds_args[0] == NULL)
		exit(1);
	pipex.cmd = get_cmd(pipex.cmd_p, pipex.cmds_args[0]);
	if (!pipex.cmd)
	{
		ft_free(&pipex, 'p');
		ft_error();
		//ft_putstr_fd("Command not found\n", 2);
		//exit(127);
	}
	execve(pipex.cmd, pipex.cmds_args, env);
	exit(1);
}

int	main(int argc, char *argv[], char *envp[])
{	
	t_pipex		pipex;
	int			stat;

	if (argc != 5)
	{
		ft_putstr_fd("Wrong number of inputs", 2);
		return (1);
	}
	if (pipe(pipex.pipe) < 0)
	{
		ft_error();
		//ft_putstr_fd("Pipe failed", 2);
		//return (1);
	}
	pipex.paths = get_path(envp);
	pipex.cmd_p = ft_split(pipex.paths, ':');
	if (ft_fork(pipex, argv, envp) < 0)
		ft_error();
	close_pipes(&pipex);
	waitpid(pipex.pid, &stat, 0);
	ft_free(&pipex, 'p');
	return (0);
}
