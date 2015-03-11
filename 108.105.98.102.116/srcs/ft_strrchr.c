char	*ft_strrchr(const char *s, int c)
{
	char	*last_occurrence;

	last_occurrence = (char *)s;
	while (*last_occurrence != '\0')
	{
		++last_occurrence;
	}
	while ((last_occurrence - s) >= 0)
	{
		if (*last_occurrence == (char)c)
		{
			return (last_occurrence);
		}
		--last_occurrence;
	}
	return ((void *)0);
}
