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

/*
**error exists in how struct is assigned next pointer
*/

void	free_list(t_data *data)
{
	t_data	*next;
	t_data	*current;

	current = data;
	while (current != NULL)
	{
		next = current->next;
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}
	return ;
}
