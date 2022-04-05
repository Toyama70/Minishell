/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:05:47 by dfernand          #+#    #+#             */
/*   Updated: 2022/03/20 10:17:55 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	**path_access(char **envp)
{
	char	**ret;

	ret = NULL;
	while (strncmp("PATH", *envp, 4))
		envp++;
	if (envp)
	{
		ret = ft_split(*envp + 5, ':');
		if (!ret)
			exit(1);
	}
	return (ret);
}

char	*access_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*try;
	int		i;

	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		try = ft_strjoin(tmp, cmd);
		if (access(try, 0) == 0)
			return (try);
		i++;
	}
	return (NULL);
}

int	test_command(char *cmd, char **envp)
{
	char	**path;
	char	*cmd_exec;
	int		ret;

	path = path_access(envp);
	cmd_exec = access_cmd(path, cmd);
	if (!cmd_exec)
		ret = 0;
	else
		ret = 1;
	return (ret);
}
