#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*destination;
	char	*source;
	size_t	index;

	index = 0;
	source = (char *)src;
	destination = dst;
	while (index < n)
	{
		destination[index] = source[index];
		++index;
	}
	dst = destination;
	return (dst);
}
