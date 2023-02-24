/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/19 19:47:14 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/25 00:45:56 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

/*
	Redirects the input and output file descriptors by duplicating
	the given fds to the standard input and standard output respectively.
*/
static void	io_redirect(int input, int output, t_pipex *p)
{
	if (dup2(input, STDIN_FILENO) == -1)
	{
		ft_error(p, strerror(errno), NULL, 1);
	}
	if (dup2(output, STDOUT_FILENO) == -1)
	{
		ft_error(p, strerror(errno), NULL, 1);
	}
}

/* Kiek ff hoe het zit met redirection of multiple pipes.*/
static void	child(t_pipex *p)
{
	// get_infile(p);
	if (p->child == 0)
		io_redirect(p->infile, p->pipe_arr[1], p);
	else if (p->child == p->cmd_cnt - 1)
		io_redirect(p->pipe_arr[2 * p->child - 2], p->outfile, p);
	else
		io_redirect(p->pipe_arr[2 * p->child - 2],
			p->pipe_arr[2 * p->child + 1], p);
	close_fd(p);
	if (p->cmd_args == NULL || p->cmd_p == NULL)
		clean_up(p, 127);
	if (execve(p->cmd_p, p->cmd_args, p->envp) == -1)
		ft_error(p, p->cmd_args[0], strerror(errno), 1);
}

static int	parent(t_pipex *p)
{
	pid_t	wpid;
	int		status;
	int		exit_c;

	// get_outfile(p);
	close_fd(p);
	p->child--;
	exit_c = 1;
	while (p->child >= 0)
	{
		wpid = waitpid(p->pids[p->child], &status, 0);
		if (wpid == p->pids[p->cmd_cnt - 1])
		{
			if ((p->child == (p->cmd_cnt -1)) && WIFEXITED(status))
				exit_c = WEXITSTATUS(status);
		}
		p->child--;
	}
	free(p->pipe_arr);
	free(p->pids);
	return (exit_c);
}

int	pipex(t_pipex *p)
{
	int	exit_c;

	if (pipe(p->pipe_arr) == -1)
		ft_error(p, strerror(errno), NULL, 1);
	p->child = 0;
	while (p->child < p->cmd_cnt)
	{
		p->cmd_args = ft_split_cmds(p->argv[p->child + 2 + p->heredoc], ' ');
		if (!p->cmd_args)
			ft_error(p, "something went wrong in split", NULL, 1);
		p->cmd_p = get_cmd(p->cmd_args[0], p);
		p->pids[p->child] = fork();
		if (p->pids[p->child] == -1)
			ft_error(p, "spooned", strerror(errno), 1);
		else if (p->pids[p->child] == 0)
			child(p);
		free_arr(p->cmd_p, p->cmd_args);
		p->child++;
	}
	exit_c = parent(p);
	if (p->heredoc == 1)
		unlink(".heredoc.tmp");
	return (exit_c);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pip;
	int		exit_code;

	if (argc < 5)
	{
		if (argc >= 2 && !ft_strcmp(argv[1], "here_doc"))
			ft_error(NULL, "here_doc", NULL, 1);
		ft_error(NULL, "standard", NULL, 1);
	}
	else if (argc < 6 && !ft_strcmp(argv[1], "here_doc"))
	{
		ft_error(NULL, "here_doc", NULL, 1);
	}
	pip = init(argc, argv, envp);
	exit_code = pipex(&pip);
	return (exit_code);
}

/*
			FIX HEADERFILE(S)
			TEST
			finish parsing -- DONE
			add process exec -- DONE
			start on exit and error handling
				$? to fnd exit_code
			CHECK FOR !cmd[0] --> mb this reason why I segfault?
			Split bonus and mand, this is also fucking us up.
					0	Successful exit without errors
					1	One or more generic errors encountered upon exit
					2	Incorrect usage, such as invalid options or missing arguments
					126	Command found but is not executable
					127 Command not found. (Problem with $PATH || typo)
	Fix return codes. [Can I just return errno?]

	Maybe someday if you feel like it, make a search and match for the commands	
	using structs and then their own little struct to store all that shizzle.
	could be funny.
*/