/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spacers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:16:39 by ybestrio          #+#    #+#             */
/*   Updated: 2022/03/10 10:35:06 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

int	ft_export(t_data *data, int i)
{
	int	end;
	int	index;

	index = 0;
	end = ft_strlen(data->input[i]);
	if (data->input[i][0] == '\'' && data->input[i][end - 1] == '\'')
		return 0;
	if (data->input[i][0] == '\"' && data->input[i][end - 1] == '\"')
		return 0;
	while (data->input[i][index] != 0)
	{
		if (data->input[i][index] == '=')
			return (1);
		index++;
	}
	return (0);
}
