/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:09:52 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/02 17:56:41 by yasinbest        ###   ########.fr       */
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

typedef struct s_input
{
	char	*input;
	char    token_id;
	struct s_input	*prev;
	struct s_input	*next;
}	t_input;

typedef struct s_data {
	char *line;
    char *l_ret;
	char **env;
	char **input;
	char **envp;
	int dquote;// 1 == pair / 0 == unclosed dquote | if closed is it an option with -xxxx
	int squote;// 1 -- pair / 0 == unclosed squote
	int spacenum;
	int cmdfound;
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

/* split */
char		**ft_split(char const *s, char c);
char	**ft_free_all(char **tab, int i);
t_input *fill_list(char *input, char token_id, t_input *list);


char	**ft_splitquote(char const *s, char c);
static char	**ft_create_tabquote(char **tab, const char *s, char c);
static char	*ft_copy_elem(const char *str, int start, int end);
static int	ft_count_element(const char *str, char c);
int	test_command(char *cmd, char **envp);
char	*access_cmd(char **path, char *cmd);
char	**path_access(char **envp);

/* errors */
int	ft_countquote(t_data *data);

#endif
