/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:25:32 by rponsonn          #+#    #+#             */
/*   Updated: 2021/12/12 19:36:40 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
