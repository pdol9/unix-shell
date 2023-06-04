/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:12:33 by pdolinar          #+#    #+#             */
/*   Updated: 2022/09/18 23:08:06 by pdolinar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
// macos
//#include <editline/readline.h>

typedef struct s_builtin
{
	
	
}	t_builtin;

typedef struct s_data
{


}	t_data;



/* validate args */



/* init */



/* main */



/* parsing */
char	*find_path(char **envp);
char	*parse_path(char **envp, char **cmd);
char	*ft_custom_strjoin(char const *s1, char const *s2, char const *s3);
void	free_double_p(char **local_paths);

/* piping */
void	ft_new_process(int num, char **argv, char **envp);
void	ft_fork(int argc, char **argv, char **envp);


/* utils */



/* exit */




#endif
