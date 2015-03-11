#include <stddef.h>

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	index;

	index = 0;
	while (src[index] != '\0')
	{
		dst[index] = src[index];
		++index;
	}
	dst[index] = '\0';
	return (dst);
}
