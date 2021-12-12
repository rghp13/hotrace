/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:26:27 by rponsonn          #+#    #+#             */
/*   Updated: 2021/12/12 19:26:29 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	hash(const char *str)
{
	int	i;
	int	char_position;
	int	value;

	value = 0;
	i = 0;
	char_position = 1;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		value += (str[i] * 10) + char_position;
		i++;
		char_position++;
	}
	return (value % TABLESIZE);
}
