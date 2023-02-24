/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd_parsing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/19 23:25:42 by ewehl         #+#    #+#                 */
/*   Updated: 2023/02/24 22:14:33 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/pipex.h"

static char	*get_env(char **envp)
{
	char	*path;
	size_t	idx;

	idx = 0;
	while (envp[idx] && ft_strncmp(envp[idx], "PATH", 4))
		idx++;
	if (!envp[idx])
		path = NULL;
	else
		path = ft_strdup(ft_strtrim(envp[idx], "PATH="));
	return (path);
}

static char	**append_slash(char **paths)
{
	char	*tmp;
	size_t	idx;

	idx = 0;
	while (paths[idx])
	{
		tmp = paths[idx];
		paths[idx] = ft_strjoin(tmp, "/");
		free_arr(tmp, NULL);
		idx++;
	}
	return (paths);
}

static char	**get_paths(char **envp)
{
	char	*env_path;
	char	**tmp_p;
	char	**paths;

	env_path = get_env(envp);
	if (!env_path)
		return (NULL);
	tmp_p = ft_split(env_path, ':');
	free_arr(env_path, NULL);
	if (!tmp_p)
		return (NULL);
	paths = append_slash(tmp_p);
	if (!paths)
		return (NULL);
	return (paths);
}

static char	*cmd_pathfinder(char *cmd, char **paths)
{
	size_t	idx;
	char	*the_way;

	idx = 0;
	the_way = NULL;
	if (!cmd || !paths)
		return (NULL);
	while (paths[idx])
	{
		the_way = ft_strjoin(paths[idx], cmd);
		if (!the_way)
		{
			free_arr(NULL, paths);
			ft_error(NULL, "something went wrong in strjoin", NULL, 1);
		}
		if (access(the_way, F_OK | X_OK) == 0)
			return (the_way);
		free_arr(the_way, NULL);
		idx++;
	}
	return (NULL);
}

char	*get_cmd(char *cmd, t_pipex *pipex)
{
	char	**env_p;
	char	*cmd_p;

	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	env_p = get_paths(pipex->envp);
	cmd_p = cmd_pathfinder(cmd, env_p);
	if (!cmd_p)
		fd_printf(2, "pipex: %s: command not found\n", cmd);
	free_arr(NULL, env_p);
	return (cmd_p);
}
