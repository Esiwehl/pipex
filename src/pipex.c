/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 14:23:02 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/16 14:45:36 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	ft_error(char *str)
{
	ft_printf(str);
	// At some pointn use perror perhaps?
	return (-1);
}


int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 5)
		return (ft_error(ERR_INPUT));
	else
	{
		ft_printf("Snelle check\n");
		ft_printf("%s \n", envp[0]);
		ft_printf("argv[0] = %s\n", argv[0]);
	}
	return (0);
}
