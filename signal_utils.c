/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 10:20:06 by ybestrio          #+#    #+#             */
/*   Updated: 2022/03/20 10:34:30 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (0);
	tab = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (0);
	return (ft_create_tab(tab, s, c));
}

int	doubquotes(t_data *data, int i, int *back)
{
	int	end;

	end = ft_strlen(data->line);
	while (data->line[i] != 0)
	{
		i++;
		if (data->line[i] == '\"')
		{
			*back = i;
			return (0);
		}
	}
	return (1);
}

int	ft_countquote(t_data *data)
{
	data->pos = -1;
	data->squote = 0;
	data->dquote = 0;
	while (data->line[++data->pos] != 0)
	{
		if (data->line[data->pos] == '\'')
		{
			data->squote++;
			data->status = sinquotes(data, data->pos, &data->pos2);
			if (data->status == 0)
				data->pos = data->pos2;
			else
				return (1);
		}
		if (data->line[data->pos] == '\"')
		{
			data->dquote++;
			data->status = doubquotes(data, data->pos, &data->pos2);
			if (data->status == 0)
				data->pos = data->pos2;
			else
				return (1);
		}
	}
	return (0);
}

size_t	ft_nextnotc(char *s, char c, int index)
{
	while (s[index] && s[index] == c && !ft_isinquote_now(s, index))
		index++;
	return (index);
}
