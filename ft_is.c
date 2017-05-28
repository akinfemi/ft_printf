
int	ft_is_conv(char *str)
{
	char	*conv = "sSpdDioOuUxXcC";

	while(*conv)
	{
		if (*str == *conv)
			return (1);
		conv++;
	}
	return (0);
}
