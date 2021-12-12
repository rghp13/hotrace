/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 12:37:07 by rponsonn          #+#    #+#             */
/*   Updated: 2021/12/12 22:39:40 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static char	*ft_realloc(char *line, int *i)
{
	int		l;
	char	*str;

	l = 0;
	str = malloc(*i * 2);
	if (str == NULL)
		return (NULL);
	*i *= 2;
	while (line && line[l])
	{
		str[l] = line[l];
		l++;
	}
	while (l < *i)
	{
		str[l] = 0;
		l++;
	}
	free(line);
	return (str);
}

static int	subgnl(char **line, int *malloc_size)
{
	int	r;
	int	i;

	i = -1;
	r = 0;
	while (1)
	{
		r = read(0, &(*line)[++i], 1);
		if (r < 1)
			break ;
		if ((*line)[i] == 10)
			break ;
		if (i == *malloc_size - 2)
		{
			*line = ft_realloc(*line, malloc_size);
			if (*line == NULL)
				return (-1);
		}
	}
	(*line)[i] = 0;
	return (r);
}

int	get_next_line(char **line)
{
	int	r;
	int	malloc_size;

	r = 0;
	malloc_size = 50;
	if (!line)
		return (-1);
	*line = NULL;
	*line = ft_realloc(*line, &malloc_size);
	if (*line == NULL)
		return (-1);
	r = subgnl(line, &malloc_size);
	return (r);
}
