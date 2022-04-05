/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:37:03 by ybestrio          #+#    #+#             */
/*   Updated: 2022/03/20 12:39:22 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_dollars(t_data *data)
{
	data->pos = -1;
	while (data->line[++data->pos] != 0)
	{
		if (data->line[data->pos] == '\'')
		{
			sinquoteline(data->line, data->pos, &data->pos2);
			data->pos = data->pos2;
		}
		if (data->line[data->pos] == '$')
		{
			data->dolstart = data->pos;
			while (1)
			{
				if (data->line[data->pos] == ' '
					|| data->line[data->pos] == 0
					|| data->line[data->pos] == '"')
				{
					data->dolend = data->pos - 1;
					return (1);
				}
				data->pos++;
			}
		}
	}
	return (0);
}

int	sinquoteline(char *s, int i, int *back)
{
	int	end;

	end = ft_strlen(s);
	while (s[i] != 0)
	{
		i++;
		if (s[i] == '\'')
		{
			*back = i;
			return (0);
		}
	}
	return (1);
}

int	sinquotes(t_data *data, int i, int *back)
{
	int	end;

	end = strlen(data->line);
	while (data->line[i] != 0)
	{
		i++;
		if (data->line[i] == '\'')
		{
			*back = i;
			return (0);
		}
	}
	return (1);
}

int	doubquoteline(char *s, int i, int *back)
{
	int	end;

	end = strlen(s);
	while (s[i] != 0)
	{
		i++;
		if (s[i] == '\"')
		{
			*back = i;
			return (0);
		}
	}
	return (1);
}
