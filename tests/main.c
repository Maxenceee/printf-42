#include "../bonus/includes/ft_printf_bonus.h"
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main(void)
{
	// printf("len: %d\n", printf("%.30f\n", 4242.28730494752873049475));
	// printf("len: %d\n", ft_printf("%.30f\n", 4242.28730494752873049475));
	// printf("\n");
	// printf("len: %d\n", printf("%f\n", 4242.28));
	// printf("len: %d\n", ft_printf("%f\n", 4242.28));
	// printf("\n");
	
	// printf("len: %d\n", printf("%f\n", 4242.2842));
	// printf("len: %d\n", ft_printf("%f\n", 4242.2842));
	// printf("\n");
	// printf("len: %d\n", printf("%f\n", 4242.284201));
	// printf("len: %d\n", ft_printf("%f\n", 4242.284201));
	// printf("\n");

	// printf("len: %d\n", printf("%f\n", 4242.101));
	// printf("len: %d\n", ft_printf("%f\n", 4242.101));
	// printf("\n");

	// printf("len: %d\n", printf("%f\n", 4242.01));
	// printf("len: %d\n", ft_printf("%f\n", 4242.01));
	// printf("\n");
	// printf("len: %d\n", printf("%f\n", 4242.001));
	// printf("len: %d\n", ft_printf("%f\n", 4242.001));
	// printf("\n");

	// printf("len: %d\n", printf("%f\n", 4242.000000001));
	// printf("len: %d\n", ft_printf("%f\n", 4242.000000001));
	// printf("\n");

	// printf("len: %d\n", printf("%-x\n", 4242));
	// printf("len: %d\n", ft_printf("%-x\n", 4242));
	// printf("\n");
	// printf("len: %d\n", printf("%010x\n", 4242));
	// printf("len: %d\n", ft_printf("%010x\n", 4242));
	// printf("\n");
	// printf("len: %d\n", printf("%-10x\n", 4242));
	// printf("len: %d\n", ft_printf("%-10x\n", 4242));
	// printf("\n");
	// printf("len: %d\n", printf("%10d\n", 42));
	// printf("len: %d\n", ft_printf("%10d\n", 42));
	// printf("\n");

	// printf("len: %d\n", printf("%.4s\n", "hello"));
	// printf("len: %d\n", ft_printf("%.4s\n", "hello"));
	// printf("\n");
	// printf("len: %d\n", printf("%.4s\n", (char *)NULL));
	// printf("len: %d\n", ft_printf("%.4s\n", (char *)NULL));
	// printf("\n");
	
	// printf("len: %d\n", printf("%#.10X\n", 0));
	// printf("len: %d\n", ft_printf("%#.10X\n", 0));
	// printf("\n");
	// printf("len: %d\n", printf("%#.10X\n", 42));
	// printf("len: %d\n", ft_printf("%#.10X\n", 42));
	// printf("\n");

	printf("%+5d, %+5d, %+5d, %+5d, %+5d, %+5d, %+5d, %+5d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	ft_printf("%+5d, %+5d, %+5d, %+5d, %+5d, %+5d, %+5d, %+5d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);

	// printf("len: %d\n", printf("%*x\n", 5, 42));
	// printf("len: %d\n", ft_printf("%*x\n", 5, 42));
	// printf("\n");
	// printf("len: %d\n", printf("%.*s\n", 4, "hello"));
	// printf("len: %d\n", ft_printf("%.*s\n", 4, "hello"));
	// printf("\n");

	// printf("%7.5s\n", "yolo");
	// ft_printf("%7.5s\n", "yolo");
	// printf("\n");
	// printf("%.5s\n", "yolo");
	// ft_printf("%.5s\n", "yolo");
	// printf("\n");
	// printf("%7s\n", "yolo");
	// ft_printf("%7s\n", "yolo");
	// printf("\n");
	// printf("%7.5s\n", "bombastic");
	// ft_printf("%7.5s\n", "bombastic");
	// printf("\n");
	// printf("%.5s\n", "bombastic");
	// ft_printf("%.5s\n", "bombastic");
	// printf("\n");
	// printf("%7s\n", "bombastic");
	// ft_printf("%7s\n", "bombastic");
	// printf("\n");
	// printf("%-7.5s\n", "tubular");
	// ft_printf("%-7.5s\n", "tubular");
	// printf("\n");

	// printf("% u\n", -1);
	// ft_printf("% u\n", -1);
	// printf("\n");

	// printf(" %u \n", 0);
	// ft_printf(" %u \n", 0);
	// printf("\n");

	// printf(" %u \n", LONG_MIN);
	// ft_printf(" %u \n", LONG_MIN);
	// printf("\n");

	// printf(" %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// ft_printf(" %u %u %u %u %u %u %u\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf("\n");

	// printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42,  42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42,  42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	// printf("\n");

	// printf(" %-2u \n", -1);
	// ft_printf(" %-2u \n", -1);
	// printf("\n");

	// printf(" %-13u \n", UINT_MAX);
	// ft_printf(" %-13u \n", UINT_MAX);
	// printf("\n");

	// printf(" %-1x \n", 0);
	// ft_printf(" %-1x \n", 0);
	// printf("\n");

	// printf(" %02u \n", -1);
	// ft_printf(" %02u \n", -1);
	// printf("\n");

	// printf(" %013u \n", UINT_MAX);
	// ft_printf(" %013u \n", UINT_MAX);
	// printf("\n");

	// printf(" %01x \n", 0);
	// ft_printf(" %01x \n", 0);
	// printf("\n");

	// printf(" %.1u \n", 0);
	// ft_printf(" %.1u \n", 0);
	// printf("\n");
	// printf("len: %d\n", printf("%.03s\n", NULL));
	// printf("len: %d\n", ft_printf("%.03s\n", NULL));
	// printf("\n");
	// printf("len: %d\n", printf("%3.1s\n", NULL));
	// printf("len: %d\n", ft_printf("%3.1s\n", NULL));
	// printf("\n");
	// printf("len: %d\n", printf("%9.1s\n", NULL));
	// printf("len: %d\n", ft_printf("%9.1s\n", NULL));
	// printf("\n");
	// printf("%-3.1s\n", NULL);
	// ft_printf("%-3.1s\n", NULL);
	// printf("\n");
	// printf("%-9.1s\n", NULL);
	// ft_printf("%-9.1s\n", NULL);
	// printf("\n");
	// printf("p3 %.4s\n", NULL);
	// ft_printf("p3 %.4s\n", NULL);
	// printf("\n");
	// printf("%15p\n", NULL);
	// ft_printf("%15p\n", NULL);
	// printf("\n");
	// printf("%-15p\n", NULL);
	// ft_printf("%-15p\n", NULL);
	// printf("\n");
	// printf("%50.2s\n", NULL);
	// ft_printf("%50.2s\n", NULL);
	// printf("\n");

	// printf("%3.6s\n", NULL);
	// ft_printf("%3.6s\n", NULL);
	// printf("\n");
	// printf("%20.6s\n", NULL);
	// ft_printf("%20.6s\n", NULL);
	// printf("\n");

	// printf(" %2p \n", -1);
	// ft_printf(" %2p \n", -1);
	// printf("\n");
	// printf(" %-2p \n", -1);
	// ft_printf(" %-2p \n", -1);
	// printf("\n");
	// printf(" %-2p \n", 1);
	// ft_printf(" %-2p \n", 1);
	// printf("\n");
	// printf(" %-2p \n", 15);
	// ft_printf(" %-2p \n", 15);
	// printf("\n");
	// printf(" %-3p \n", 16);
	// ft_printf(" %-3p \n", 16);
	// printf("\n");
	// printf("len: %d\n", printf(" %-4p \n", 17));
	// printf("len: %d\n", ft_printf(" %-4p \n", 17));
	// printf("\n");
	// printf(" %-9p %-10p \n", LONG_MIN, LONG_MAX);
	// ft_printf(" %-9p %-10p \n", LONG_MIN, LONG_MAX);
	// printf("\n");
	// printf(" %-11p %-12p \n", INT_MIN, INT_MAX);
	// ft_printf(" %-11p %-12p \n", INT_MIN, INT_MAX);
	// printf("\n");
	// printf(" %-13p %-14p \n", ULONG_MAX, -ULONG_MAX);
	// ft_printf(" %-13p %-14p \n", ULONG_MAX, -ULONG_MAX);
	// printf("\n");
	// printf(" %-1p %-2p \n", 0, 0);
	// ft_printf(" %-1p %-2p \n", 0, 0);
	// printf("\n");

	// printf("%5%\n");
	// ft_printf("%5%\n");
	// printf("%-5%\n");
	// ft_printf("%-5%\n");
	// printf("%-05%\n");
	// ft_printf("%-05%\n");
	// printf("percent 2 %12%\n");
	// ft_printf("percent 2 %12%\n");
	// printf("percent 3 %-12%\n");
	// ft_printf("percent 3 %-12%\n");

	// printf("%p\n", NULL);
	// ft_printf("%p\n", NULL);
	// printf("%p\n", NULL);
	// ft_printf("%p\n", NULL);
	// printf("%p\n", NULL);
	// ft_printf("%p\n", NULL);
	// printf("%15p\n", NULL);
	// ft_printf("%15p\n", NULL);
	// printf("%-15p\n", NULL);
	// ft_printf("%-15p\n", NULL);

	return (0);
}