/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/16 17:04:31 by abobas        #+#    #+#                 */
/*   Updated: 2020/06/01 16:37:18 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	minishell(t_minishell *sh)
{
	while (1)
	{
		reset(sh);
		if (!prompt(sh))
			continue ;
		if (!signal_handler_parent())
			continue ;
		if (!parse(sh))
			continue ;
		evaluate(sh);
	}
}

int		main(int ac, char **av, char **env)
{
	t_minishell		sh;
	t_vector		v;

	v = init_env(env);
	sh = init_minishell();
	sh.env = &v;
	minishell(&sh);
	return (0);
	(void)ac;
	(void)av;
}
