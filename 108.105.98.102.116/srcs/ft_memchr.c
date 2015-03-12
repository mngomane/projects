#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	size_t			index;

	string = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (*string == (unsigned char)c)
			return (string);
		if (*string == '\0')
			return (NULL);
		++string;
		++index;
	}
	return (NULL);
}
