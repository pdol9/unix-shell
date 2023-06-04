/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:05:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/09/18 23:28:19 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* run bash command */
void	ft_new_process(int num, char **argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv[num - 1], ' ');
	path = parse_path(envp, cmd);
	if (path == NULL)
		error_path(cmd);
	if (execve(path, cmd, envp) == -1)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
	}
	free_double_p(cmd);
	exit(errno);
}

void	ft_fork(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	pid;
	int	num;

	num = return_num(argv);
	while (num < argc)
	{
		pipe(pipefd);
		pipe_check(pipefd);
		pid = fork();
		fd_pid_error(0, pid);
		if (pid == 0)
		{
			close(pipefd[0]);
			dup2(pipefd[1], STDOUT_FILENO);
			close(pipefd[1]);
			ft_new_process(num, argv, envp);
		}
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		waitpid(-1, NULL, WNOHANG);
		num++;
	}
}
