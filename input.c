/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:14:53 by ybestrio          #+#    #+#             */
/*   Updated: 2022/03/02 16:15:35 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

t_input *fill_list(char *input, char token_id, t_input *list)
{
    t_input *tmp;

    tmp = malloc(sizeof(t_input));
	if (!tmp)
		exit(0); // a definir !!!!
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
