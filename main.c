/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:21:39 by rponsonn          #+#    #+#             */
/*   Updated: 2021/12/12 19:30:22 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	main(void)
{
	t_data	**arr;

	arr = malloc((sizeof(t_data *) * TABLESIZE));
	if (arr == NULL)
		return (1);
	init_table(arr);
	if (parse_stdin(arr) == 1)
	{
		free_everything(arr);
		free(arr);
		return (1);
	}
	process_requests(arr);
	free_everything(arr);
	free(arr);
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
		ptr = ft_parse(&flag);
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
			add_last(arr[i], ptr);
	}
	return (0);
}
