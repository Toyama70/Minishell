/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:35:43 by yasinbest         #+#    #+#             */
/*   Updated: 2022/03/04 15:04:52 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

int sinquoteline(char *s, int i, int *back)
{
	int end;

	end = strlen(s); // switch to ft_strlen
	while (s[i] != 0)
	{
		i++;
		if (s[i] == '\'')
		{
			*back = i;
			return 0;
		}
	}

return 1;
}

int sinquotes(t_data *data, int i, int *back)
{
	int end;

	end = strlen(data->line); // switch to ft_strlen
	while (data->line[i] != 0)
	{
		i++;
		if (data->line[i] == '\'')
		{
			*back = i;
			return 0;
		}
	}

return 1;
}

// eafe 'aef aef'

int doubquotes(t_data *data, int i, int *back)
{
	int end;

	end = strlen(data->line); // switch to ft_strlen
	while (data->line[i] != 0)
	{
		i++;
		if (data->line[i] == '\"')
		{
			*back = i;
			return 0;
		}
	}
return 1;

}


// ' " '

int	ft_countquote(t_data *data)
{
	int i = -1;
	int back;
	int status;

	data->squote = 0;
	data->dquote = 0;
	while (data->line[++i] != 0)
	{
		if (data->line[i] == '\'')
		{
			data->squote++;
			status = sinquotes(data, i, &back);
			if (status == 0)
				i = back;
			else 
				return 1;
		}
		if (data->line[i] == '\"')
		{
			data->dquote++;
			status = doubquotes(data, i, &back);
			if (status == 0)
				i = back;
			else 
				return 1;
		}
		
	}
	printf("squote in function = %d\n", data->squote);
	/*
	if ((data->squote % 2) == 1)
		return 1;
	if	((data->dquote % 2) == 1)
		return 1;
	else */
		return 0;
}
