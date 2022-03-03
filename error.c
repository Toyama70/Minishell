/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:35:43 by yasinbest         #+#    #+#             */
/*   Updated: 2022/03/03 19:53:41 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

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
			status = sinquotes(data, i, &back);
			if (status == 0)
				i = back;
			else 
				return 1;
		}
		if (data->line[i] == '\"')
		{	
			status = doubquotes(data, i, &back);
			if (status == 0)
				i = back;
			else 
				return 1;
		}
		
	}

	if ((data->squote % 2) == 1)
		return 1;
	if	((data->dquote % 2) == 1)
		return 1;
	else 
		return 0;
}
