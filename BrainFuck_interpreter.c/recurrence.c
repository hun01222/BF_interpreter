#include <stdio.h>

int fac(int a)
{
    if (a == 1)
        return a;
    else if (a < 1)
    {
        printf("You entered wrong value.\n");
        return 0;
    }
    else
        return a * fac(a - 1);
}

int main(void)
{
    int n;
    printf("Enter the integer value.: ");
    scanf("%d", &n);
    printf("%d! is %d.", n, fac(n));
}
