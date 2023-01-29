/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ewehl <ewehl@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/16 14:23:02 by ewehl         #+#    #+#                 */
/*   Updated: 2023/01/29 18:12:44 by ewehl         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(void)
{
	char	*msg;

	msg = strerror(errno);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(errno);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
}

void	ft_free(t_pipex *pipex, char flag)
{
	size_t	idx;

	idx = 0;
	if(flag == 'p')
		close_pipes(pipex);
	while(pipex->cmd_p[idx])
	{
		free(pipex->cmd_p[idx]);
		idx++;
	}
	free(pipex->cmd_p);
}

int	check_cmd(char *cmd)
{
	if (access(cmd, F_OK) < 0)
	{
		ft_error();
	}
	if (access(cmd, X_OK) < 0)
	{
		ft_putstr_fd("Permissions denied, weeb", 2);
		exit(126);
	}
	return (1);
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
		path = "/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin:/bin:/sbin:.";
		return (path);
	}
	path = ft_strdup(ft_strtrim(env[idx], "PATH="));
	return (path);
}

char *get_cmd(char **paths, char *cmd)
{
	char	*the_way;
	char	*tmp = NULL;
	size_t	idx;

	idx = 0;
	while (paths[idx])
	{
		paths[idx] = ft_strappend(paths[idx], "/");
		the_way = ft_strjoin(paths[idx], cmd);
		free(tmp);
		// printf("The way = %s\n", the_way);
		if (access(the_way, F_OK) == 0)
		{
			check_cmd(the_way);
			return (the_way);
		}
		free(the_way);
		idx++;
	}
	ft_error();
	return (NULL);
}

int	ft_fork(t_pipex pipex, char **argv, char **envp)
{
	pipex.pid = fork();
	// printf("pid:%d\n", pipex.pid);
	if (pipex.pid == 0)
	{
		// printf("Here :D\n");
		child(pipex, argv, envp);
	}
	else
		parent(pipex, argv, envp);
	return (pipex.pid);
}

void	child(t_pipex pipex, char **argv, char **env)
{
	pipex.infile = open(argv[1], O_RDONLY);
	// printf("HUH? %d || pid: %d || ppid: %d\n", pipex.infile, getpid(), getppid());
	if (access(argv[1], F_OK) < 0)
		ft_error();
	if (access(argv[1], R_OK) < 0)
		ft_error();
	dup2(pipex.pipe[1], 1);
	close(pipex.pipe[0]);
	dup2(pipex.infile, 0);
	close(pipex.infile);
	pipex.cmds_args = ft_split(argv[2], ' ');
	// printf("Child cmds_args= %s\n", pipex.cmds_args[0]);
	pipex.cmd = get_cmd(pipex.cmd_p, pipex.cmds_args[0]);
	// printf("cmd = %s\n", pipex.cmd);
	if (!pipex.cmd)
	{
		ft_free(&pipex, 'c');
		ft_error();
		//ft_putstr_fd("Command not found\n", 2);
		//exit(127);
	}
	execve(pipex.cmd, pipex.cmds_args, env);
	exit(1);
}

void	parent(t_pipex pipex, char **argv, char **env)
{
	pipex.outfile = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	// printf("Pid = %d\tPpid = %d\n", getpid(), getppid());
	if (access(argv[4], W_OK) < 0)
	{
		ft_error();
		//ft_putstr_fd("permission denied\n", 2);
		//exit(1);
	}
	dup2(pipex.pipe[0], 0);
	close(pipex.pipe[1]);
	dup2(pipex.outfile, 1);
	close(pipex.outfile);
	pipex.cmds_args = ft_split(argv[3], ' ');
	// printf("Parent cmds_args= %s\n", pipex.cmds_args[0]);
	if (pipex.cmds_args[0] == NULL)
		exit(1);
	pipex.cmd = get_cmd(pipex.cmd_p, pipex.cmds_args[0]);
	// printf("P_cmd = %s\n", pipex.cmd);
	if (!pipex.cmd)
	{
		ft_free(&pipex, 'p');
		ft_error();
		//ft_putstr_fd("Command not found\n", 2);
		//exit(127);
	}
	execve(pipex.cmd, pipex.cmds_args, env);
	exit(1);
}

/*void print_array(char **array)
{
	size_t idx;

	idx = 0;
	while (array[idx])
	{
		ft_printf("%s\n", array[idx]);
		idx++;
	}
}*/

int	main(int argc, char *argv[], char *envp[])
{	
	t_pipex		pipex;
	int			stat;

	if (argc != 5)
	{
		ft_putstr_fd("Wrong number of inputs", 2);
		return (1);
	}
	if (pipe(pipex.pipe) < 0)
	{
		ft_error();
		//ft_putstr_fd("Pipe failed", 2);
		//return (1);
	}
	// printf("MAIN pid: %d\t ppid: %d\n", getpid(), getppid());
	pipex.paths = get_path(envp);
	// printf("pipex.paths = %s\n", pipex.paths);
	pipex.cmd_p = ft_split(pipex.paths, ':');
	// printf("\t\t\033[0;36m THE CMD PATHS\033[0;37m\n");
	// print_array(pipex.cmd_p);
	// printf("\t\t\t\033[0;36m FIN \033[0;37m\n");
	if (ft_fork(pipex, argv, envp) < 0)
		ft_error();
	close_pipes(&pipex);
	waitpid(pipex.pid, &stat, 0);
	ft_free(&pipex, 'p');
	return (0);
}
