#ifndef T_PIPEX_H
# define T_PIPEX_H

typedef struct s_pipex
{
	char	**env;
	char	**cmds;
	char	***args;

	int		p[2];
	int		p2[2]
	pid_t	*child;

	int		cmd_count;
	int		pipe_count; 

}t_pipex;

t_pipex	*malloc_pipex(void);
t_pipex	set_pipex(void);
void	destroy_pipex(t_pipex pipex);
void	free_pipex(t_pipex pipex);

#endif