/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur_danny.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfernand <dfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:44:45 by dfernand          #+#    #+#             */
/*   Updated: 2022/03/20 10:55:35 by dfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	insert_block_double(t_input *check)
{
	t_input	*new;
	char	tmp;

	new = malloc(sizeof(t_input));
	if (!new)
		exit(0);
	if (check->next)
		check->next->prev = new;
	new->next = check->next;
	new->prev = check;
	check->next = new;
	new->input = ft_strdup(&(check->input[2]));
	new->token_id = 'f';
	tmp = check->input[0];
	free(check->input);
	check->input = malloc(sizeof(char) * 3);
	if (!check->input)
		exit(0);
	check->input[0] = tmp;
	check->input[1] = tmp;
	check->input[2] = '\0';
	check->token_id = 'r';
}

void	insert_block(t_input *check)
{
	t_input	*new;
	char	tmp;

	new = malloc(sizeof(t_input));
	if (!new)
		exit(0);
	if (check->next)
		check->next->prev = new;
	new->next = check->next;
	new->prev = check;
	check->next = new;
	new->input = ft_strdup(&(check->input[1]));
	new->token_id = 'f';
	tmp = check->input[0];
	free(check->input);
	check->input = malloc(sizeof(char) * 2);
	if (!check->input)
		exit(0);
	check->input[0] = tmp;
	check->input[1] = '\0';
	check->token_id = 'r';
}

void	insert_block_case2(t_input *check, int pos)
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

void	insert_block_case2_double(t_input *check, int pos)
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

int	is_redir(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == '<' || str[i] == '>')
			return (i);
		i++;
	}
	return (0);
}
