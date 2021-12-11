#ifndef HOTRACE_H
# define HOTRACE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# define TABLESIZE 12
# define ERROR "ERROR : INVALID VALUE\n"
# define GNL_BUFFER_SIZE 32

typedef struct s_data
{
	char			*key;
	char			*value;
	struct s_data	*next;
}					t_data;

#endif