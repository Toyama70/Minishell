/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:12:53 by ybestrio          #+#    #+#             */
/*   Updated: 2022/03/03 13:52:05 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"
#include "libft.h"

int	ft_count_element(const char *str, char c)
{
	int	count;
	int	i;
	int	trigger;

	i = 0;
	count = 0;
	trigger = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (str[i] == c)
			trigger = 0;
		i++;
	}
	return (count);
}

char	*ft_copy_elem(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((sizeof(char) * (end - start + 1)));
	if (!word)
		return (0);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_create_tabquote(char **tab, const char *s, char c)
{
	int		i;
	size_t	count;
	int		start;

	i = 0;
	count = 0;
	start = -1;
	while (i <= (int)ft_strlen((char *)s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == (int)ft_strlen((char *)s)) && start >= 0)
		{
			tab[count++] = ft_copy_elem(s, start, i);
			if (!tab[count - 1])
				return (ft_free_all(tab, count - 1));
			start = -1;
		}
		i++;
	}
	tab[count] = NULL;
	return (tab);
}

char	**ft_splitquote(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (0);
	tab = malloc(sizeof(char *) * (ft_count_element(s, c) + 1));
	if (!tab)
		return (0);
	return (ft_create_tabquote(tab, s, c));
}
