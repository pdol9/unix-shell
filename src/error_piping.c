/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_piping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:05:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/09/18 23:28:19 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* return error message for invalid bash command*/
void	error_path(char **cmd)
{
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, ": command not found\n", 20);
	free_double_p(cmd);
	exit(127);
}

/* 	return message if pid or file descriptor is invalid */
void	fd_pid_error(int fd, pid_t pid)
{
	if (pid == -1)
	{
		perror("Failed to fork");
		exit(EXIT_FAILURE);
	}
	if (fd < 0)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
		exit(errno);
	}
}

/* return message if pipefd is invalid */
void	pipe_check(int pipefd[])
{
	if (pipe(pipefd) == -1)
	{
		write(2, "Failed to pipe\n", 16);
		exit(EXIT_FAILURE);
	}
}

int	return_num(char **argv)
{
	int	num;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		num = 4;
	else
		num = 3;
	return (num);
}

/* free allocated memory */
void	free_double_p(char **local_paths)
{
	int	i;

	i = 0;
	while (local_paths[i] != NULL)
		free(local_paths[i++]);
	free(local_paths[i]);
	free(local_paths);
}
