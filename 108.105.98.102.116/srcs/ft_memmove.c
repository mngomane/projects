#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*destination;
	char	*source;
	size_t	index;

	index = 0;
	source = (char *)src;
	destination = dst;
	while (index < len)
	{
		destination[index] = source[index];
		++index;
	}
	dst = destination;
	return (dst);
}
