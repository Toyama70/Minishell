/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:46:34 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 12:31:55 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	cd_to_home(t_data *data)
{
	int	j;

	j = 0;
	while (data->tab_env[j])
	{
		if (ft_strncmp(data->tab_env[j], "HOME", 4) == 0)
		{
			if (chdir(data->home) == -1)
			{
				perror("chdir()");
				return (1);
			}
			return (0);
		}
		j++;
	}
	perror("chdir()");
	return (1);
}

void	change_pwd(t_data *data)
{
	t_env	*ptr;
	char	cwd[1000];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd()");
		return ;
	}
	ptr = data->env;
	while (ptr)
	{
		if (ft_strncmp(ptr->variable, "PWD", 3) == 0)
		{
			free(ptr->valeur);
			ptr->valeur = ft_strdup(cwd);
			break ;
		}
		ptr = ptr->next;
	}
}

void	my_cd(t_data *data, t_input *list)
{
	t_input	*ptr_lst;

	ptr_lst = list;
	if (ptr_lst->next == NULL)
	{
		if (cd_to_home(data) == 1)
		{
			g_exit_value = 127;
			return ;
		}
	}
	else
	{
		if (chdir(ptr_lst->next->input) == -1)
		{
			perror("chdir()");
			g_exit_value = 127;
			return ;
		}
	}
	g_exit_value = 0;
	change_pwd(data);
	lst_to_tab(data);
}
