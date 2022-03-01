/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:26:24 by yasinbest         #+#    #+#             */
/*   Updated: 2022/03/01 15:06:35 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"


//c == command, a == args, o == options, f == file

void	ft_parse(t_data *data, t_input *list, char **envp)
{
	
	
	data->input = ft_split(data->line, ' ');
	data->spacenum = 0;

	if (data->input[0] != 0)
	{
/*		int i = 0;
		while (data->envp)
		printf("", 
		)*/		
		printf("-->%s----", data->input[0]);
		if (test_command(data->input[0], envp) == 1)
		{
			list = fill_list(data->input[0], 'c', list);
		}
		else if (open(data->input[0], O_RDONLY) != -1)
		{
			list = fill_list(data->input[0], 'f', list);
		}
		else 
		{
			list = fill_list(data->input[0], 'a', list);
		}
	}
	ft_free_all(data->input, 0);
	printf("list = %s\n", list->input);
	printf("token = %c\n", list->token_id);
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
  		
		ft_parse(&data, list, envp);

		write(0, "~$ ", 3);
		free(data.line);
	}

	
	//	system("leaks minishell");
}
