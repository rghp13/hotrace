#include "hotrace.h"

int	process_requests(t_data **arr)
{
	int		flag;
	int		i;
	char	*ptr;

	flag = 0;
	while (1)
	{
		ptr = ft_process(&flag);
		if (flag == -1)
			return (1);
		if (flag == 1)
			return (0);
		i = hash(ptr);
		if (i == -1)
			return (-1);
		if (arr[i] == NULL)
			return (ft_putstr(ERROR));
		ft_search_list(arr[i], ptr);//find and print otherwise print error message
	}
}

void	ft_search_list(t_data *data, char *key_check)
{
	t_data	*ptr;
	int		flag;
	int		len;

	len = ft_strlen(key_check);
	ptr = data;
	while (ptr != NULL)
	{
		if (ft_strncmp(data->key, key_check, len) == 0 && len == \
		ft_strlen(data->key))
		{
			ft_print_value(data->value);
			flag = 1;
		}
		ptr = ptr->next;
	}
	if (flag == 0)
		ft_putstr(ERROR);
}
