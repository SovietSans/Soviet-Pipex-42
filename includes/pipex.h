/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soviet  <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:02:57 by soviet            #+#    #+#             */
/*   Updated: 2025/03/06 15:18:44 by soviet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>
# include <sys/wait.h>
# include "../libft_utils/libft.h"
# include "../libft_utils/printf/ft_printf.h"
# include "../libft_utils/get_next_line/get_next_line.h"

typedef struct s_cmd
{
	char	*in_file;
	char	*out_file;
	char	*path;
	char	**env;
	char	**flags;
}			t_cmd;

int		pipex(int argc, t_cmd **cmds, int fd[2]);
int		check_all_access(t_cmd **cmds);
void	wait_all_pid(pid_t pid, int ac);
void	free_all(char **list);
void	free_for_all(t_cmd **list);
void	error_handler(int err, char *error);
void	error_msg(int err, char *error);
void	close_n_exit(int fd[2], t_cmd **cmds);
void	close_all(int p_fd[2], int fd[2], t_cmd **cmds);
void	close_fd(int fd[2]);
void	ft_exec(int p_fd[2], int fd[2], t_cmd **cmds, int i);
void	child_process(int p_fd[2], int fd[2], t_cmd ***cmds, int i);
void	parent_process(int p_fd[2], int fd[2], t_cmd ***cmds);
pid_t	last_process(int p_fd[2], int fd[2], int argc, t_cmd ***cmds);
t_cmd	**parser(char **argv, int argc, char **env);

#endif
