/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tim_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:49:23 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 12:32:42 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	change_dollars(t_data *data)
{
	char	*save;

	if (data->line[data->dolend + 1] == '"')
		data->dollar = ft_substr(data->line, data->dolstart + 1,
				data->dolend - data->dolstart);
	else
		data->dollar = ft_substr(data->line, data->dolstart + 1, data->dolend);
	data->dollar = ft_strjoin(data->dollar, "=");
	change_dollars2(data);
	save = ft_strjoin(ft_substr(data->line, 0, data->dolstart), data->dollar);
	save = ft_strjoin(save,
			ft_substr(data->line, data->dolend + 1, ft_strlen(data->line)));
	data->line = ft_strdup(save);
	free(data->dollar);
}

void	change_dollars2(t_data *data)
{
	t_env	*ptr;

	ptr = data->env;
	while (ptr)
	{
		if (ft_strncmp(ptr->variable, data->dollar,
				ft_strlen(data->dollar)) == 0)
		{
			if (ptr->valeur)
				break ;
		}
		ptr = ptr->next;
	}
	if (data->dollar[0] == '?')
		data->dollar = ft_strdup(ft_itoa(g_exit_value));
	else if (ptr == NULL)
		data->dollar = ft_strdup("");
	else
		data->dollar = ft_strdup(ptr->valeur);
}

char	*change_line(char *str)
{
	int		i;
	char	*line;
	char	*save;

	i = 0;
	line = ft_strdup(str);
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
		{
			if (i == 0)
				line = ft_substr(line, 1, ft_strlen(line));
			else if (i == (ft_strlen(line) - 1))
				line = ft_substr(line, 0, ft_strlen(line) - 1);
			else
			{
				save = ft_substr(line, 0, i);
				line = ft_strjoin(save,
						ft_substr(line, i + 1, ft_strlen(line)));
			}
			return (line);
		}
		i++;
	}
	return (NULL);
}

void	remove_quotes(t_input *list)
{
	t_input	*ptr_lst;
	char	*line;

	ptr_lst = list;
	while (ptr_lst)
	{
		line = change_line(ptr_lst->input);
		if (line != NULL)
		{
			ptr_lst->input = ft_strdup(line);
			ptr_lst->token_id = 'a';
		}
		else
			ptr_lst = ptr_lst->next;
	}
}

void	move_element(int nb, t_input *list)
{
	t_input		*tmp;
	int			i;

	i = 1;
	tmp = list;
	while (tmp && i <= nb)
	{
		free(tmp->input);
		tmp->input = ft_calloc(sizeof(char), 1);
		tmp->input[0] = '\0';
		tmp = tmp->next;
		i++;
	}
}
