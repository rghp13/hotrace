/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:26:45 by rponsonn          #+#    #+#             */
/*   Updated: 2021/12/12 21:52:53 by vrigaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		{
			ft_putstr(ptr);
			ft_putstr(ERROR);
		}
		ft_search_list(arr[i], ptr);
		free(ptr);
	}
}

void	ft_search_list(t_data *data, char *key_check)
{
	t_data	*ptr;
	int		flag;
	int		len;

	flag = 0;
	len = ft_strlen(key_check);
	ptr = data;
	while (ptr != NULL)
	{
		if (ft_strncmp(ptr->key, key_check, len) == 0 && len == \
		(int)ft_strlen(ptr->key))
		{
			ft_print_value(ptr->value);
			flag = 1;
			return ;
		}
		ptr = ptr->next;
	}
	if (flag == 0)
	{
		ft_putstr(key_check);
		ft_putstr(ERROR);
	}
}
