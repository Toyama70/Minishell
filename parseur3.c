/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernand <dfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:03:22 by dfernand          #+#    #+#             */
/*   Updated: 2022/03/20 11:04:19 by dfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_pipe(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == '|')
			return (i);
		i++;
	}
	return (0);
}

void	parse_q(t_input *list)
{
	t_input	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->token_id == 'q')
		{
			if (tmp->input[0] == '\"'
				&& tmp->input[ft_strlen(tmp->input) - 1] == '\"')
				tmp->token_id = 't';
			else if (tmp->input[0] == '\''
				&& tmp->input[ft_strlen(tmp->input) - 1] == '\'')
				tmp->token_id = 't';
		}
		tmp = tmp->next;
	}
}

void	clean_cmd(t_input *list)
{
	t_input	*tmp;

	tmp = list;
	parse_q(list);
	while (tmp)
	{
		if (tmp->token_id != 't' && tmp->token_id != 'q')
			check_space(tmp);
		else if (ft_strncmp(tmp->input, ">>", 2) == 0)
			tmp->token_id = 'r';
		else if (tmp->token_id == 'q')
			check_space_q(tmp);
	tmp = tmp->next;
	}
	parse_q(list);
}
