/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_management.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 21:29:23 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/27 06:09:29 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

void	check_files(t_pipex *p, int io)
{
	if (io == 1)
	{
		if (access(p->argv[1], F_OK) < 0)
		{
			ft_error(NULL, p->argv[1], strerror(errno), 0);
		}
		if (access(p->argv[1], R_OK) < 0)
		{
			ft_error(NULL, p->argv[1], "Permission denied", 0);
		}
	}
	else
	{
		if (access(p->argv[p->argc - 1], W_OK) < 0)
			ft_error(NULL, p->argv[p->argc - 1], strerror(errno), 1);
	}
}

/*
	For infile
		Sets the input file descriptor for pipex.
		If heredoc is specified, a temporary file will be created,
		otherwise the specified input file will be opened.
	For outfile
		Opens/creates an output file. If here_doc is specified, the
		output file will be appended, otherwise it will be overwritten.
*/
void	get_files(t_pipex *p)
{
	p->outfile = open(p->argv[p->argc - 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	p->infile = open(p->argv[1], O_RDONLY, 0644);
}
