#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	char	*string;
	char	*origin;

	string = (char *)s;
	origin = (char *)s;
	if (string == NULL)
	{
		return (0);
	}
	while (*string != '\0')
	{
		++string;
	}
	return ((size_t)(string -origin));
}

char		*ft_strdup(const char *s1)
{
	char	*duplicate;
	size_t	length;
	size_t	index;

	index = 0;
	length = ft_strlen(s1);
	duplicate = (char *)malloc(sizeof(char) * (length + 1));
	while (index < length)
	{
		duplicate[index] = s1[index];
		++index;
	}
	duplicate[index] = '\0';
	return (duplicate);
}
