/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 15:50:33 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/07 22:25:37 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"

void	write_till_limit(t_pipex pipex, char *limit)
{
	char *line;

	close(pipex.pipe[0]);
	fd_printf(1, "heredoc> ");
	line = get_next_line(0);
	while (line)
	{
		if (ft_strcmp(limit, line) == 0)
		{
			free(line);
			close(pipex.pipe[1]);
			exit(0);
		}
		fd_printf(1, "heredoc> ");
		fd_printf(pipex.pipe[1], "%s\n", line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(pipex.pipe[1]);
	fd_printf(2, "an error occurred while trying to write to fd\n");
}


void	heredoc(t_pipex pipex, int argc, char *argv[])
{
	if (argc < 6)
	{
		fd_printf(2, "Invalid number of arguments");
		exit(1);
	}	
	if (pipe(pipex.pipe) < 0)
	{
		fd_printf(STDERR_FILENO, "We are clogged..");
		exit (126);
	}
	pipex.pid = fork();
	if (pipex.pid == -1)
	{
		fd_printf(2, "Fork failed\n");
		exit(1);
	}
	if (pipex.pid == 0)
		write_till_limit(pipex, argv[1]);
	else
	{
		close(pipex.pipe[1]);
		dup2(pipex.pipe[0], 0);
		close(pipex.pipe[0]);
		waitpid(pipex.pid, NULL, 0);
	}
}

int	check_input(t_pipex pipex, int argc, char *argv[])
{
	int cmd_pos;

	cmd_pos = 0;
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		heredoc(pipex, argc, argv); // Do something about appending and truncating.
		cmd_pos = 3;
	}
	else
		cmd_pos = 2;
	pipex.cmd_idx = cmd_pos;
	return (cmd_pos);
}

static void	process_uno(t_pipex pipex, char *argv[], char *envp[])
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
	pipex.cmd_idx = 3;
	dup2(pipex.pipe[1], 1);
	dup2(pipex.infile, 0);
	pipex.cmds_args = ft_split_cmds(argv[pipex.cmd_idx++], ' ');
	pipex.cmd = wayfinder(pipex.cmd_p, pipex.cmds_args[0]);
	if (!pipex.cmd)
	{
		fd_printf(2, "pipex: %s: command not found\n", pipex.cmds_args[0]);
		ft_free(&pipex, 'c');
		exit(127);
	}
	execve(pipex.cmd, pipex.cmds_args, envp);
	exit(1);
}

void	process_dos(t_pipex pipex, int argc, char *argv[], char *envp[])
{
	pipex.outfile = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	fd_printf(pipex.outfile, "Do i get here at all? %s\n", argv[argc -1]);
	if (access(argv[argc - 1], W_OK) < 0)
	{
		fd_printf(2, "pipex: %s: permission denied\n", argv[argc - 1]);
		exit(1);
	}
	dup2(pipex.pipe[0], 0);
	close(pipex.pipe[1]);
	dup2(pipex.outfile, 1);
	pipex.cmds_args = ft_split_cmds(argv[argc - 2], ' ');
	if (pipex.cmds_args[0] == NULL)
		exit(1);
	pipex.cmd = wayfinder(pipex.cmd_p, pipex.cmds_args[0]);
	if (!pipex.cmd)
	{
		fd_printf(2, "pipex: %s: command not found\n", pipex.cmds_args[0]);
		ft_free(&pipex, 'p');
		exit(127);
	}
	execve(pipex.cmd, pipex.cmds_args, envp);
	exit(1);
}

static void ft_fork(t_pipex pipex, int argc, char *argv[], char *envp[])
{
	pipex.pid = fork();
	if (pipex.pid == -1)
	{
		fd_printf(2, "Fork failed\n");
		exit(EXIT_FAILURE);
	}
	if (pipex.pid == 0)
	{
		close(pipex.pipe[0]);
		process_uno(pipex, argv, envp);
	}
	else
	{
		close(pipex.pipe[1]);
		waitpid(pipex.pid, NULL, 0);
		process_dos(pipex, argc, argv, envp);// Do I need this..?
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex		pipex;
	int			cmd_start;

	if (argc < 5)
	{
		fd_printf(2, "Invalid number of arguments");
		exit(1);
	}
	if (pipe(pipex.pipe) < 0)
	{
		fd_printf(STDERR_FILENO, "We are clogged..");
		exit (126);
	}
	pipex.paths = get_path(envp);
	pipex.cmd_p = ft_split(pipex.paths, ':');
	cmd_start = check_input(pipex, argc, argv);
	while (cmd_start < argc - 2)
	{
		ft_fork(pipex, argc, argv, envp);
		cmd_start++;
	}
	close_pipes(&pipex);
	ft_free(&pipex, 'p');
}