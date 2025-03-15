/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttremel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:11:41 by ttremel           #+#    #+#             */
/*   Updated: 2025/03/06 14:55:50 by ttremel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	create_here_doc(int p_fd[2], char **av)
{
	size_t	lim_size;
	char	*line;

	line = NULL;
	lim_size = ft_strlen(av[1]);
	while (1)
	{
		ft_printf_fd("here_doc>", 2);
		line = get_next_line(0);
		if (!line)
		{
			close(p_fd[0]);
			close(p_fd[1]);
			return (-1);
		}
		line[ft_strlen(line) - 1] = 0;
		if (ft_strncmp(av[1], line, lim_size + 1) == 0)
			break ;
		ft_printf_fd("%s\n", p_fd[1], line);
		free(line);
	}
	free(line);
	close(p_fd[1]);
	return (0);
}

static int	here_doc(char **av)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		close(p_fd[0]);
		close(p_fd[1]);
		return (-1);
	}
	if (pid)
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		wait(NULL);
	}
	else
		if (create_here_doc(p_fd, av) == -1)
			return (-1);
	return (p_fd[0]);
}

static int	open_fd(int fd[2], char **av, char ac, int h_doc)
{
	int		ret;

	if (h_doc)
		ret = here_doc(av);
	else
		ret = open(av[0], O_RDONLY, 0777);
	fd[0] = ret;
	if (h_doc)
		ret = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		ret = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	fd[1] = ret;
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_cmd	**cmds;
	pid_t	pid;
	int		fd[2];
	int		here_doc;

	if (ac <= 1)
		error_handler(0, NULL);
	here_doc = (ft_strcmp(av[1], "here_doc") == 0);
	if (ac < 5 || (ac < 6 && here_doc))
		error_handler(0, NULL);
	cmds = parser(&av[2 + here_doc], (ac - (3 + here_doc)), env);
	if (!cmds)
		return (1);
	cmds[0]->in_file = ft_strdup(av[1]);
	cmds[0]->out_file = ft_strdup(av[ac - 1]);
	if (!(*cmds)->in_file || !(*cmds)->out_file
		|| open_fd(fd, &av[1], ac - 1, here_doc) == -1)
	{
		free_for_all(cmds);
		return (-1);
	}
	pid = pipex((ac - (3 + here_doc)), cmds, fd);
	close_fd(fd);
	free_for_all(cmds);
	wait_all_pid(pid, ac - (3 + here_doc));
}
