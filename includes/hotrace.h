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

int		get_next_line(int fd, char **line, int ret);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_gnl_strjoin(char **s1, const char *s2);
int		ft_loop(char **ptr, int *ret, int *fd, char *data);
int		ft_im_out_of_lines(char **line, int output);
void	add_last(t_data *head, t_data *new);
int		hash(const char *str);

#endif