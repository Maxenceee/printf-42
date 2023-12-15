#include "../bonus/includes/ft_printf_bonus.h"
#include <stdio.h>

int main(void)
{
	printf("len %d\n", printf("%.30f\n", 4242.28730494752873049475));
	printf("len %d\n", ft_printf("%.30f\n", 4242.28730494752873049475));
	printf("len %d\n", printf("%f\n", 4242.28));
	printf("len %d\n", ft_printf("%f\n", 4242.28));
	
	printf("len %d\n", printf("%f\n", 4242.2842));
	printf("len %d\n", ft_printf("%f\n", 4242.2842));
	printf("len %d\n", printf("%f\n", 4242.284201));
	printf("len %d\n", ft_printf("%f\n", 4242.284201));

	printf("len %d\n", printf("%f\n", 4242.101));
	printf("len %d\n", ft_printf("%f\n", 4242.101));

	printf("len %d\n", printf("%f\n", 4242.01));
	printf("len %d\n", ft_printf("%f\n", 4242.01));
	printf("len %d\n", printf("%f\n", 4242.001));
	printf("len %d\n", ft_printf("%f\n", 4242.001));

	printf("len %d\n", printf("%f\n", 4242.000000001));
	printf("len %d\n", ft_printf("%f\n", 4242.000000001));

	printf("len %d\n", printf("%-x\n", 4242));
	printf("len %d\n", ft_printf("%-x\n", 4242));
	printf("len %d\n", printf("%010x\n", 4242));
	printf("len %d\n", ft_printf("%010x\n", 4242));
	printf("len %d\n", printf("%-10x\n", 4242));
	printf("len %d\n", ft_printf("%-10x\n", 4242));
	printf("len %d\n", printf("%10d\n", 42));
	printf("len %d\n", ft_printf("%10d\n", 42));

	printf("len %d\n", printf("%.4s\n", "hello"));
	printf("len %d\n", ft_printf("%.4s\n", "hello"));
	printf("len %d\n", printf("%.4s\n", NULL));
	printf("len %d\n", ft_printf("%.4s\n", NULL));

	printf("len %d\n", printf("%.10p\n", NULL));
	printf("len %d\n", ft_printf("%.10p\n", NULL));
	
	printf("len %d\n", printf("%#.10X\n", NULL));
	printf("len %d\n", ft_printf("%#.10X\n", NULL));
	printf("len %d\n", printf("%#.10X\n", 42));
	printf("len %d\n", ft_printf("%#.10X\n", 42));

	printf("len %d\n", printf("%*x\n", 5, 42));
	printf("len %d\n", ft_printf("%*x\n", 5, 42));
	printf("len %d\n", printf("%.*s\n", 4, "hello"));
	printf("len %d\n", ft_printf("%.*s\n", 4, "hello"));
	return (0);
}