#include "hotrace.h"

void	addlast(t_data *head, t_data *new)
{
	t_data	*ptr;

	ptr = head;
	if (head->next == NULL)
	{
		head->next = new;
		return ;
	}
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = new;
	return ;
}
