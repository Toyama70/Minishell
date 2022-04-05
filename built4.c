/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:50:35 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 12:32:05 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	my_unset(t_data *data, t_input *list)
{
	t_input	*ptr_lst;

	ptr_lst = list;
	if (ptr_lst->next == NULL)
		return ;
	ptr_lst = ptr_lst->next;
	while (ptr_lst)
	{
		remove_env(data, ptr_lst->input);
		ptr_lst = ptr_lst->next;
	}
	g_exit_value = 0;
	lst_to_tab(data);
}

void	remove_env(t_data *data, char *str)
{
	t_env	*ptr;
	char	*variable;

	ptr = data->env;
	variable = ft_strjoin(str, "=");
	while (ptr)
	{
		if (ft_strncmp(variable, ptr->variable, ft_strlen(variable)) == 0)
		{
			ptr->previous->next = ptr->next;
			if (ptr->next)
			{
				free(ptr->variable);
				ptr->next->previous = ptr->previous;
			}
			free(variable);
			break ;
		}
		ptr = ptr->next;
	}
}

void	init_export(t_data *data, char *input)
{
	int	i;

	i = 0;
	while (input[i] != '=' && input[i])
		i++;
	data->ex_variable = ft_substr(input, 0, i + 1);
	if (input[i] == '\0')
		data->ex_valeur = ft_substr(input, i, ft_strlen(input));
	else
		data->ex_valeur = ft_substr(input, i + 1, ft_strlen(input));
}

void	my_export(t_data *data, t_input *list)
{
	t_input	*ptr_lst;

	ptr_lst = list;
	if (ptr_lst->next == NULL)
		return (print_export(data));
	ptr_lst = ptr_lst->next;
	while (ptr_lst)
	{
		init_export(data, ptr_lst->input);
		if (data->ex_variable[ft_strlen(data->ex_variable) - 1] != '=')
		{
			if (check_in_env(data, data->ex_variable, 1) == 1)
				export_var(data, 1);
		}
		else
		{
			if (check_in_env(data, data->ex_variable, 1) == 1)
				export_var(data, 1);
			change_val(data);
		}
		ptr_lst = ptr_lst->next;
	}
	g_exit_value = 0;
	lst_to_tab(data);
}

void	write_and_exit(int fd, char *str, int ex)
{
	g_exit_value = ex;
	write(fd, str, ft_strlen(str));
	exit (ex);
}
