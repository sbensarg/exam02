#include <stdio.h>

int ft_printf(const char *fmt, ...);

int main()
{
    printf("[%10.5s]\n", "sara");
    ft_printf("[%10.5s]", "sara");
}