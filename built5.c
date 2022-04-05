/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:52:34 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 12:32:12 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	print_export2(t_data *data, char **tab)
{
	int	i;
	int	len;

	len = 0;
	while (tab[len])
	{
		i = 0;
		write(1, "declare -x ", 11);
		while (tab[len][i])
		{
			write(1, &(tab[len][i]), 1);
			if (tab[len][i] == '=' && tab[len][i + 1] == '\0')
			{
				if (check_in_valeur(data, tab[len]) == 1)
					break ;
			}
			if (tab[len][i++] == '=')
				write(1, "\"", 1);
		}
		if (check_in_valeur(data, tab[len++]) == 0)
			write(1, "\"", 1);
		write(1, "\n", 1);
	}
	free_tab(tab);
}

void	print_export(t_data *data)
{
	int		len;
	char	**tab;

	len = 0;
	while (data->tab_env[len] != NULL)
		len++;
	tab = malloc(sizeof(char *) * (len + 1));
	len = 0;
	while (data->tab_env[len])
	{
		tab[len] = ft_strdup(data->tab_env[len]);
		len++;
	}
	tab[len] = NULL;
	sort_tab(tab);
	print_export2(data, tab);
}

void	mmy_export(t_data *data)
{
	if (check_in_env(data, data->ex_variable, 0) == 1)
		export_var(data, 0);
	change_val(data);
	lst_to_tab(data);
}

void	my_exit(t_input *list)
{
	t_input	*ptr;
	int		exiting;

	ptr = list;
	write(1, "exit\n", 5);
	if (ptr->next == NULL)
		exit (0);
	if (ptr->next && ptr->next->next
		&& ptr->next->next->token_id != 'r' && ptr->next->next->next)
	{
		write(2, "exit: too many arguments\n", 25);
		g_exit_value = 1;
		return ;
	}
	if (ptr->next && ptr->next->next && ptr->next->next->token_id != 'r')
		write_and_exit(2, "exit: too many arguments\n", 1);
	exiting = ft_atoi(ptr->next->input);
	if (exiting == -1)
		write_and_exit(2, "exit: numeric argument required\n", 127);
	g_exit_value = exiting;
	exit (exiting);
}

int	check_egales(t_data *data, t_input *list)
{
	t_input	*ptr_lst;
	int		i;
	int		count;

	ptr_lst = list;
	count = 0;
	while (ptr_lst && ptr_lst->token_id == 'a')
	{
		i = 0;
		while (ptr_lst->input[i])
		{
			if (ptr_lst->input[i] == '=')
			{
				init_export(data, ptr_lst->input);
				if (ft_strlen(data->ex_variable) == 0)
					return (count);
				else
					mmy_export(data);
			}
			i++;
		}
		ptr_lst = ptr_lst->next;
	}
	return (count);
}
