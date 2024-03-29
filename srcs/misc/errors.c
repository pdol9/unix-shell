/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsemke <fsemke@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:05:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/11/02 10:53:17 by fsemke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* return error message for invalid bash command*/
void	error_path(t_exec *cmd)
{
	char	*path;
	t_env	*env;

	path = cmd->cmd->token;
	env = cmd->data->env;
	if (find_path(env) == NULL)
	{
		write(2, path, ft_strlen(path));
		write(2, ": No such file or directory\n", 28);
	}
	else
	{
		write(2, path, ft_strlen(path));
		write(2, ": command not found\n", 20);
	}
	clear_nodes(&cmd->data->env);
	free(cmd->data->redir);
	cleanup_tokens(cmd->data);
	cleanup_exec(cmd->data);
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
