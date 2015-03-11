#include <stddef.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	index;

	index = 0;
	while (src[index] != '\0' && index < n)
	{
		dst[index] = src[index];
		++index;
	}
	while (index < n)
	{
		dst[index] = '\0';
	}
	return (dst);
}
