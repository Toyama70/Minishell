/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:48:39 by dfernand          #+#    #+#             */
/*   Updated: 2022/03/20 12:32:17 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_redir	*set_infile(t_chain *chain)
{
	t_redir	*ret;

	if (!chain->infile)
		return (NULL);
	else
	{
		ret = chain->infile;
		while (ret)
		{
			if (ret->next == NULL)
				return (ret);
			ret = ret->next;
		}
	}
	return (ret);
}

t_redir	*set_outfile(t_chain *chain)
{
	t_redir	*ret;

	if (!chain->outfile)
		return (NULL);
	else
	{
		ret = chain->outfile;
		while (ret)
		{
			if (ret->next == NULL)
				return (ret);
			ret = ret->next;
		}
	}
	return (ret);
}

void	set_redir(t_chain *chain)
{
	t_redir	*infile;
	t_redir	*outfile;

	infile = set_infile(chain);
	outfile = set_outfile(chain);
	if (chain->std_err == 1)
	{
		dup(2);
		chain->std_out = 1;
		printf("%s\n", chain->error_msg);
	}
	else if (chain->std_in == 0)
		chain->fd_in = dup2(infile->fd, 0);
	else
		dup(0);
	if (chain->std_out == 0 && chain->outfile)
		chain->fd_out = dup2(outfile->fd, 1);
	else if (chain->std_err)
		dup(2);
	else
		dup(1);
}

void	child(t_chain *chain, char **envp)
{
	char	*cmd_exec;
	char	**cmd;
	char	**path;

	set_redir(chain);
	path = path_access(envp);
	cmd = ft_split(chain->cmd, ' ');
	cmd_exec = access_cmd(path, cmd[0]);
	execve(cmd_exec, cmd, envp);
	printf("command not found: %s\n", chain->cmd);
	g_exit_value = 127;
	exit (127);
}

int	is_path(char **envp)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = envp;
	while (tmp[i])
	{
		if (ft_strncmp("PATH", tmp[i++], 4) == 0)
			return (1);
	}
	return (0);
}
