/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 14:07:48 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/19 13:39:08 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != 0)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	signalfound(int this_signal)
{
	if (this_signal == SIGINT)
	{
		rl_replace_line("", 0);
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	ft_readline(t_data *data)
{
	int	n;

	n = 0;
	data->line = readline("~$ ");
	if (data->line && data->line[0])
		add_history(data->line);
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
