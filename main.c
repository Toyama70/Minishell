/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:26:24 by yasinbest         #+#    #+#             */
/*   Updated: 2022/03/14 11:28:14 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

//aef'aef aef'

//c == command, a == args, o == options, f == file, r=chevrons, p = "pipe", 
//d = contient un dollar, e = export avec =

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
		if (data->dquote == 0 && data->squote == 0)
		{
			data->input = ft_split(data->line, ' ');
			while (data->input[++i] != 0)
			{
				if (test_command(data->input[i], envp) == 1)
				{
					list = fill_list(data->input[i], 'c', list);
					data->spacenum++; // spacenum sert a compter les commandes
					printf("list = %s\n", list->input);
					printf("token = %c\n", list->token_id);
				}
				else if (open(data->input[i], O_RDONLY) != -1)
				{
					list = fill_list(data->input[i], 'f', list);
					printf("list = %s\n", list->input);
					printf("token = %c\n", list->token_id);
				}
				else if (data->input[i][0] == '-')
				{
					list = fill_list(data->input[i], 'o', list);
					printf("list = %s\n", list->input);
					printf("token = %c\n", list->token_id);
				}
				else if (data->input[i][0] == '/')
				{
					list = fill_list(data->input[i], 'w', list);
					printf("list = %s\n", list->input);
					printf("token = %c\n", list->token_id);
				}
				else if (ft_export(data, i) == 1) //creer une fonction
				{
					list = fill_list(data->input[i], 'e', list);
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
	if (data->dquote != 0 || data->squote != 0)// il y a une quote donc ameliorer les verifs de quotes ne pas quitter direct	
		{
			data->input = ft_splitquote(data->line, ' ', data);
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
				else if (data->input[i][0] == '-')
				{
					list = fill_list(data->input[i], 'o', list);
					printf("list = %s\n", list->input);
					printf("token = %c\n", list->token_id);
				}
				else if (data->input[i][0] == '/')
				{
					list = fill_list(data->input[i], 'w', list);
					printf("list = %s\n", list->input);
					printf("token = %c\n", list->token_id);
				}
				else if (ft_export(data, i) == 1) //creer une fonction et ajouter chez Danny
				{
					list = fill_list(data->input[i], 'e', list);
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

char	*ft_replace_str(const char *s, size_t start, size_t n, const char *sub)
{
	size_t	i;
	size_t	sl;
	size_t	l;
	char	*tmp;

	sl = strlen(sub);
	l = strlen(s) - n + sl;
	tmp = malloc(sizeof(char) * (l + 2));
	if (!tmp)
		return (NULL);
	i = -1;
	while (++i < start)
		tmp[i] = s[i];
	i--;
	while (++i < start + sl)
		tmp[i] = sub[i - start];
	i--;
	while (++i < l)
		tmp[i] = s[i - sl + n];
	tmp[i] = 0;
	return (tmp);
}



int ft_readline(t_data *data)
{
	int	n;

	n = 0;
	data->line = readline("minishell>");
	if (!data->line)
		exit(1);
	while (data->line[n])
	{
		if (data->line[n] == 9)
		{
			data->temp = strdup(data->line);
			free(data->line);
			data->line = ft_replace_str(data->temp, n, 1, "    ");
			free(data->temp);
			n = 0;
			continue ;
		}
		n++;
	}
	return (0);


}

int main(int argc, char **argv/*, char **envp*/)
{
	t_data data;
	t_input *list;
	//data.envp = envp;
	
	(void)(argc);
	(void)(argv);

	list = NULL;
	write(0, "~$ ", 3);
	while (1)
	{
		ft_readline(&data);


	}
	/*
    while ((data.line = get_next_line(0)) != NULL)
	{
		ft_cleanline(data.line);
		ft_parse(&data, list, envp);

		write(0, "~$ ", 3);
		free(data.line);
	}
*/
	
	//	system("leaks minishell");
}
