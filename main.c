#include "hotrace.h"

int	main(void)
{
	t_data	*arr[TABLESIZE];
	int64_t time_start;

	time_start = get_time();
	init_table(arr);
	if (parse_stdin(arr) == 1)
	{
		free_everything(arr);
		return (1);
	}
	printf("\n%ld\n\n", get_time() - time_start);
	process_requests(arr);
	printf("\n%ld\n\n", get_time() - time_start);
	free_everything(arr);
	return (0);
}

void	init_table(t_data **arr)
{
	int	i;

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
		if (flag == 1 || flag == -1)
		{
			if (ptr)
				free(ptr);
			if (flag == -1)
				return (1);
			return (0);
		}
		i = hash(ptr->key);
		if (i < 0)
			return (1);
		if (arr[i] == NULL)
			arr[i] = ptr;
		else
			add_first(&arr[i], ptr);
	}
	return (0);
}
