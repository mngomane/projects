#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while (*string1 != '\0' && *string2 != '\0')
	{
		if (*string1 != *string2 ||
			(size_t)(string1 - (unsigned char *)s1) >= n ||
			(size_t)(string2 - (unsigned char *)s2) >= n)
		{
			return ((int)(*string1 - *string2));
		}
		++string1;
		++string2;
	}
	return ((int)(*string1 - *string2));
}
