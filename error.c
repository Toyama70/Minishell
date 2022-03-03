/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:35:43 by yasinbest         #+#    #+#             */
/*   Updated: 2022/03/02 15:35:53 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

int	ft_countquote(t_data *data)
{
	int i = -1;

	data->squote = 0;
	data->dquote = 0;

	while (data->line[++i] != 0)
	{
		if (data->line[i] == '\'')
			data->squote++;
		if (data->line[i] == '\"')
			data->dquote++;
	}
	if ((data->squote % 2) == 1)
		return 1;
	if	((data->dquote % 2) == 1)
		return 1;
	else 
		return 0;
}
