/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:12:53 by ybestrio          #+#    #+#             */
/*   Updated: 2022/03/20 10:35:06 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	ft_isinquote_now(char *str, int index)
{
	int		b;
	int		i;

	b = 0;
	i = -1;
	while (++i <= index && str[i])
	{
		if (b != '"' && str[i] == '\'')
			while (str[++i] && str[i] != '\'' && i <= index)
				b = '\'';
		if (i > index)
			return (b != 0);
		b = 0;
		if (b != '\'' && str[i] == '"')
			while (str[++i] && str[i] != '"' && i <= index)
				b = '"';
		if (i > index)
			return (b != 0);
	}
	return (b != str[i - 1] && (b == '\'' || b == '"'));
}

static size_t	ft_nextc(char *s, char c, int index)
{
	while (1)
	{
		while (s[index] && s[index] != c)
			index++;
		if (!s[index] || !ft_isinquote_now(s, index))
			break ;
		index++;
	}
	return (index);
}

static size_t	ft_getnum(char *s, char c)
{
	int		onword;
	size_t	count;
	size_t	i;

	count = 0;
	onword = 1;
	i = -1;
	if (*s != c)
		onword = 0;
	while (s[++i])
	{
		if (onword == 0 && s[i] != c)
			count++;
		if (s[i] == c && !ft_isinquote_now(s, i))
			onword = 0;
		else
			onword = 1;
	}
	return (count);
}

static int	ft_myfrees(char **r, size_t n)
{
	size_t	i;
	int		b;

	i = -1;
	b = 1;
	while (++i < n)
		b *= r[i] != 0;
	if (b)
		return (1);
	i = -1;
	while (++i < n)
		if (r[i])
			free(r[i]);
	free(r);
	return (0);
}

char	**ft_splitquote(char *s, char c)
{
	char			**r;
	size_t			i;
	size_t			j;
	size_t			n;
	size_t			n2;

	if (!s)
		return (0);
	n2 = ft_getnum(s, c);
	n = n2;
	r = malloc((n + 1) * sizeof(char *));
	if (!r)
		return (0);
	r[n] = 0;
	i = 0;
	while (n--)
	{
		i = ft_nextnotc(s, c, i);
		j = ft_nextc(s, c, i);
		*r++ = ft_substr(s, i, j - i);
		i += j - i;
	}
	if (!ft_myfrees(r - n2, n2))
		return (0);
	return (r - n2);
}
