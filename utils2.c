/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:25:08 by rponsonn          #+#    #+#             */
/*   Updated: 2021/12/12 19:27:13 by rponsonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	add_last(t_data *head, t_data *new)
{
	t_data	*ptr;

	if (head->next == NULL)
	{
		if (ft_check_key_val(head->key, new->key))
			free_list(new);
		else
			head->next = new;
		return ;
	}
	ptr = head;
	while (ptr->next != NULL)
	{
		if (ft_check_key_val(ptr->key, new->key))
		{
			free_list(new);
			return ;
		}
		ptr = ptr->next;
	}
	if (ft_check_key_val(ptr->key, new->key))
		free_list(new);
	else
		ptr->next = new;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	val1;
	unsigned char	val2;
	unsigned int	i;
	int				hold;

	i = 0;
	while (i < n)
	{
		val1 = s1[i];
		val2 = s2[i];
		if (val1 != val2)
		{
			hold = val1 - val2;
			return (hold);
		}
		if (val1 == '\0' && val2 == '\0')
			return (0);
		i++;
	}
	return (0);
}

void	ft_putstr(const char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}

void	ft_print_value(const char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(1, "\n", 1);
}
