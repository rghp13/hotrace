/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:26:35 by rponsonn          #+#    #+#             */
/*   Updated: 2021/12/12 22:33:50 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# define TABLESIZE 3021377
# define ERROR ": Not found.\n"
# define GNL_BUFFER_SIZE 64

typedef struct s_data
{
	char			*key;
	char			*value;
	struct s_data	*next;
}					t_data;

int		parse_stdin(t_data **arr);
int		get_next_line(char **line);
int		hash(const char *str);
int		process_requests(t_data **arr);
void	ft_search_list(t_data *data, char *key_check);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_gnl_strjoin(char **s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	init_table(t_data **arr);
void	free_everything(t_data **arr);
void	free_list(t_data *data);
t_data	*ft_parse(int *flag);
void	add_last(t_data *head, t_data *new);
t_data	*ft_malloc(int *flag);
int		ft_datacheck_key(char **ptr, int *flag, t_data *data);
int		ft_datacheck_value(char **ptr, int *flag, t_data *data);
char	*ft_process(int *flag);
void	ft_putstr(const char *str);
void	ft_print_value(const char *str);
int		ft_check_key_val(const char *s1, const char *s2);

#endif