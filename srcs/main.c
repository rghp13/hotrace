#include "hotrace.h"

int	main(void)
{
	char	*ptr;
	int		ret;

	ret = get_next_line(2, &ptr, GNL_BUFFER_SIZE);
	printf("%s\n%d\n", ptr, ret);
	free(ptr);
	return (0);
}
