#include <stdio.h>

int ft_printf(const char *fmt, ...);

int main()
{
    printf("[%3.10d]\n", 3);
    // printf("%d\n", 0);
	// printf("%d\n", 42);
	// printf("%d\n", 1);
	// printf("%d\n", 5454);
	// printf("%d\n", (int)2147483647);
	// printf("%d\n", (int)2147483648);
	// printf("%d\n", (int)-2147483648);
	// printf("%d\n", (int)-2147483649);

   ft_printf("[%3.10d]\n", 3);
    // ft_printf("%d\n", 0);
	// ft_printf("%d\n", 42);
	// ft_printf("%d\n", 1);
	// ft_printf("%d\n", 5454);
	// ft_printf("%d\n", (int)2147483647);
	// ft_printf("%d\n", (int)2147483648);
	// ft_printf("%d\n", (int)-2147483648);
	// ft_printf("%d\n", (int)-2147483649);
}