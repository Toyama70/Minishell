/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:26:24 by yasinbest         #+#    #+#             */
/*   Updated: 2022/03/03 13:54:08 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"


//c == command, a == args, o == options, f == file, p == pipe, r=chevrons

void	ft_parse(t_data *data, t_input *list, char **envp)
{
	int i = -1;
	data->cmdfound = 0;
	
	if (ft_countquote(data) == 1)
	{
		write(2, "Error : quote not closed ?\n", 27);
		return ;
	}

	if (data->line != 0)
	{
		if (data->dquote == 0 || data->squote == 0)
		{
			data->input = ft_split(data->line, ' ');
			while (data->input[++i] != 0)
			{
				if (test_command(data->input[i], envp) == 1 && data->spacenum == 0)
				{
					list = fill_list(data->input[i], 'c', list);
					data->spacenum++;
					printf("list = %s\n", list->input);
					printf("token = %c\n", list->token_id);
				}
				else if (open(data->input[i], O_RDONLY) != -1)
				{
					list = fill_list(data->input[i], 'f', list);
					printf("list = %s\n", list->input);
					printf("token = %c\n", list->token_id);
				}
				else 
				{
					list = fill_list(data->input[i], 'a', list);
					printf("list = %s\n", list->input);
					printf("token = %c\n", list->token_id);
				}
			}
		}
		//temporary content inside else if
	else if (data->dquote != 0 || data->squote != 0)// il y a une quote donc ameliorer les verifs de quotes ne pas quitter direct	
		{
			data->input = ft_split(data->line, ' ');
			while (data->input[++i] != 0)
			{
				if (test_command(data->input[i], envp) == 1 && data->spacenum == 0)
				{
					list = fill_list(data->input[i], 'c', list);
					data->spacenum++;
					printf("list = %s\n", list->input);
					printf("token = %c\n", list->token_id);
				}
				else if (open(data->input[i], O_RDONLY) != -1)
				{
					list = fill_list(data->input[i], 'f', list);
					printf("list = %s\n", list->input);
					printf("token = %c\n", list->token_id);
				}
				else 
				{
					list = fill_list(data->input[i], 'a', list);
					printf("list = %s\n", list->input);
					printf("token = %c\n", list->token_id);
				}
			}
		}
	
	
	
	}
	
			
	ft_free_all(data->input, 0);
}

void	ft_cleanline(char *str)
{
	int i = 0;

	i = strlen(str);
	str[i-1] = 0;

}

int main(int argc, char **argv, char **envp)
{
	t_data data;
	t_input *list;
	//data.envp = envp;
	
	(void)(argc);
	(void)(argv);

	list = NULL;
	write(0, "~$ ", 3);
    while ((data.line = get_next_line(0)) != NULL)
	{
		ft_cleanline(data.line);
		ft_parse(&data, list, envp);

		write(0, "~$ ", 3);
		free(data.line);
	}

	
	//	system("leaks minishell");
}
