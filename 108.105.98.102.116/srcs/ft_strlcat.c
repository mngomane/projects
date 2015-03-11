#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	source_index;

	index = 0;
	source_index = 0;
	while (dst[index] != '\0')
	{
		++index;
	}
	while (src[source_index] != '\0' && source_index < size)
	{
		dst[index] = src[source_index];
		++index;
		++source_index;
	}
	dst[index] = '\0';
	return (index + source_index);
}
