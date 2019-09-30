#include"ft_printf.h"

void param_setzero(void)
{
	g_param->minus = 0;
	g_param->plus = 0;
	g_param->space = 0;
	g_param->zero = 0;
	g_param->oktotorp = 0;
	g_param->type = 0;
}



int ft_analyze(const char *str)
{
	int i;

	i = 0;

	return (1);	
}

void ft_printf(const char *str, ...)
{
	int i;
	
	i = 0;
	g_param = (t_param*)malloc(sizeof(t_param));
	param_setzero();
	while (str[i])
	{
		if (str[i] == '%')
		{
			i+=ft_analyze(&str[i]);
			//print_param();
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}

}

