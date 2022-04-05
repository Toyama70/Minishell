/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:29:19 by dfernand          #+#    #+#             */
/*   Updated: 2022/03/20 10:26:59 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	close_infile(t_chain *chain)
{
	t_redir	*tmp;

	tmp = NULL;
	if (chain->infile)
		tmp = chain->infile;
	while (tmp)
	{
		close(tmp->fd);
		if (tmp->name_file)
		{
			free(tmp->name_file);
			tmp->name_file = NULL;
		}
		tmp = tmp->next;
	}
}

void	close_outfile(t_chain *chain)
{
	t_redir	*tmp;

	tmp = chain->outfile;
	while (tmp)
	{
		close(tmp->fd);
		if (tmp->name_file)
		{
			free(tmp->name_file);
			tmp->name_file = NULL;
		}
		tmp = tmp->next;
	}
}

int	check_fd(t_chain *chain)
{
	int		ret;
	t_redir	*tmp;

	ret = 0;
	tmp = chain->infile;
	while (tmp)
	{
		if (tmp->fd == -1)
		{
			ret = 1;
			chain->error_msg = ft_strdup("no such file or directory: ");
			chain->error_msg = ft_strjoin(chain->error_msg, tmp->name_file);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

char	*ft_strndup(char *s1, int size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[i] != '\0' && i < size)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strmdup(char *s1, int size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) - size + 1));
	if (ptr == NULL)
		return (NULL);
	while (s1[size + i] != '\0' && s1[size + i] != ' ')
	{
		ptr[i] = s1[size + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
