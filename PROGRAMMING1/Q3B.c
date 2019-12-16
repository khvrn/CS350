#include <stdio.h>
int gcd(int a, int b);

int main()
{
    printf("%d", gcd(24, 36));

    return 0;
}


int gcd(int a, int b)
{
    if(a==0)
    {
        return a;
    } else if(b==0) {
        return b;
    } else if (a==b) {
        return a;
    }
    
    if(a>b)
    {
        return gcd(a-b, b);
    }
    return gcd(a, b-a);
}
