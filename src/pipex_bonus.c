/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/07 15:50:33 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/09 00:30:01 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"

int is_valid_fd(int fd)
{
    return fcntl(fd, F_GETFD) != -1 || errno != EBADF;
}

void	command_exe(t_pipex pipex, char *cmd)
{
	pipex.cmds_args = ft_split_cmds(cmd, ' ');
	if (pipex.cmds_args[0] == NULL)
		exit(1);
	pipex.cmd = wayfinder(pipex.cmd_p, pipex.cmds_args[0]);
	fd_printf(2, "cmd exe: cmd = %s\n", pipex.cmd);
	if (!pipex.cmd)
	{
		fd_printf(2, "pipex: %s: command not found\n", pipex.cmds_args[0]);
		ft_free(&pipex, 'p');
		exit(127);
	}
	execve(pipex.cmd, pipex.cmds_args, pipex.cmd_p); //idk if parsed env works
	fd_printf(2, "pipex: %s: execve failed.\n", pipex.cmds_args);
	ft_free(&pipex, 'p');
	exit(1);
}

void	process_exe(t_pipex pipex, char *cmd)
{
	pipex.pid = fork();
	if (pipex.pid < 0)
	{
		fd_printf(2, "Fork failed\n");
		exit (1);
	}
	else if (pipex.pid == 0)
	{
		fd_printf(2, "CHILD Here\n");
		close(pipex.pipe[0]);
		char *tmp_piper = ft_itoa(pipex.pipe[0]);
		char *tmp_pipew = ft_itoa(pipex.pipe[1]);
		fd_printf(2, "in process pipe[0]: %s\tpipe[1]: %s\n", tmp_piper, tmp_pipew);
		free(tmp_piper); free(tmp_pipew);
		if (dup2(pipex.pipe[1], 1) < 0)
		{
			int fddup = is_valid_fd(pipex.pipe[1]);
			char *fdupc = ft_itoa(fddup);
			fd_printf(2, "fdupc = %s\n", fdupc);
			free(fdupc);
			fd_printf(2, "pipex: c dup failed\n");
			exit (1);
		}
		close(pipex.pipe[1]);
		command_exe(pipex, cmd);
	}
	else
	{
		fd_printf(2, "MAIN Here\n");
		close(pipex.pipe[1]);
		if (dup2(pipex.pipe[0], 0) < 0)
		{
			fd_printf(2, "pipex: m dup failed\n");
			exit (1);
		}
		close(pipex.pipe[0]);
		waitpid(pipex.pid, NULL, 0);
	}
}

void	write_till_limit(t_pipex *pipex, char *limit)
{
	char *line;
	char *tmp_piper = ft_itoa(pipex->pipe[0]);
	char *tmp_pipew = ft_itoa(pipex->pipe[1]);
	fd_printf(2, "pipe[0]: %s\tpipe[1]: %s\n", tmp_piper, tmp_pipew);
	free(tmp_piper); free(tmp_pipew);
	close(pipex->pipe[0]);
	fd_printf(1, "heredoc> ");
	line = get_next_line(0);
	while (line)
	{
		fd_printf(2, "GNL Here\n");
		if (ft_strncmp(limit, line, ft_strlen(limit)) == 0)
		{
			free(line);
			close(pipex->pipe[1]);
			exit(0);
		}
		fd_printf(1, "heredoc> ");
		fd_printf(pipex->pipe[0], "%s\n", line);						//You changed pipe[1] from pipe[0]
		free(line);
		line = get_next_line(0);
	}
	free(line);
	close(pipex->pipe[1]);
	fd_printf(2, "an error occurred while trying to write to fd\n");
}

void	heredoc(t_pipex *pipex, int argc, char *limiter)
{
	if (argc < 6)
	{
		fd_printf(2, "Invalid number of arguments");
		exit(1);
	}	
	pipex->pid = fork();
	if (pipex->pid == -1)
	{
		fd_printf(2, "Fork failed\n");
		exit(1);
	}
	if (pipex->pid == 0)
		write_till_limit(pipex, limiter);
	else
	{
		close(pipex->pipe[1]);
		dup2(pipex->pipe[0], 0);
		close(pipex->pipe[0]);
		waitpid(pipex->pid, NULL, 0);
	}
}

void	init_pipex(t_pipex *pipex, int argc, char *argv[])
{	
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		pipex->cmd_idx = 3;
		heredoc(pipex, argc, argv[2]);
		pipex->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND,
				0644);
		if (pipex->outfile < 0)
		{
			fd_printf(2, "pipex: %s Error opening outfile\n", argv[argc - 1]);
			exit (1);
		}
	}
	else
	{
		pipex->cmd_idx = 2;
		pipex->infile = open(argv[1], O_RDONLY);
		pipex->outfile = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
		if (dup2(pipex->infile, STDIN_FILENO) < 0)
		{
			fd_printf(2, "pipex: %s: dup failed\n", argv[argc - 1]);
			exit (1);
		}
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc < 5)
	{
		fd_printf(2, "Not enough arguments.\n");
		fd_printf(2, "Format ./pipex infile cmd1 cmd2 .. cmdx outfile\n");
		exit (1);
	}
	if (pipe(pipex.pipe) < 0)
	{
		fd_printf(2, "We are clogged..");
		exit (126);
	}
	char *tmp_piper = ft_itoa(pipex.pipe[0]);
	char *tmp_pipew = ft_itoa(pipex.pipe[1]);
	fd_printf(2, "in main pipe[0]: %s\tpipe[1]: %s\n", tmp_piper, tmp_pipew);
	free(tmp_piper); free(tmp_pipew);
	pipex.paths = get_path(envp);
	pipex.cmd_p = ft_split(pipex.paths, ':');
	init_pipex(&pipex, argc, argv);
	while (pipex.cmd_idx < (argc - 2))
	{
		fd_printf(2, "Here\n");
		char *tmp_idx = ft_itoa(pipex.cmd_idx);
		fd_printf(2, "pipex.cmd_idx = %s\n", tmp_idx);
		free(tmp_idx);
		process_exe(pipex, argv[pipex.cmd_idx++]);
	}
	if (dup2(pipex.outfile, STDOUT_FILENO) < 0)
		fd_printf(2, "pipex: %s: f dup failed\n", argv[argc - 1]);
	command_exe(pipex, argv[argc - 2]);
}
