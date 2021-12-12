/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:09:30 by vrigaudy          #+#    #+#             */
/*   Updated: 2021/12/12 14:02:43 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_data	*ft_malloc(int *flag)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		*flag = -1;
	return (data);
}

int	ft_datacheck_key(char **ptr, int *flag, t_data *data)
{
	int	ret;

	ret = get_next_line(STDIN_FILENO, ptr, 0);
	if (ret == -1)
	{
		*flag = -1;
		return (-1);
	}
	if (ft_strlen(*ptr) == 0)
	{
		free(data);
		*flag = 1;
		if (ret == 0)
		{
			*flag = -1;
			return (-1);
		}
		return (1);
	}
	return (0);
}

int	ft_datacheck_value(char **ptr, int *flag, t_data *data)
{
	int	ret;

	ret = get_next_line(STDIN_FILENO, ptr, 0);
	if (ret == -1)
	{
		free(data->key);
		free(data);
		*flag = -1;
	}
	if (ret == 0)
		*flag = -1;
	return (ret);
}

t_data	*ft_parse(int *flag)
{
	int		i;
	int		ret;
	char	*ptr;
	t_data	*data;

	i = 0;
	data = ft_malloc(flag);
	if (!data)
		return (NULL);
	data->next = NULL;
	ret = ft_datacheck_key(&ptr, flag, data);
	if (ret == -1 || ret == 1)
		return (NULL);
	data->key = ptr;
	ret = ft_datacheck_value(&ptr, flag, data);
	data->value = ptr;
	return (data);
}

char	*ft_process(int *flag)
{
	int		ret;
	char	*ptr;

	ret = get_next_line(STDIN_FILENO, &ptr, 0);
	if (ret == -1)
	{
		*flag = -1;
		return (NULL);
	}
	if (ret == 0 && ft_strlen(ptr) == 0)
	{
		*flag = 1;
		return (NULL);
	}
	return (ptr);
}
