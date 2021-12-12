/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_key_val.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrigaudy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 19:04:31 by vrigaudy          #+#    #+#             */
/*   Updated: 2021/12/12 19:13:55 by vrigaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_key_val(const char *s1, const char *s2)
{
	int	ret;

	ret = 0;
	if (ft_strlen(s1) == ft_strlen(s2))
	{
		if (strncmp(s1, s2, ft_strlen(s1) == 0)
			ret = 1;
	}
	return (ret);
}