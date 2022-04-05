/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_cmd4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:42:57 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 10:44:10 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	clean_option(t_input *list)
{
	t_input	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->token_id == 't' && tmp->input[1] == '-')
		{
			tmp->input[0] = ' ';
			tmp->input[ft_strlen(tmp->input) - 1] = ' ';
		}
	tmp = tmp->next;
	}
}

void	correct_file(t_input *list)
{
	t_input	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->token_id == 'r')
		{
			if (tmp->next)
				tmp->next->token_id = 'f';
		}
		tmp = tmp->next;
	}
}
