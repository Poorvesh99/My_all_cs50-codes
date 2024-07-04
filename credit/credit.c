#include <cs50.h>
#include <stdio.h>

int main(void)
{
 int n = 42673 % 100;
 n /= 10;
 printf("%i\n",n);
}