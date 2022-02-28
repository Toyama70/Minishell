/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:09:24 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/28 09:09:26 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*free_all(char *line, char **save, char *buffer, int ret)
{
	free(buffer);
	if (ret == 2)
	{
		return (line);
	}
	if (ret == 0)
	{
		if (*save)
		{
			free(*save);
			*save = NULL;
		}
		if (ft_strlen(line) > 0)
			return (line);
		else
		{
			free(line);
			return (NULL);
		}
	}
	return (NULL);
}

int	fill_line(char **line, char **save, char *buffer, int ret)
{
	char	*tmp;

	if (ret > 0)
	{
		tmp = ft_substr(buffer, 0, pos_n(buffer));
		*line = ft_strjoin(*line, tmp);
		free(tmp);
		if (ft_strlen(buffer) != pos_n(buffer))
		{
			if (!(*save))
				*save = ft_strdup("");
			tmp = ft_substr(buffer, pos_n(buffer), ft_strlen(buffer));
			*save = ft_strjoin(*save, tmp);
			free(tmp);
			if (*line == NULL || *save == NULL)
				return (0);
			return (2);
		}
		if (((*line)[pos_n((*line)) - 1]) == '\n')
			return (2);
		return (1);
	}
	return (0);
}

int	check_save(char **line, char **save)
{
	char	*tmp;

	if ((*save))
	{
		if (ft_strlen(*save) > 0)
		{
			free(*line);
			*line = ft_substr(*save, 0, pos_n(*save));
			tmp = ft_substr(*save, pos_n(*save), ft_strlen(*save));
			free(*save);
			*save = ft_strdup(tmp);
			free(tmp);
			if (*line == NULL || *save == NULL)
				return (0);
			if (((*line)[pos_n((*line)) - 1]) == '\n')
				return (2);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save;
	char		*line;
	int			ret;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc(sizeof(char) * 1 + 1);
	line = ft_strdup("");
	if (line == NULL || buffer == NULL)
		return (NULL);
	ret = check_save(&line, &save);
	while (ret == 1)
	{
		ret = read(fd, buffer, 1);
		buffer[ret] = '\0';
		ret = fill_line(&line, &save, buffer, ret);
	}
	return (free_all(line, &save, buffer, ret));
}	