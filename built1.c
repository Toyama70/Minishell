/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:01:41 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 12:31:41 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	my_pwd(t_data *data)
{
	t_env	*ptr;

	ptr = data->env;
	while (ptr)
	{
		if (ft_strncmp(ptr->variable, "PWD=", 4) == 0)
		{
			write(1, ptr->valeur, ft_strlen(ptr->valeur));
			write(1, "\n", 1);
			break ;
		}
		ptr = ptr->next;
	}
	g_exit_value = 0;
}

void	my_echo(t_input *list)
{
	t_input	*ptr;
	int		option;

	ptr = list;
	option = 1;
	if (ptr->next == NULL)
		return (write_line(1, "\n"));
	ptr = ptr->next;
	while (ptr && ptr->token_id != 'r')
	{
		if (ptr->token_id == 'o' && check_n(ptr->input) == 0
			&& option == 1 && ptr->prev && ptr->prev->token_id == 'c')
			option = 0;
		else
		{
			write(1, ptr->input, ft_strlen(ptr->input));
			if (ptr->next)
				write(1, " ", 1);
		}
		ptr = ptr->next;
	}
	if (option == 1)
		write(1, "\n", 1);
	g_exit_value = 0;
}

int	check_n(char *str)
{
	int	i;

	i = 1;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

void	my_env(t_data *data, t_input *list)
{
	t_env	*ptr;
	t_input	*ptr_lst;

	ptr = data->env;
	ptr_lst = list;
	if (ptr_lst->next)
	{
		perror("env");
		g_exit_value = 127;
		return ;
	}
	while (ptr)
	{
		if (ptr->exported == 1)
		{
			write(1, ptr->variable, ft_strlen(ptr->variable));
			if (ptr->valeur)
				write(1, ptr->valeur, ft_strlen(ptr->valeur));
			write(1, "\n", 1);
		}
		ptr = ptr->next;
	}
	g_exit_value = 0;
}

void	write_line(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}
