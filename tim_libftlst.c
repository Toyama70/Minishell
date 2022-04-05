/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tim_libftlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:45:38 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 09:14:35 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	make_env(t_data *data, char **envp)
{
	int		i;
	t_env	*ptr;

	i = 0;
	while (envp[i])
	{
		ptr = ft_lstnew(envp[i], 1);
		ft_lstadd_back(&data->env, ptr);
		i++;
	}
	link_lst(data);
}

void	link_lst(t_data *data)
{
	t_env	*ptr;

	ptr = data->env;
	ptr->previous = NULL;
	while (ptr->next)
	{
		ptr->next->previous = ptr;
		ptr = ptr->next;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	lst_to_tab(t_data *data)
{
	t_env	*ptr;
	int		i;
	int		max;

	i = 0;
	ptr = data->env;
	max = ft_lstsize(ptr) + 1;
	data->tab_env = ft_calloc(sizeof(char *), ft_lstsize(ptr) + 1);
	while (ptr)
	{
		if (ft_strncmp(ptr->variable, "HOME", 4) == 0)
			data->home = ft_strdup(ptr->valeur);
		if (ptr->exported == 0)
			i--;
		else if (ptr->valeur)
			data->tab_env[i] = ft_strjoin(ptr->variable, ptr->valeur);
		else
			data->tab_env[i] = ft_strdup(ptr->variable);
		ptr = ptr->next;
		i++;
	}
	while (i < max)
		data->tab_env[i++] = NULL;
}
