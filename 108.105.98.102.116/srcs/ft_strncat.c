#include <stddef.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	index;
	size_t	source_index;

	index = 0;
	source_index = 0;
	while (s1[index] != '\0')
	{
		++index;
	}
	while (s2[source_index] != '\0' && source_index < n)
	{
		s1[index] = s2[source_index];
		++index;
		++source_index;
	}
	s1[index] = '\0';
	return (s1);
}
