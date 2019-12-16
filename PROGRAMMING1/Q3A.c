#include <stdio.h>
int gcd(int a, int b);

int main()
{
    printf("%d", gcd(24, 36));

    return 0;
}


int gcd(int a, int b)
{
    int gcd = 1;
    for(int i=2; i <= a && i <= b; i++)
    {
        if(a%i==0 & b%i==0)
        {
            gcd = i;
        }
    }
    return gcd;
}
