/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttremel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:11:41 by soviet            #+#    #+#             */
/*   Updated: 2025/03/06 14:55:46 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	open_fd(int fd[2], char **av, char ac)
{
	int		ret;

	ret = open(av[0], O_RDONLY, 0777);
	fd[0] = ret;
	ret = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	fd[1] = ret;
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_cmd	**cmds;
	pid_t	pid;
	int		fd[2];

	if (ac <= 1)
		error_handler(0, NULL);
	if (ac != 5)
		error_handler((ac > 5), NULL);
	cmds = parser(&av[2], (ac - 3), env);
	if (!cmds)
		exit(-1);
	cmds[0]->in_file = ft_strdup(av[1]);
	cmds[0]->out_file = ft_strdup(av[ac - 1]);
	if (!(*cmds)->in_file || !(*cmds)->out_file
		|| open_fd(fd, &av[1], ac - 1) == -1)
	{
		free_for_all(cmds);
		exit(0);
	}
	pid = pipex(ac - 3, cmds, fd);
	close_fd(fd);
	free_for_all(cmds);
	wait_all_pid(pid, ac - 3);
}
