#include <ft_printf.h>
int	ft_is_conv(char *str)
{
	char	*conv;
	conv = "sSpdDioOuUxXcC%";

	while(*conv)
	{
		if (*str == *conv)
			return (1);
		conv++;
	}
	return (0);
}

int		ft_is_valid(char c)
{
	char *conv;

	conv = "sdDiouUxXcp%";
	while(*conv)
	{
		if (c == *conv)
			return (1);
		conv++;
	}
	return (0);
}

int	ft_is_slmod(const char *str)
{
	char	*slmod[3];
	int 	i;

	slmod[0] = "hh";
	slmod[1] = "ll";
	slmod[2] = "\0";
	i = 0;
	while(i < 3)
	{
		if (ft_strncmp(slmod[i], str, 2) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_lmod(const char ch, t_format **p)
{
	char		lmod[5];
	t_format	*params;
	int 		i;

	params = *p;
	lmod[0] = 'h';
	lmod[1] = 'l';
	lmod[2] = 'j';
	lmod[3] = 'z';
	lmod[4] = '\0';
	i = -1;
	while(++i < 5)
	{
		if (ch == lmod[i])
		{
			if (params->lmod == '\0')
				params->lmod = ch;
			else if (ch == 'l' && params->lmod == 'h')
				params->lmod = ch;
			else if (ch == 'z' && (params->lmod == 'l' || params->lmod == 'h'))
				params->lmod = ch;
			else if (ch == 'j' && (params->lmod == 'z' || params->lmod == 'l' || params->lmod == 'h'))
				params->lmod = ch;
			return (1);
		}
	}
	return (0);
}

int		ft_is_dioux(char c)
{
	char	*conv;
	conv = "dioux";

	while(*conv)
	{
		if (c == *conv)
			return (1);
		conv++;
	}
	return (0);
}

int		ft_is_diox(char c)
{
    char	*conv;
    conv = "diox";

    while(*conv)
    {
        if (c == *conv)
            return (1);
        conv++;
    }
    return (0);
}

int		ft_is_di(char c)
{
	char	*conv;
	conv = "di";

	while(*conv)
	{
		if (c == *conv)
			return (1);
		conv++;
	}
	return (0);
}