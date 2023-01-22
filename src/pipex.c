/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 14:23:02 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/22 21:03:22 by ewehl         ########   odam.nl         */
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

char **path_parser(char *full_path)
{
	char **paths;
	
	paths = ft_split(full_path, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

char *find_path(char **paths)
{
	char *the_way;
	size_t idx;

	idx = 0;
	while (paths[idx])
	{
		the_way = ft_strappend(paths[idx], '/' + cmd[0])
		if (access(paths[idx], X_OK))
		idx++;
	}
}

int main(int argc, char *argv[], char *envp[])
{
	static int x = 1;
	int fd = open("tester.c", O_RDONLY);
	for(int i = 0; i < 5; i++)
	{
		printf("Does this also get printed");
		int f = fork();
		printf("fork ret = %d\n", f);
		if (f == 0)
		{
			printf("[kid] pid %d from [parent] pid %d\n", getpid(), getppid());
			if (execve(argv[0], argv[1], get_path(envp)));
			exit(0);
		}
		else
			printf("[%d]They don't show this... kidpid [%d]\n", x++, getpid());
	}
	close(fd);
	printf("x = %d\n", x);
	return (0);
}

/*int	main(int argc, char *argv[], char *envp[])
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
}*/
