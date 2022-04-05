/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_danny2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:36:41 by dfernand          #+#    #+#             */
/*   Updated: 2022/03/20 11:16:57 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	find_last_q(char c, char *str, int pos)
{
	int	l;

	l = ft_strlen(str) - 1;
	while (str[l])
	{
		if (str[l] == c)
			return (l - pos + 1);
		l--;
	}
	return (0);
}

int	is_pipe_q(char *str)
{
	int	i;
	int	last;

	i = 1;
	last = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			i += find_last_q(str[i], str, i);
		if (str[i] == '|')
			return (i);
		i++;
	}
	return (0);
}

int	is_redir_q(char *str)
{
	int	i;
	int	l;

	l = ft_strlen(str);
	i = 0;
	while (i < l && str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			i += find_last_q(str[i], str, i);
		if (str[i] == '<' || str[i] == '>')
			return (i);
		i++;
	}
	return (0);
}

void	check_space_q(t_input *check)
{
	if ((check->input[0] == '<' || check->input[0] == '>'))
	{
		if (ft_strlen(check->input) == 1)
		{
			check->token_id = 'r';
			return ;
		}
	}
	else if ((is_redir_q(check->input)))
		insert_block_case2(check, is_redir_q(check->input));
}
