




#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include<stdio.h> // убрать
#include<unistd.h>
#include<stdlib.h>
#include <stdarg.h>

void ft_printf(const char *str, ...);


typedef struct	s_param
{
	int	minus; // выводимое значение выравнивается по левому краю в пределах минимальной ширины поля(по правому)	
	int plus; // всегда указывать знак (плюс или минус) для выводимого десятичного числового значения (только для отрицательных чисел)
	int	space; // помещать перед результатом пробел, если первый символ значения не знак (Вывод может начинаться с цифры.)
	int	zero;		// https://ru.wikipedia.org/wiki/Printf
	int	oktotorp;
	char	*type;  // тип переменной
}		t_param;



t_param *g_param;

#endif
