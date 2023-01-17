/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 14:23:02 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/17 17:15:30 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(char *str)
{
	ft_printf(str);
	// At some point use perror perhaps?
	return (-1);
}

/*char *get_path(char **string)
{
	char *path;

	path = ft_strchr("PATH=", 5);
	return (path);
}*/

int	main(int argc, char *argv[], char *envp[])
{	
	if (argc != 5)
		return (ft_error(ERR_INPUT));
	else
	{
		for (int idx = 0; envp[idx]; idx++)
			ft_printf("%s \n", envp[idx]);
		ft_printf("argv[0] = %s\n", argv[0]);
		int fd = open("src/pipex.c", O_RDONLY);
		for (int jdx = 0; jdx < 46; jdx++)
			ft_printf("%s", get_next_line(fd));
		close(fd);
	}
	return (0);
}
