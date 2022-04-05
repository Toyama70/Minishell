/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_cmd2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:40:57 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 10:43:40 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	open_infile(t_chain *chain, char *name_file)
{
	t_redir	*redir;
	t_redir	*tmp_r;

	tmp_r = chain->infile;
	while (chain->infile && tmp_r->next)
		tmp_r = tmp_r->next;
	redir = malloc(sizeof(t_redir));
	if (!redir)
		exit(0);
	if (!chain->infile)
		chain->infile = redir;
	else
		tmp_r->next = redir;
	chain->std_in = 0;
	redir->name_file = ft_strdup(name_file);
	redir->fd = open(name_file, O_RDONLY);
	redir->next = NULL;
}

void	open_outfile1(t_chain *chain, char *name_file)
{
	t_redir	*redir;
	t_redir	*tmp_r;

	tmp_r = chain->outfile;
	while (chain->outfile && tmp_r->next)
		tmp_r = tmp_r->next;
	redir = malloc(sizeof(t_redir));
	if (!redir)
		exit(0);
	if (!chain->outfile)
		chain->outfile = redir;
	else
		tmp_r->next = redir;
	chain->std_out = 0;
	redir->name_file = ft_strdup(name_file);
	redir->fd = open(name_file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	redir->next = NULL;
}

void	open_outfile2(t_chain *chain, char *name_file)
{
	t_redir	*redir;
	t_redir	*tmp_r;

	tmp_r = chain->outfile;
	while (chain->outfile && tmp_r->next)
		tmp_r = tmp_r->next;
	redir = malloc(sizeof(t_redir));
	if (!redir)
		exit(0);
	if (!chain->outfile)
		chain->outfile = redir;
	else
		tmp_r->next = redir;
	chain->std_out = 0;
	redir->name_file = ft_strdup(name_file);
	redir->fd = open(name_file, O_CREAT | O_RDWR | O_APPEND, 0644);
	redir->next = NULL;
}

void	open_redir(t_input *list, t_chain *chain)
{
	t_input	*tmp_l;

	tmp_l = list;
	if (tmp_l->input[0] == '<')
		open_infile(chain, tmp_l->next->input);
	else if (ft_strncmp(tmp_l->input, ">>", 2) == 0)
		open_outfile2(chain, tmp_l->next->input);
	else if (tmp_l->input[0] == '>')
		open_outfile1(chain, tmp_l->next->input);
}

t_chain	*fill_chain(t_input *list, t_chain *chain)
{
	t_input	*tmp;
	t_chain	*tmp_c;
	int		k;

	correct_file(list);
	tmp = list;
	tmp_c = chain;
	while (tmp)
	{
		while (tmp_c->pipe)
			tmp_c = tmp_c->pipe;
		k = return_tokenid(tmp->token_id);
		if (k == 1)
			tmp_c->cmd = add_cmd(tmp_c->cmd, tmp->input);
		else if (k == 0)
			add_chain(chain);
		else if (k == 3)
			open_redir(tmp, tmp_c);
		tmp = tmp->next;
	}
	return (chain);
}
