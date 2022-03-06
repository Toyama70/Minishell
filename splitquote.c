/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:12:53 by ybestrio          #+#    #+#             */
/*   Updated: 2022/03/06 15:45:04 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"
#include "libft.h"

int	ft_count_elements(const char *str, char c, t_data *data) //trop d elements calcules mais pas un souci trigger non utilise dans quotes mais calloc donc ok
{
	int	count;
	int	i;
	int	trigger;
	int status;
	int back;

	i = 0;
	count = 0;
	trigger = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' && trigger == 0)
		{
			if (str[i + 1] == '\'')
			{
				i = i + 2;
				continue ;
			}
			status = sinquotes(data, i, &back);
			if (status == 0)
			{
				i = back;
				count++; //gerer les '' vides
			}
		}
		if (str[i] == '\"' && trigger == 0)
		{
			if (str[i + 1] == '\"')
			{
				i = i + 2;
				continue ;
			}
			status = doubquotes(data, i, &back);
			if (status == 0)
			{
				i = back;
				count++;
			}
		}
		if (str[i] != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		if (str[i] == c)
			trigger = 0;
		i++;
	}
	printf("elemcount = %d \n", count);
	return (count);
}

char	*ft_copy_elem(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = calloc(sizeof(char), (end - start + 1));
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
	int		back;

	i = 0;
	count = 0;
	start = -1;

	while (s[i] != 0)
	{
		if (s[i] != c && start < 0)
			start = i;
		if (s[i] == '\'') //regler les '' vides;
		{
			if (s[i + 1] == '\'')
			{
				i = i + 2;
				start = -1;
				continue ;
			}
			if (start == -1)
				start = i;
			sinquoteline((char *)s, i, &back);
			i = back + 1;
		}
		if (s[i] == '\"') //regler les '' vides;
		{
			if (s[i + 1] == '\"')
			{
				i = i + 2;
				start = -1;
				continue ;
			}
			if (start == -1)
				start = i;
			doubquoteline((char *)s, i, &back);
			i = back + 1;
		}
		if ((s[i] == c || i == (int)ft_strlen((char *)s) || s[i] == '\'' || s[i] == '\"') && start >= 0)
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

char	**ft_splitquote(char const *s, char c, t_data *data)
{
	char	**tab;

	if (!s)
		return (0);
	tab = calloc(sizeof(char *), (ft_count_elements(s, c, data) + 3));

	if (!tab)
		return (0);
	return (ft_create_tabquote(tab, s, c));
}
