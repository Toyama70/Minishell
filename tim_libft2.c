/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tim_libft2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:30:58 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/19 12:49:29 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static int	ft_putnbr_itoa(unsigned int nb, char *str, int i)
{
	if (nb >= 10)
	{
		i = ft_putnbr_itoa(nb / 10, str, i);
		i = ft_putnbr_itoa(nb % 10, str, i);
	}
	else
	{
		str[i] = (char)(nb + '0');
		i++;
	}
	return (i);
}

static int	mal_len(int c)
{
	int	len;
	int	save;

	save = c;
	len = 0;
	if (save < 0)
	{
		len++;
		save *= -1;
	}
	if (save == 0)
		len++;
	while (save != 0)
	{
		save /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * mal_len(n) + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		i++;
		i = ft_putnbr_itoa((unsigned int)(n * -1), str, i);
	}
	else
		i = ft_putnbr_itoa((unsigned int)n, str, i);
	str[i] = '\0';
	return (str);
}

int	verif_long(const char *str, int i, int signe)
{
	unsigned long long	num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += (str[i++] - '0');
		if (num > 255 && signe < 0)
			return (127);
	}
	return ((int)(num * signe));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	int	num;

	signe = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			signe *= -1;
		return (127);
	}
	if (str[i] > '9' || str[i] < '0' || str[i] == '\0')
		return (-1);
	num = (verif_long(str, i, signe));
	return (num);
}
