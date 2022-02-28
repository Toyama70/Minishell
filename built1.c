/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:01:41 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/28 14:20:56 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void my_pwd(t_data *data)
{
	if (strncmp(data->line, "pwd", 3) == 0)
	{
		char cwd[10000];
        
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
	       	printf("%s\n", cwd);
		}
		else
		{
			perror("error pwd");
		}
	}
}

void my_echo(t_data *data)
{
	int	i;

	i = 4;
	while (data->line[i] == ' ')
		i++;
	data->l_ret = ft_substr(data->line, i, ft_strlen(data->line) - 1);
	printf("%s",data->l_ret);
}

void	my_env(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
		printf("%s\n",data->env[i++]);
}