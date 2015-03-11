char	*ft_strchr(const char *s, int c)
{
	char	*first_occurrence;

	first_occurrence = (char *)s;
	while (*first_occurrence != '\0')
	{
		if (*first_occurrence == (char)c)
		{
			return (first_occurrence);
		}
		++first_occurrence;
	}
	if (*first_occurrence == (char)c)
	{
		return (first_occurrence);
	}
	return ((void *)0);
}
