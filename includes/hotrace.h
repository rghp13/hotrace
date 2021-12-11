#ifndef HOTRACE_H
# define HOTRACE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# define TABLESIZE 1024
# define ERROR "ERROR : INVALID VALUE\n"
# define GNL_BUFFER_SIZE 32

typedef struct s_data
{
	char			*key;
	char			*value;
	struct s_data	*next;
}					t_data;

int		parse_stdin(t_data **arr);
int		get_next_line(int fd, char **line, int ret);
int		hash(const char *str);
int		process_requests(t_data **arr);
void	ft_search_list(t_data *data, char *key_check);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_gnl_strjoin(char **s1, const char *s2);
void	addlast(t_data *head, t_data *new);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif