#include "hotrace.h"

void	free_everything(t_data **arr)
{
	int	i;

	i = 0;
	while (i < TABLESIZE)
	{
		if (arr[i])
			free_list(arr[i]);
		i++;
	}
	return ;
}

void	free_list(t_data *data)
{
	t_data	*next;
	t_data	*current;

	if (data->next == NULL)
	{
		free(data->key);
		free(data->value);
		free(data);
		return ;
	}
	current = data;
	while (current)
	{
		next = current->next;
		free(data->key);
		free(data->value);
		free(data);
		current = next;
	}
	return ;
}
