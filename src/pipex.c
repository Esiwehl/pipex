/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 14:23:02 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/19 18:48:37 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(char *str)
{
	ft_printf(str);
	// At some point use perror perhaps?
	return (-1);
}

char *get_path(char **env)
{
	char *path;
	size_t idx;

	idx = 0;
	while (env[idx] && ft_strncmp(env[idx], "PATH", 4))
		idx++;
	if (env[idx] == NULL)
	{
		ft_error(ERR_PATH);
		return (NULL); //Maybe some exit instead..?
	}
	path = ft_strdup(env[idx]);
	printf("env[%zu]: %s\n", idx, env[idx]);
	return (path);
}



int	main(int argc, char *argv[], char *envp[])
{	
	char *path;

	if (argc != 5)
		return (ft_error(ERR_INPUT));
	else
	{
		ft_printf("argv[0] = %s\n", argv[0]);
		path = get_path(envp);
		ft_printf("path: %s", path);
		free(path);
	}
	return (0);
}
