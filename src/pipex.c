/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 14:23:02 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/07 13:18:33 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

char	*wayfinder(char **paths, char *cmd)
{
	char	*the_way;
	size_t	idx;

	idx = 0;
	if ((cmd[0] == '.') || ((ft_strrchr(cmd, '/')) && access(cmd, F_OK) == 0))
	{
		if (check_cmd(cmd) == 1)
			return (cmd);
	}
	while (paths[idx])
	{
		paths[idx] = ft_strappend(paths[idx], "/");
		the_way = ft_strjoin(paths[idx], cmd);
		if (access(the_way, F_OK) == 0)
		{
			check_cmd(the_way);
			return (the_way);
		}
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
	{
		fd_printf(2, "pipex: %s: No such file or directory\n", argv[1]);
		exit(0);
	}
	if (access(argv[1], R_OK) < 0)
	{
		fd_printf(2, "pipex: %s: Permission denied\n", argv[1]);
		exit(0);
	}
	dup2(pipex.pipe[1], 1);
	close(pipex.pipe[0]);
	dup2(pipex.infile, 0);
	// fd_printf(2, "argv[2]= %s\n", argv[2]);
	pipex.cmds_args = ft_split_cmds(argv[2], ' ');
	// fd_printf(2, "cmdargs in c: %s\n", pipex.cmds_args[0]);
	pipex.cmd = wayfinder(pipex.cmd_p, pipex.cmds_args[0]);
	// fd_printf(2, "cmd in c = %s\n", pipex.cmd);
	if (!pipex.cmd)
	{
		fd_printf(2, "pipex: %s: command not found\n", pipex.cmds_args[0]);
		ft_free(&pipex, 'c');
		exit(127);
	}
	execve(pipex.cmd, pipex.cmds_args, env);
	exit(1);
}

void	parent(t_pipex pipex, char **argv, char **env)
{
	pipex.outfile = open(argv[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (access(argv[4], W_OK) < 0)
	{
		fd_printf(2, "pipex: %s: permission denied\n", argv[4]);
		exit(1);
	}
	dup2(pipex.pipe[0], 0);
	close(pipex.pipe[1]);
	dup2(pipex.outfile, 1);
	pipex.cmds_args = ft_split_cmds(argv[3], ' ');
	if (pipex.cmds_args[0] == NULL)
		exit(1);
	pipex.cmd = wayfinder(pipex.cmd_p, pipex.cmds_args[0]);
	// fd_printf(2, "cmd in p = %s\n", pipex.cmd);
	if (!pipex.cmd)
	{
		fd_printf(2, "pipex: %s: command not found\n", pipex.cmds_args[0]);
		ft_free(&pipex, 'c');
		exit(127);
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
		ft_putstr_fd("Invalid number of arguments", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipex.pipe) < 0)
	{
		fd_printf(STDERR_FILENO, "We are clogged..");
		exit (126);
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

//Do I need two cmds_args for parent and child process?