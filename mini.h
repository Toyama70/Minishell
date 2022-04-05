/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:09:52 by tmartial          #+#    #+#             */
/*   Updated: 2022/03/20 12:32:37 by tmartial         ###   ########.fr       */
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
# include <termios.h>
# include <sys/param.h>
# include <readline/readline.h>
# include <readline/history.h>

int	g_exit_value;

typedef struct s_env {
	int				exported;
	char			*variable;
	char			*valeur;
	struct s_env	*next;
	struct s_env	*previous;
}				t_env;

typedef struct s_input
{
	char			*input;
	char			token_id;
	char			*out;
	char			*in;
	struct s_input	*prev;
	struct s_input	*next;
}	t_input;

typedef struct s_data {
	char			*line;
	char			*l_ret;
	char			**input;
	int				dquote;
	int				squote;
	int				spacenum;
	int				cmdfound;
	int				insquote;
	int				indquote;
	int				pos;
	int				pos2;
	int				status;
	struct termios	old;
	struct termios	new;
	char			*temp;
	int				dolstart;
	int				dolend;
	char			*dollar;
	char			*ex_variable;
	char			*ex_valeur;
	char			**tab_env;
	char			*home;
	t_env			*env;
}			t_data;

typedef struct s_redir
{
	int				fd;
	char			*name_file;
	struct s_redir	*next;
	struct s_redir	*prev;
}		t_redir;

typedef struct s_chain {
	char			*cmd;
	char			*error_msg;
	int				std_in;
	int				std_out;
	int				std_err;
	int				fd_in;
	int				fd_out;
	struct s_redir	*infile;
	struct s_redir	*outfile;
	struct s_chain	*pipe;
}		t_chain;

char	*slash(char *str);
char	**ft_envp(char *str);
void	child_bin(t_chain *chain);
int		is_bin(char *cmd);
size_t	ft_nextnotc(char *s, char c, int index);
void	ft_free_chain(t_chain *chain);
t_input	*listing2(t_data *data, t_input *list);
//static size_t	ft_nextc(char *s, char c, int index);
/* main */
t_input	*ft_parse(t_data *data, t_input *list, char **envp);
t_input	*ft_free_list(t_input *list);
int		is_builtin(t_data *data, t_input *list, t_chain *chain);
int		built_pipe(t_input *list);
int		is_path(char **str);
char	*ft_stralldup(char *s1, int size);

/* built_exe */
int		is_builtin(t_data *data, t_input *list, t_chain *chain);
int		built_pipe(t_input *list);
void	ft_close(t_chain *chain);
void	close_fd(t_redir *redir);

/* built1 */
void	my_pwd(t_data *data);
void	my_echo(t_input *list);
int		check_n(char *str);
void	my_env(t_data *data, t_input *list);
void	write_line(int fd, char *str);

/* built2 */
void	change_val(t_data *data);
void	export_var(t_data *data, int exporting);
int		check_in_env(t_data *data, char *ex_variable, int exporting);
int		check_in_valeur(t_data *data, char *ex_variable);
void	sort_tab(char **tab);

/* built3 */
int		cd_to_home(t_data *data);
void	change_pwd(t_data *data);
void	my_cd(t_data *data, t_input *list);

/* built4 */
void	my_unset(t_data *data, t_input *list);
void	remove_env(t_data *data, char *str);
void	init_export(t_data *data, char *input);
void	my_export(t_data *data, t_input *list);
void	write_and_exit(int fd, char *str, int ex);

/* built5 */
void	print_export2(t_data *data, char **tab);
void	print_export(t_data *data);
void	mmy_export(t_data *data);
void	my_exit(t_input *list);
int		check_egales(t_data *data, t_input *list);

/* errors */
int		ft_dollars(t_data *data);
int		sinquoteline(char *s, int i, int *back);
int		sinquotes(t_data *data, int i, int *back);
int		doubquoteline(char *s, int i, int *back);
int		doubquotes(t_data *data, int i, int *back);
int		ft_countquote(t_data *data);

/* execution */
t_redir	*set_infile(t_chain *chain);
t_redir	*set_outfile(t_chain *chain);
void	set_redir(t_chain *chain);
void	child(t_chain *chain, char **envp);
void	ft_exec(t_chain *chain, char **envp);
void	execution(t_chain *chain, char **envp);

