int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*string1;
	unsigned char	*string2;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	while (*string1 != '\0' && *string2 != '\0')
	{
		if (*string1 != *string2)
		{
			return ((int)(*string1 - *string2));
		}
		++string1;
		++string2;
	}
	return ((int)(*string1 - *string2));
}
