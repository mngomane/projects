#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		index;
	unsigned char	*string;

	index = 0;
	string = b;
	while (index < len)
	{
		string[index] = (unsigned char)c;
		++index;
	}
	b = string;
	return (b);
}
