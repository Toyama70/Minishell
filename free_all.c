/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernand <dfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:47:52 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 12:03:41 by dfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_input	*ft_free_list(t_input *list)
{
	t_input	*tmp;

	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		free(list);
		list = tmp;
	}
	free(list);
	return (NULL);
}

void	ft_free_chain(t_chain *chain)
{
	t_chain	*tmp;

	tmp = chain;
	while (tmp)
	{
		if (tmp->cmd)
			free(tmp->cmd);
		if (tmp->error_msg)
			free(tmp->error_msg);
		if (chain->fd_out)
			close(chain->fd_out);
		if (chain->fd_in)
			close(chain->fd_in);
		if (chain->infile)
			close_fd(chain->infile);
		if (chain->outfile)
			close_fd(chain->outfile);
		tmp = tmp->pipe;
		chain = tmp;
		free(chain);
		chain = NULL;
	}
}
