/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   t_pipex.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 16:21:32 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/19 16:27:52 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"
#include "../headers/t_pipex.h"

t_pipex *malloc(void)
{
    t_pipex *pipex;

    pipex = (t_pipex *)malloc(sizeof(t_pipex pipex));
    if(!pipex)
        ft_error(ERR_PIPE);
    *pipex = set_pipex();
    return (pipex);
}

t_pipex set_pipex(void)
{
    t_pipex pipex;

    ft_memset(&pipex, 0, sizeof(t_pipex));
	pipex.env = NULL;
	pipex.args = NULL;
	pipex.cmds = NULL;
	pipex.child = NULL;
	pipex.pipe = NULL;
    return (pipex);
}

void	free_pipex(t_pipex pipex)
{
	destroy_pipex(pipex);
	free(pipex);
}
