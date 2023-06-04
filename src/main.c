/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:05:07 by pdolinar          #+#    #+#             */
/*   Updated: 2022/09/20 14:38:32 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	if (ac || av || envp)
	{
		printf("hello minishell\n");
	}
	/* init_shell();
	while (1)
	{
		print_cmd_line();
		path = readline() --> get_next_line
		cmd = parser(path);
		if (cmd == NULL)
			exec();
		else
			exit;
	} */
	
	
	
	return (EXIT_SUCCESS);
}
