int	ft_tolower(int c)
{
	if ((unsigned char)c >= 'A' && (unsigned char)c <= 'Z')
	{
		return (c - ('M' - 'm'));
	}
	return (c);
}
