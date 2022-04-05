/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:45:23 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 09:19:42 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	change_val(t_data *data)
{
	t_env	*ptr;

	ptr = data->env;
	if (data->ex_variable[ft_strlen(data->ex_variable) - 1] != '=')
		data->ex_variable = ft_strjoin(data->ex_variable, "=");
	while (ptr)
	{
		if (ft_strncmp(data->ex_variable, ptr->variable,
				ft_strlen(ptr->variable)) == 0)
		{
			ptr->valeur = ft_strdup(data->ex_valeur);
			lst_to_tab(data);
			break ;
		}
		ptr = ptr->next;
	}
}

void	export_var(t_data *data, int exporting)
{
	t_env	*ptr;

	ptr = data->env;
	if (data->ex_variable[ft_strlen(data->ex_variable) - 1] != '=')
		data->ex_variable = ft_strjoin(data->ex_variable, "=");
	while (ptr)
	{
		if (ft_strncmp(data->ex_variable, ptr->variable,
				ft_strlen(ptr->variable)) == 0)
		{
			ptr->exported = exporting;
			return ;
		}
		if (ptr->next == NULL)
		{
			ptr->next = ft_lstnew(ft_strjoin
					(data->ex_variable, data->ex_valeur), exporting);
			ptr->next->previous = ptr;
			ptr->next->valeur = NULL;
			break ;
		}
		ptr = ptr->next;
	}
	lst_to_tab(data);
}

int	check_in_env(t_data *data, char *ex_variable, int exporting)
{
	t_env	*ptr;

	ptr = data->env;
	if (ex_variable[ft_strlen(ex_variable) - 1] != '=')
		ex_variable = ft_strjoin(ex_variable, "=");
	while (ptr)
	{
		if (ft_strncmp(ex_variable, ptr->variable,
				ft_strlen(ptr->variable)) == 0)
		{
			if (ptr->exported == 0)
				ptr->exported = exporting;
			return (0);
		}
		ptr = ptr->next;
	}
	return (1);
}

int	check_in_valeur(t_data *data, char *ex_variable)
{
	t_env	*ptr;

	ptr = data->env;
	if (ex_variable[ft_strlen(ex_variable) - 1] != '=')
		ex_variable = ft_strjoin(ex_variable, "=");
	while (ptr)
	{
		if (ft_strncmp(ex_variable, ptr->variable,
				ft_strlen(ptr->variable)) == 0)
		{
			if (ptr->valeur)
			{
				return (0);
			}
			else
			{
				return (1);
			}
		}
		ptr = ptr->next;
	}
	return (0);
}

void	sort_tab(char **tab)
{
	char	*save;
	int		len;

	len = 0;
	while (tab[len + 1])
	{
		if (ft_strncmp(tab[len], tab[len + 1], ft_strlen(tab[len])) > 0)
		{
			save = ft_strdup(tab[len]);
			free(tab[len]);
			tab[len] = ft_strdup(tab[len + 1]);
			tab[len + 1] = ft_strdup(save);
			len = -1;
		}
		len++;
	}
}
