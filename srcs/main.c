#include "hotrace.h"

int	main(void)
{
	t_data	*arr[TABLESIZE];

	init_table(arr);
	if (parse_stdin(arr) == 1)
	{
		free_everything(arr);
		return (1);
	}
	process_requests(arr);
	free_everything(arr);
	return (0);
}

void	init_table(t_data **arr)
{
	int i;

	i = 0;
	while (i < TABLESIZE)
	{
		arr[i] = NULL;
		i++;
	}
	return ;
}

int	parse_stdin(t_data **arr)
{
	t_data	*ptr;
	int		flag;
	int		i;

	flag = 0;
	while (1)
	{
		ptr = ft_parse(&flag);//if -1 might need to free ptr
		if (flag == 1)
			break ;
		if (flag == -1)
		{
			if (ptr)
				free(ptr);
			return (1);
		}
		i = hash(ptr->key);
		if (i < 0)
			return (1);
		if (arr[i] == NULL)
			arr[i] = ptr;
		else
			add_last(arr[i], ptr);
	}
	return (0);
}
