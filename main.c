/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:26:24 by yasinbest         #+#    #+#             */
/*   Updated: 2022/03/20 12:27:14 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	t_input	*list;
	t_chain	*chain;

	list = ft_garbage(argc, argv, &data, envp);
	while (1)
	{
		ft_trash(&data);
		if (to_continue(&data) == 1)
			continue ;
		if (data.line[0] != '\n' && data.line[0] != '\0')
		{
			list = ft_parse(&data, list, envp);
			if (to_continue2(list, &data) == 1)
				continue ;
			clean_cmd(list);
			move_element(check_egales(&data, list), list);
			chain = prepare_cmd(list, data.tab_env);
			if (is_builtin(&data, list, chain) == 1)
				(execution(chain, data.tab_env));
			list = ft_free_list(list);
			ft_free_chain(chain);
		}
		free(data.line);
	}
}

int	to_continue(t_data *data)
{
	if (data->line == '\0' || ft_scanspace(data->line) == 1)
	{
		free(data->line);
		return (1);
	}
	return (0);
}

int	to_continue2(t_input *list, t_data *data)
{
	if (list == NULL)
	{
		free(data->line);
		return (1);
	}
	return (0);
}
