/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_management_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/20 21:29:23 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/27 06:33:27 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex_bonus.h"

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
	if (p->heredoc == 1)
	{
		heredoc(p);
		p->infile = open(".heredoc.tmp", O_RDONLY);
		if (p->infile == -1)
			ft_error(p, NULL, NULL, 1);
		p->outfile = open(p->argv[p->argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (p->outfile == -1)
			ft_error(p, NULL, NULL, 1);
	}
	else
	{
		p->outfile = open(p->argv[p->argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
		p->infile = open(p->argv[1], O_RDONLY, 0644);
	}
}

/*
	Reads from STDIN and stores the lines read in [tmp_fd] 
	until it finds the specified limiter.
*/
void	heredoc(t_pipex *p)
{
	int		tmp_fd;
	int		std_in;
	char	*line;

	tmp_fd = open(".heredoc.tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd == -1)
		ft_error(p, strerror(errno), ".heredoc.tmp", 1);
	std_in = dup(STDIN_FILENO);
	fd_printf(1, "here_doc > ");
	line = get_next_line(std_in);
	while (line)
	{
		if ((!ft_strncmp(line, p->argv[2], ft_strlen(p->argv[2]))
				&& ft_strlen(p->argv[2]) == (ft_strlen(line)) - 1))
			close(std_in);
		else
		{
			fd_printf(tmp_fd, line);
			fd_printf(1, "here_doc > ");
		}
		free(line);
		line = get_next_line(std_in);
	}
	close(tmp_fd);
}
