#include <stddef.h>

char	*ft_strstr(const char *s1, const char *s2)
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
		index = (*occurrence == s2[index] ? index + 1 : 0);
		++occurrence;
	}
	if (s2[index] == '\0')
	{
		return (occurrence - index);
	}
	return (NULL);
}
