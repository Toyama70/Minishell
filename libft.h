/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybestrio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:14:00 by ybestrio          #+#    #+#             */
/*   Updated: 2022/03/01 10:36:55 by ybestrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>


char **ft_free_all(char **tab, int i);
static int  ft_count_words(const char *str, char c);
static char *ft_copy_str(const char *str, int start, int end);
static char **ft_create_tab(char **tab, const char *s, char c);
char    **ft_split(char const *s, char c);
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);



#endif
