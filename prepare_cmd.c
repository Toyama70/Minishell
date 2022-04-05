/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:43:47 by dfernand          #+#    #+#             */
/*   Updated: 2022/03/20 10:43:20 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	init_chain(t_chain *chain)
{
	chain->cmd = NULL;
	chain->error_msg = NULL;
	chain->pipe = NULL;
	chain->infile = NULL;
	chain->outfile = NULL;
	chain->std_in = 1;
	chain->std_out = 1;
	chain->std_err = 0;
	chain->fd_out = 0;
	chain->fd_in = 0;
}

int	return_tokenid(char c)
{
	if (c == 'c' || c == 'a' || c == 'o' || c == 'q' || c == 't')
		return (1);
	else if (c == 'f')
		return (2);
	else if (c == 'r')
		return (3);
	return (-1);
}

char	*add_cmd(char *current, char *add)
{
	char	*tmp;
	char	*add_space;

	add_space = ft_strjoin(" ", add);
	if (current)
		tmp = ft_strjoin(current, add_space);
	else
		tmp = ft_strdup(add);
	return (tmp);
}

void	add_chain(t_chain *chain)
{
	t_chain	*tmp;
	t_chain	*new;

	tmp = chain;
	while (tmp->pipe)
		tmp = tmp->pipe;
	new = malloc(sizeof(t_chain));
	if (!new)
		exit(0);
	tmp->pipe = new;
	init_chain(new);
}

t_chain	*prepare_cmd(t_input *list, char **envp)
{
	t_chain	*chain;

	chain = malloc(sizeof(t_chain));
	if (!chain)
		exit(0);
	init_chain(chain);
	clean_option(list);
	remove_quotes(list);
	chain = fill_chain(list, chain);
	redir_err(chain, envp);
	if (is_path(envp))
		bin_check(chain, envp);
	return (chain);
}
