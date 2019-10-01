#include"ft_printf.h"


int not_valid_exit(const char *str)
{
		g_flag = 0;
		if(str[1] && str[1] == '%')
		{
				write(1, "%", 1);
				return (2);
		}
		return(1);
}

int	get_type(const char *str)
{
	int i;

	i = 1;
	while (str[i] && (isalpha(str[i]) == 0)) // TOD
		i++;
	if (!str[i])
		return (-1);
	if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
		i++;
	 if (str[i] == 'l' || str[i] == 'h')
        i++;
	if (str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd' || str[i] == 'i'
			|| str[i] == 'o' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X' || str[i] == 'f')
		g_param->type = str[i]; //TOD
	else
		return (-1);
	return (i);
}


int get_size(const char *str)
{
	if (g_param->type == 'f')
	{
		if ((str[0] == 'l' || str[0] == 'L') && g_param->type == 'f')
			g_param->size = (str[0] == 'l' ? 2 : 1);
		else 
			return (-1);
	}
	else if (g_param->type == 'd' || g_param->type == 'i' || g_param->type == 'o' || g_param->type == 'u'
			 || g_param->type == 'x' || g_param->type == 'X')
	{
		if (str[0] == 'h' && str[1] == 'h')
			g_param->size = 5;
		else if (str[0] == 'h')
     		g_param->size = 4;
		else if (str[0] == 'l' && str[1] == 'l')
       		g_param->size = 3;
		else if (str[0] == 'l')
			g_param->size = 2;
		else 
			return (-1);
	}
	else
		return (-1);
	return (1);
}

int get_prescision(const char *str)
{
	int i;

	i = 1;
	 while(isdigit(str[i]) == 1)
    {
        g_param->prescision = g_param->prescision * 10 + (str[i] - 48);
        i++;
    }
	if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
        return (get_size(&str[i]));
    if (isalpha(str[i]) == 1)
        return (1);
    return (-1);
}


int get_width(const char *str)
{
	int i;
	
	i = 0;
	printf("in here\n");
	while(isdigit(str[i]) == 1)
	{
		g_param->width = g_param->width * 10 + (str[i] - 48);
		i++; 
	}
	if (str[i] == '.')
		return (get_prescision(&str[i]));
	if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
		return (get_size(&str[i]));
	if (isalpha(str[i]) == 1)
        return (1);
    return (-1);
}

int get_flags(const char *str)
{
	int i;
	
	//printf("in here ");
	i = 0;
	while (str[i] == '#' || str[i] == '+' || str[i] == '-' || str[i] == ' ' || str[i] == '0')
	{	
		if (str[i] == '-')
		{
			if(g_param->minus == 0)
				g_param->minus = 1;
			else
				return (-1);
		}
		if (str[i] == '+')
		{
			if(g_param->plus == 0)
				g_param->plus = 1;
			else
				return (-1);
		}
		if (str[i] == '#')
		{
			if(g_param->oktotorp == 0)
				g_param->oktotorp = 1;
			else
				return (-1);
		}
		if (str[i] == ' ')
		{
			if(g_param->space == 0)
				g_param->space = 1;
			else
				return (-1);
		}
		if (str[i] == '0')
		{
			if(g_param->zero == 0)
				g_param->zero = 1;
			else
				return (-1);
		}
	i++;
	}
	if (isdigit(str[i]) == 1)
		return(get_width(&str[i]));
	if(str[i] == '.')
		return (get_prescision(&str[i]));
	if (str[i] == 'l' || str[i] == 'L' || str[i] == 'h')
		return (get_size(&str[i]));
	if (isalpha(str[i]) == 1)
		return (1);
	return (-1);
}

void correct_flags(void)
{

	if (g_param->space && g_param->plus)
		g_param->space = 0;
	if (g_param->type == 'd' || g_param->type == 'i' || g_param->type == 'u')
	{
		if (g_param->prescision != 0)
			g_param->zero = 0;
	}
	else if (g_param->type == 'o' || g_param->type == 'x' || g_param->type == 'X')
	{
		g_param->plus = 0;
		if (g_param->prescision != 0)
            g_param->zero = 0;
	}
}


int ft_analyze(const char *str)
{
	int i;

	i = get_type(str);
	if (i == -1)
		return(not_valid_exit(str));
	if(i == 1)
		return (i + 1);
	if (get_flags(&str[1]) == -1)
		return(not_valid_exit(str));
//	correct_flags();
	return (i + 1);
}



int main(void)
{
		//printf(" % %dd", 10);
		ft_printf("%%d\n");
		printf("plus	 %d\n", g_param->plus);
		printf("minus	 %d\n", g_param->minus);
  		printf("space	 %d\n", g_param->space);
		printf("oktotorp %d\n", g_param->oktotorp);
		printf("zero	 %d\n\n", g_param->zero );
  		printf("width		%d\n", g_param->width);
  		printf("prescision  %d\n", g_param->prescision);
		printf("size		%d\n", g_param->size);
		printf("type		%c\n", g_param->type);

}
