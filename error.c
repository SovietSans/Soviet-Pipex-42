/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttremel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:07:00 by soviet            #+#    #+#             */
/*   Updated: 2025/03/06 16:13:52 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/pipex.h"

static int	access_to_cmd(t_cmd *cmd)
{
	char	*dup;

	dup = ft_strdup(cmd->path);
	if (!dup)
		return (-1);
	if (access(dup, F_OK | X_OK) == -1)
		error_msg(2, cmd->flags[0]);
	free(dup);
	return (0);
}

static int	access_to_file(char *in_file, char *out_file)
{
	char	*dup;

	if (in_file)
	{
		dup = ft_strdup(in_file);
		if (!dup)
			return (-1);
		if (access(dup, F_OK | R_OK) == -1)
			error_msg(3, dup);
	}
	if (out_file)
	{
		dup = ft_strdup(out_file);
		if (!dup)
			return (-1);
		if (access(dup, X_OK) == -1)
			error_msg(4, dup);
	}
	free(dup);
	return (0);
}

int	check_all_access(t_cmd **cmds)
{
	size_t	i;

	i = 0;
	if (access_to_file(cmds[0]->in_file, NULL) == -1)
	{
		free_for_all(cmds);
		return (-1);
	}
	while (cmds[i])
	{
		if (access_to_cmd(cmds[i]))
		{
			free_for_all(cmds);
			return (-1);
		}
		i++;
	}
	if (access_to_file(NULL, cmds[0]->out_file) == -1)
	{
		free_for_all(cmds);
		return (-1);
	}
	return (0);
}

void	error_handler(int err, char *error)
{
	error_msg(err, error);
	exit(EXIT_FAILURE);
}

void	error_msg(int err, char *error)
{
	if (err == 0)
		ft_printf_fd(
			"pipex : error : there's too few arguments, 4 needed\n", 2);
	else if (err == 1)
		ft_printf_fd(
			"pipex : error : there's too many arguments, 4 needed\n", 2);
	else if (err == 2)
		ft_printf_fd(
			"pipex : error : command \"%s\" doesn't exist\n", 2, error);
	if (err == 3)
		ft_printf_fd(
			"pipex : error : can't access to file : %s\n", 2, error);
	if (err == 4)
		ft_printf_fd(
			"pipex : error : permission denied : %s\n", 2, error);
}
