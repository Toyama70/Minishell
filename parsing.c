/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:48:44 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 12:02:46 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_input	*listing(t_data *data, t_input *list)
{
	int	i;

	i = -1;
	if (data->dquote == 0 && data->squote == 0)
	{
		data->input = ft_split(data->line, ' ');
		while (data->input[++i] != 0)
		{
			if (ft_strncmp(data->input[i], "export\0", 7) == 0)
				list = fill_list(data->input[i], 'c', list);
			else if (ft_strncmp(data->input[i], "exit\0", 5) == 0)
				list = fill_list(data->input[i], 'c', list);
			else if (ft_strncmp(data->input[i], "echo\0", 5) == 0)
				list = fill_list(data->input[i], 'c', list);
			else if (data->input[i][0] == '-')
				list = fill_list(data->input[i], 'o', list);
			else if (data->input[i][0] == '$')
				list = fill_list(data->input[i], 'd', list);
			else
				list = fill_list(data->input[i], 'a', list);
		}
	}
	return (list);
}

t_input	*listing2(t_data *data, t_input *list)
{
	int	i;

	i = -1;
	data->input = ft_splitquote(data->line, ' ');
	while (data->input[++i] != 0)
	{
		if (ft_strncmp(data->input[i], "export\0", 7) == 0)
			list = fill_list(data->input[i], 'c', list);
		else if (ft_strncmp(data->input[i], "echo\0", 5) == 0)
			list = fill_list(data->input[i], 'c', list);
		else if (open(data->input[i], O_RDONLY) != -1)
			list = fill_list(data->input[i], 'f', list);
		else if (data->input[i][0] == '-')
			list = fill_list(data->input[i], 'o', list);
		else
			list = fill_list(data->input[i], 'q', list);
	}
	return (list);
}

t_input	*ft_parse(t_data *data, t_input *list, char **envp)
{
	data->cmdfound = 0;
	(void)(envp);
	if (ft_countquote(data) == 1)
	{
		write(2, "Error : quote not closed ?\n", 27);
		return (NULL);
	}
	while (ft_dollars(data) != 0)
		change_dollars(data);
	if (data->line != 0)
		list = listing(data, list);
	if (data->dquote != 0 || data->squote != 0)
		list = listing2(data, list);
	while (list && list->prev)
	{
		usleep(1);
		if (list->prev)
			list = list->prev;
	}
	return (list);
	ft_free_all(data->input, 0);
}
