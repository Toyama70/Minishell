/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:16:48 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 12:32:46 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	ft_signal_launch(void)
{
	signal(SIGINT, signalfound);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_void(int argc, char **argv)
{
	(void)(argc);
	(void)(argv);
}

t_input	*ft_garbage(int argc, char **argv, t_data *data, char **envp)
{
	ft_void(argc, argv);
	load_ios(data, envp);
	ft_signal_launch();
	make_env(data, envp);
	lst_to_tab(data);
	g_exit_value = 0;
	return (NULL);
}

void	ft_trash(t_data *data)
{
	data->spacenum = 0;
	ft_signal_launch();
	ft_readline(data);
}
