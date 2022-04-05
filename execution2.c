/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:26:07 by dfernand          #+#    #+#             */
/*   Updated: 2022/03/20 12:32:20 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*slash(char *str)
{
	int		l;
	char	*ret;

	l = ft_strlen(str) - 1;
	ret = NULL;
	while (str[l] && str[l] != '/')
		l--;
	ret = ft_substr(str, ++l, ft_strlen(str));
	free(str);
	return (ret);
}

char	**ft_envp(char *str)
{
	int		l;
	char	**ret;

	l = ft_strlen(str) - 1;
	while (str[l] && str[l] != '/')
		l--;
	ret = malloc(sizeof(char *) * 2);
	if (!ret)
		exit(0);
	ret[1] = NULL;
	ret[0] = ft_substr(str, 0, l);
	return (ret);
}

void	child_bin(t_chain *chain)
{
	char	*cmd_exec;
	char	**cmd;
	char	**envp;
	int		i;

	set_redir(chain);
	i = 0;
	while (chain->cmd[i] && chain->cmd[i] != ' ')
		i++;
	cmd_exec = ft_strndup(chain->cmd, i);
	cmd = ft_split(chain->cmd, ' ');
	cmd[0] = slash(cmd[0]);
	envp = ft_envp(chain->cmd);
	execve(cmd_exec, cmd, envp);
	g_exit_value = 127;
	exit (127);
}

int	is_bin(char *cmd)
{
	int		i;
	char	*cmd_exec;

	i = 0;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	cmd_exec = ft_strndup(cmd, i);
	if (access(cmd_exec, 0) == 0)
		return (1);
	return (0);
}