/* ft_split */
char	**ft_free_all(char **tab, int i);
int		ft_count_words(const char *str, char c);
char	*ft_copy_str(const char *str, int start, int end);
char	**ft_create_tab(char **tab, const char *s, char c);
char	**ft_split(char const *s, char c);

/* libft utils */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, int start, int len);

/* libft utils 2 */
void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_bzero(void *s, size_t n);

/* parseur danny */
void	insert_block_double(t_input *check);
void	insert_block(t_input *check);
void	insert_block_case2(t_input *check, int pos);
void	insert_block_case2_double(t_input *check, int pos);
int		is_redir(char *str);
int		is_2chevron(char *str);
void	check_space(t_input *check);
void	insert_block_p(t_input *check);
void	insert_block_p_case2(t_input *check, int pos);
int		is_pipe(char *str);
void	check_space_pipe(t_input *check);
void	parse_q(t_input *list);
void	clean_cmd(t_input *list);

/* parseur danny2 */
int		find_last_q(char c, char *str, int pos);
int		is_pipe_q(char *str);
int		is_redir_q(char *str);
void	check_space_q(t_input *check);
void	check_space_pipe_q(t_input *check);
void	ft_close(t_chain *chain);

/* prepare_cmd */
void	init_chain(t_chain *chain);
int		return_tokenid(char c);
char	*add_cmd(char *current, char *add);
void	add_chain(t_chain *chain);
void	open_infile(t_chain *chain, char *name_file);
void	open_outfile1(t_chain *chain, char *name_file);
void	open_outfile2(t_chain *chain, char *name_file);
void	open_redir(t_input *list, t_chain *chain);
void	correct_file(t_input *list);
t_chain	*fill_chain(t_input *list, t_chain *chain);
void	clean_option(t_input *list);
int		is_slash(char *str);
char	*cut_cmd(char *cmd, int s, int err);
void	list_bin(t_chain *chain, int s, char **path, char **envp);
void	bin_check(t_chain *chain, char **envp);
t_chain	*prepare_cmd(t_input *list, char **envp);

/* redir_err */
void	close_infile(t_chain *chain);
void	close_outfile(t_chain *chain);
int		check_fd(t_chain *chain);
char	*ft_strndup(char *s1, int size);
char	*ft_strmdup(char *s1, int size);
void	redir_err(t_chain *chain, char **envp);

/* redir_err2 */
char	*extract_cmd(char *cmd);
int		check_exec(char *cmd);
void	redir_err(t_chain *chain, char **envp);

/* signal */
void	signalfound(int this_signal);
int		ft_readline(t_data *data);
char	*ft_replace_str(const char *s, size_t start, size_t n, const char *sub);
t_input	*fill_list(char *input, char token_id, t_input *list);
void	load_ios(t_data *data, char **envp);
int		ft_scanspace(char *s);

/* splitquote */
char	**ft_splitquote(char *s, char c);

/* splitquote2 */
int		ft_isinquote_now(char *str, int index);

/* test_command */
char	**path_access(char **envp);
char	*access_cmd(char **path, char *cmd);
int		test_command(char *cmd, char **envp);

/* tim libft */
char	*fft_strjoin(char *s1, char *s2);
char	*fft_strrchr(char *s, int c);
char	*fft_strchr(char *s, int c);

/* tim libft2 */
char	*ft_itoa(int n);
int		ft_atoi(const char *str);

/* tim libftlst */
void	make_env(t_data *data, char **envp);
void	link_lst(t_data *data);
void	free_tab(char **tab);
void	lst_to_tab(t_data *data);

/* tim lst */
t_env	*ft_lstnew(char *content, int exported);
t_env	*ft_lstlast(t_env *lst);
void	ft_lstadd_back(t_env **alst, t_env *new);
int		ft_lstsize(t_env *lst);
void	ft_lstclear(t_env *lst);

/* tim parser */
void	change_dollars(t_data *data);
void	change_dollars2(t_data *data);
void	remove_quotes(t_input *list);
char	*change_line(char *str);
void	move_element(int nb, t_input *list);
t_input	*ft_garbage(int argc, char **argv, t_data *data, char **envp);
void	ft_void(int argc, char **argv);
void	ft_trash(t_data *data);
int		to_continue(t_data *data);
int		to_continue2(t_input *list, t_data *data);

#endif
