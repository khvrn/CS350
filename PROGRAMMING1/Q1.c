#include <stdio.h>
#include <math.h>
#define N 500

int sqrSum(int a, int b);

int main()
{
    int sum, cSum = 0;
    int numTrip = 0;
    
    printf("Pythagorean Triples:\n");
    
    for(int a=1; a<N; a++) //starts at one
    {
        for(int b=a+1; b <N; b++) //starts one greater than a to prevent duplicates
        {
            sum = sqrSum(a, b);
            
            for(int c=b; c <= sum; c++) // starts at b and ends at the sum of the squares to prevent unnneccesary computation
            {
                cSum = pow((double)c, 2);
                if(sum==cSum)
                {
                    numTrip++; //keeps track of the # of Pythagorean triples
                    printf("%d: %d %d %d\n", numTrip, a, b, c);
                }
            }
        }
    }
    return 0;
}

int sqrSum(int a, int b)
{
    double sqA = (pow((double)a, 2));
    double sqB = (pow((double)b, 2));
    int sum = sqA + sqB;
    return sum;
}