/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernand <dfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 21:05:47 by dfernand          #+#    #+#             */
/*   Updated: 2022/03/01 15:00:46 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"


/*free_split est deja utiliser a voir a la suite qd on fera FUUUUUUUUUSION*/
/*
void	free_split(char **path)
{
	int	i;

	i = 0;
	while (path[i])
		free(path[i++]);
	free(path);
} // readapter*/
/***************************************************************************/

char	**path_access(char **envp)
{
	char	**ret;

	ret = NULL;
	while (strncmp("PATH", *envp, 4))// mettre le vrai
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
		//free(tmp);
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
//	free_split(path);
//	free(cmd_exec);
	return (ret);
}
