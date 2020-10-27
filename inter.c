#include <stdio.h>
#include <unistd.h>
void ft_putchar(char c)
{
    write(1,&c,1);
}
int ft_check(char c, char* string, int i)
{
    while (i >= 0)
    {
       if(string[i] == c)
           return 1;    
      i--;
    }
  return 0;
}
int main(int argc, char **argv)
{
    int i;
    int j;
    i = 0;
    j = 0;
    if(argc == 3)
    {
        while (argv[1][i])
        {
            while (argv[2][j])
            {
                if(argv[1][i] == argv[2][j])
                {
                    if(ft_check(argv[2][j],argv[1], i-1) == 0)
                    {
                          ft_putchar(argv[1][i]);
                          break;
                    }                        
                }
                j++;
            }
            j = 0;
            i++;
        }
         ft_putchar('\n');
    }else
          ft_putchar('\n');
}