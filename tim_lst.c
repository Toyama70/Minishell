/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tim_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:55:49 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/18 16:30:21 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_env	*ft_lstnew(char *content, int exported)
{
	t_env	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		exit(127);
	new->exported = exported;
	new->variable = fft_strchr(content, '=');
	new->valeur = fft_strrchr(content, '=');
	new->next = NULL;
	new->previous = NULL;
	return (new);
}

t_env	*ft_lstlast(t_env *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_env **alst, t_env *new)
{	
	if (*alst == NULL)
	{
		*alst = new;
	}
	else
	{
		ft_lstlast(*alst)->next = new;
	}
}

int	ft_lstsize(t_env *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstclear(t_env *lst)
{
	t_env	*last;

	if (lst)
	{
		while (lst)
		{
			last = (lst)->next;
			free((lst)->variable);
			(lst)->variable = NULL;
			free((lst)->valeur);
			(lst)->valeur = NULL;
			lst = last;
		}
	}
}
