/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:30:05 by dfernand          #+#    #+#             */
/*   Updated: 2022/03/20 12:32:31 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_fork1(t_chain *chain, char **envp)
{
	pid_t	p1;
	int		status;

	p1 = fork();
	if (p1 < 0)
		exit(0);
	if (p1 == 0)
		child(chain, envp);
	waitpid(p1, &status, 0);
	g_exit_value = status % 255;
}

void	ft_fork2(t_chain *chain)
{
	pid_t	p1;
	int		status;

	p1 = fork();
	if (p1 < 0)
		exit(0);
	if (p1 == 0)
		child_bin(chain);
	waitpid(p1, &status, 0);
	g_exit_value = status % 255;
}

void	ft_exec(t_chain *chain, char **envp)
{
	if (chain->std_err != 1 && is_path(envp))
		ft_fork1(chain, envp);
	else if (is_bin(chain->cmd))
		ft_fork2(chain);
	else
	{
		g_exit_value = 127;
		printf("%s\n", chain->error_msg);
	}
}

void	execution(t_chain *chain, char **envp)
{
	if (chain->pipe == NULL)
		ft_exec(chain, envp);
}
