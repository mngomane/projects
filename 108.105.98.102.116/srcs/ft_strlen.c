#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	char	*origin;
	char	*string;

	origin = (char *)s;
	string = (char *)s;
	if (string == NULL)
	{
		return (0);
	}
	while (*string != '\0')
	{
		++string;
	}
	return ((size_t)(string - origin));
}
