/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 09:28:46 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 11:09:21 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_builtin(t_data *data, t_input *list, t_chain *chain)
{
	if (built_pipe(list) == 0)
		set_redir(chain);
	if (ft_strncmp(list->input, "pwd", 4) == 0)
		my_pwd(data);
	else if (ft_strncmp(list->input, "echo", 5) == 0)
		my_echo(list);
	else if (ft_strncmp(list->input, "env", 4) == 0)
		my_env(data, list);
	else if (ft_strncmp(list->input, "cd", 3) == 0)
		my_cd(data, list);
	else if (ft_strncmp(list->input, "unset", 6) == 0)
		my_unset(data, list);
	else if (ft_strncmp(list->input, "export", 7) == 0)
		my_export(data, list);
	else if (ft_strncmp(list->input, "exit", 5) == 0)
		my_exit(list);
	else
		return (1);
	ft_close(chain);
	return (0);
}

int	built_pipe(t_input *list)
{
	if (ft_strncmp(list->input, "pwd", 4) == 0)
		return (0);
	else if (ft_strncmp(list->input, "echo", 5) == 0)
		return (0);
	else if (ft_strncmp(list->input, "env", 4) == 0)
		return (0);
	else if (ft_strncmp(list->input, "cd", 3) == 0)
		return (0);
	else if (ft_strncmp(list->input, "unset", 6) == 0)
		return (0);
	else if (ft_strncmp(list->input, "export", 7) == 0)
		return (0);
	else if (ft_strncmp(list->input, "exit", 5) == 0)
		return (0);
	return (1);
}

void	ft_close(t_chain *chain)
{
	if (chain->fd_out)
		close(chain->fd_out);
	if (chain->fd_in)
		close(chain->fd_in);
	chain->fd_in = 0;
	chain->fd_out = 0;
	dup(1);
	dup(0);
}

void	close_fd(t_redir *redir)
{
	t_redir	*tmp;

	tmp = redir;
	while (tmp)
	{
		if (tmp->name_file)
			free(tmp->name_file);
		redir = tmp;
		tmp = tmp->next;
		free(redir);
	}
}
