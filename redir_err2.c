/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_err2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:26:34 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 10:28:59 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*extract_cmd(char *cmd)
{
	char	*ret;
	int		i;

	i = 0;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	ret = ft_strndup(cmd, i);
	return (ret);
}

int	check_exec(char *cmd)
{
	if (cmd[0] == '.' && cmd[1] == '/')
		return (0);
	else if (cmd[0] == '/')
		return (0);
	return (1);
}

void	redir_err(t_chain *chain, char **envp)
{
	t_chain	*tmp;
	char	*cmd;

	tmp = chain;
	while (tmp)
	{
		cmd = extract_cmd(tmp->cmd);
		if (is_path(envp) == 0 && check_exec(cmd))
		{
			tmp->error_msg = ft_strdup("command not found: ");
			tmp->error_msg = ft_strjoin(tmp->error_msg, tmp->cmd);
			tmp->std_err = 1;
			tmp->std_out = 0;
			tmp->std_in = 0;
			close_outfile(tmp);
		}
		else if (tmp->infile && check_fd(tmp) == 1)
		{
			tmp->std_err = 1;
			tmp->std_in = 0;
			tmp->std_out = 0;
		}
		free(cmd);
		tmp = tmp->pipe;
	}
}
