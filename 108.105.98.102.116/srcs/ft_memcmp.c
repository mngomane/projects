#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*string1;
	char	*string2;
	size_t	index;

	index = 0;
	string1 = (char *)s1;
	string2 = (char *)s2;
	while (index < n)
	{
		if (string1[index] != string2[index])
		{
			return (string1[index] - string2[index]);
		}
		++index;
	}
	return (0);
}
