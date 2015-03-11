#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;

	string = (unsigned char *)s;
	while (n > 0)
	{
		if (*string == (unsigned char)c)
		{
			return (string);
		}
		if (*string == '\0')
		{
			return (NULL);
		}
		++string;
		--n;
	}
	return (NULL);
}
