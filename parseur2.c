/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernand <dfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:55:58 by dfernand          #+#    #+#             */
/*   Updated: 2022/03/20 11:11:53 by dfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_2chevron(char *str)
{
	int	i;
	int	l;

	l = ft_strlen(str) - 1;
	i = 0;
	while (i < l)
	{
		if (str[i] == '>' && str[i + 1] == '>')
			return (i);
		i++;
	}
	return (0);
}

void	check_space(t_input *check)
{
	if (ft_strncmp(">>", check->input, 2) == 0)
	{
		if (ft_strlen(check->input) == 2)
			check->token_id = 'r';
		else
			insert_block_double(check);
	}
	else if ((is_2chevron(check->input)))
		insert_block_case2_double(check, is_2chevron(check->input));
	else if ((check->input[0] == '<' || check->input[0] == '>'))
	{
		if (ft_strlen(check->input) == 1)
			check->token_id = 'r';
		else
			insert_block(check);
	}
	else if ((is_redir(check->input)))
		insert_block_case2(check, is_redir(check->input));
}

void	insert_block_p_case2(t_input *check, int pos)
{
	t_input	*new;

	new = malloc(sizeof(t_input));
	if (!new)
		exit(0);
	if (check->next)
		check->next->prev = new;
	new->next = check->next;
	new->prev = check;
	check->next = new;
	new->token_id = 'a';
	new->input = ft_strdup(&(check->input[pos]));
	check->input[pos] = '\0';
}
