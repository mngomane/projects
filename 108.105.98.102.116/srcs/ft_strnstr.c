#include <stddef.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*occurrence;
	size_t	index;

	occurrence = (char *)s1;
	index = 0;
	if (*s2 == '\0')
	{
		return ((char *)s1);
	}
	while (*occurrence != '\0' && s2[index] != '\0')
	{
		if ((size_t)(occurrence - s1) >= n)
		{
			return (NULL);
		}
		index = (*occurrence == s2[index] ? index + 1 : 0);
		++occurrence;
	}
	if (s2[index] == '\0')
	{
		return (occurrence - index);
	}
	return (NULL);
}
