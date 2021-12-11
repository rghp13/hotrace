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
	write(1, str, ft_strlen(str));
}

void	ft_print_value(const char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
