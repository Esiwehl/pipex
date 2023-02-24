/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 21:25:05 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/25 00:45:46 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

/*
	Initializes a data structure with no data in it. Sets strings to NULL
	and ints to -1, because 0 is a valid fd and should not be used for
	initialization.
	Returns the newly initialized data structure.
*/
t_pipex	clean_init(void)
{
	t_pipex	pipex;

	pipex.envp = NULL;
	pipex.argc = -1;
	pipex.argv = NULL;
	pipex.heredoc = 0;
	pipex.infile = -1;
	pipex.outfile = -1;
	pipex.pipe_arr = NULL;
	pipex.cmd_cnt = -1;
	pipex.child = -1;
	pipex.pids = NULL;
	pipex.cmd_args = NULL;
	pipex.cmd_p = NULL;
	return (pipex);
}

/*
	Creates a pipe (pair of fds) for each command.
*/
void	blow_pipes(t_pipex *p)
{
	int	idx;

	idx = 0;
	while (idx < p->cmd_cnt - 1)
	{
		if (pipe(&(p->pipe_arr[2 * idx])) == -1)
			ft_error(p, strerror(errno), NULL, 1);
		idx++;
	}
}

/*print [pipex.pids] later uit om te testen.*/
/*
	Initializes a new data structure to hold pipex information. Stores the
	arguments, the environment pointer, opens the input fd and opens/creates
	the output fd.
	Returns the data structure.
*/
t_pipex	init(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	pipex = clean_init();
	pipex.argc = argc;
	pipex.argv = argv;
	pipex.envp = envp;
	if (!ft_strcmp(argv[1], "here_doc"))
		pipex.heredoc = 1;
	get_files(&pipex);
	pipex.cmd_cnt = argc - 3 - pipex.heredoc;
	pipex.pids = malloc(sizeof(pipex.pids) * (pipex.cmd_cnt - 1));
	if (!pipex.pids)
		ft_error(&pipex, "unexpected error", "init()", 1);
	pipex.pipe_arr = malloc(sizeof(pipex.pipe_arr) * 2 * pipex.cmd_cnt);
	if (!pipex.pipe_arr)
		ft_error(&pipex, "unexpected error", "init()", 1);
	blow_pipes(&pipex);
	return (pipex);
}
