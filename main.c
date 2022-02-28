/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasinbestrioui <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:26:24 by yasinbest         #+#    #+#             */
/*   Updated: 2022/02/28 23:18:16 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"

void	ft_spacenum(t_data *data)
{
	int i = 0;
	data->spacenum = 0;

	while (data->line[i] != 0)
	{
		if (data->line[i] == ' ')
		{
			data->spacenum++;
			while (data->line[i] == ' ')
				i++;
		}
		i++;
	}
	if (data->line[i - 2] == ' ' && data->spacenum != 0)
		data->spacenum -= 1;
	if (data->line[0] == ' ' && data->spacenum != 0)
		data->spacenum -= 1;
}

void	ft_empty(t_data *data)
{
(void)(data);


}

void	ft_parse(t_data *data)
{
	write(1, "ok in parse\n", 12);
	sleep(1);
//	ft_empty(data);
	ft_spacenum(data);
	data->spacenum += 1;
	printf("%d\n", data->spacenum);
}

int main()
{
	t_data data;
	
	write(1,"ok\n", 3);
	write(0, "~$ ", 3);
    while ((data.line = get_next_line(0)) != NULL)
	{
  		ft_parse(&data);

		write(0, "~$ ", 3);
		free(data.line);
	}
    return (0);
}
