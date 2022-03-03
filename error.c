/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:35:43 by yasinbest         #+#    #+#             */
/*   Updated: 2022/03/03 13:49:31 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

int in_quotes(t_data *data)
{
	int i;

	i = -1;
	(void)(data);


return 0;


}


int	ft_countquote(t_data *data)
{
	int i = -1;

	data->squote = 0;
	data->dquote = 0;
	while (data->line[++i] != 0)
	{
		if (data->line[i] == '\'' && data->squote % 2 == 0)
			data->squote++;
		if (data->line[i] == '\"' && data->squote % 2 == 0)
			data->dquote++;
	}

	if ((data->squote % 2) == 1)
		return 1;
	if	((data->dquote % 2) == 1)
		return 1;
	else 
		return 0;
}
