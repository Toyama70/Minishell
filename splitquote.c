/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitquote.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:12:53 by ybestrio          #+#    #+#             */
/*   Updated: 2022/03/05 11:38:10 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mini.h"
#include "libft.h"

int	ft_count_elements(const char *str, char c, t_data *data)
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
			status = sinquotes(data, i, &back);
			if (status == 0)
			{
				i = back;
				count++; //gerer les '' vides
			}
		}
		if (str[i] == '\"' && trigger == 0)
		{
			status = doubquotes(data, i, &back);
			if (status == 0)
			{
				i = back;
				count++;
			}
		}
		else if (str[i] != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (str[i] == c)
			trigger = 0;
		i++;
	}
	printf("\nelements count = %d\n", count);
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

	while (i <= (int)ft_strlen((char *)s))
	{
		if (s[i] != c && start < 0)
			start = i;
		if (s[i] == '\'') //regler les '' vides;
		{
			if (start == -1)
				start = i;
			sinquoteline((char *)s, i, &back);
			i = back + 1;
		}
		if (s[i] == '\"') //regler les '' vides;
		{
			if (start == -1)
			{
				start = i; // doesn't work with empty ''
			
			}	
			doubquoteline((char *)s, i, &back);
			i = back +1;
		}
		else if ((s[i] == c || i == (int)ft_strlen((char *)s) || s[i] == '\'' || s[i] == '\"') && start >= 0)
		{
			printf("\n i avant tab = %d\n", i);
			printf("\n start avant tab = %d\n", start);
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
	tab = calloc(sizeof(char *), (ft_count_elements(s, c, data) + 1));
	if (!tab)
		return (0);
	return (ft_create_tabquote(tab, s, c));
}
