/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_cmd3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernand <dfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:41:10 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 12:04:51 by dfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_slash(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == '/')
			return (i);
		i--;
	}
	return (0);
}

char	*cut_cmd(char *cmd, int s, int err)
{
	char	*ret;

	if (err)
		ret = ft_strjoin("echo no such file or directory: ", cmd);
	else
		ret = ft_stralldup(cmd, s);
	free(cmd);
	return (ret);
}

void	list_bin(t_chain *chain, int s, char **path, char **envp)
{
	char	*str;
	char	*cmd_bin;
	int		i;
	int		j;
	int		err;

	err = 0;
	cmd_bin = ft_strmdup(chain->cmd, s + 1);
	if (test_command(cmd_bin, envp) == 0)
		err = 1;
	str = ft_strndup(chain->cmd, s);
	i = 0;
	while (path[i])
	{
		j = ft_strncmp(path[i], str, ft_strlen(str));
		if (j == 0)
			chain->cmd = cut_cmd(chain->cmd, s + 1, err);
		i++;
	}
}

void	bin_check(t_chain *chain, char **envp)
{
	char	**path;
	t_chain	*tmp;
	int		s;

	tmp = chain;
	path = path_access(envp);
	while (tmp)
	{
		s = is_slash(tmp->cmd);
		if (s)
			list_bin(chain, s, path, envp);
		tmp = tmp->pipe;
	}
}

char	*ft_stralldup(char *s1, int size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) - size + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[size + i] != '\0')
	{
		ptr[i] = s1[size + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
