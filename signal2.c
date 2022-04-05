/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:46:09 by ybestrio          #+#    #+#             */
/*   Updated: 2022/03/20 10:16:35 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	load_ios(t_data *data, char **envp)
{
	tcgetattr(0, &data->old);
	tcgetattr(0, &data->new);
	data->new.c_lflag &= ~(ECHOCTL);
	tcsetattr(0, TCSANOW, &data->new);
	(void)(envp);
}

t_input	*fill_list(char *input, char token_id, t_input *list)
{
	t_input	*tmp;

	tmp = malloc(sizeof(t_input));
	if (!tmp)
		exit(0);
	if (list)
	{
		list->next = tmp;
		tmp->prev = list;
		tmp->next = NULL;
	}
	else
	{
		tmp->prev = NULL;
		tmp->next = NULL;
	}
	tmp->input = ft_strdup(input);
	tmp->token_id = token_id;
	return (tmp);
}

int	ft_scanspace(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
