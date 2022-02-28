/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:09:52 by tmartial          #+#    #+#             */
/*   Updated: 2022/02/28 22:37:25 by yasinbest        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_data {
	char *line;
    char *l_ret;
	char **env;
	char **input;

	int spacenum;
	
}           t_data;

/* main */
void    my_pwd(t_data *data);
void    my_echo(t_data *data);
void    my_env(t_data *data);

/* parser */
void make_env(t_data *data, char **env);

/* gnl */
unsigned int	ft_strlen(char *s);
char			*free_all(char *line, char **save, char *buffer, int ret);
int				fill_line(char **line, char **save, char *buffer, int ret);
int				check_save(char **line, char **save);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *s1);
char			*ft_strchr(char *s, int c);
char			*ft_substr(char *s, unsigned int start, size_t len);
unsigned int	pos_n(char *buffer);
char			*get_next_line(int fd);

#endif
