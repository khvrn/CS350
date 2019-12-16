/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <math.h>

int celsius(int fahrenheit);
int fahrenheit(int celsius);
void printFahrenheit();
void printCelsius();

int main()
{
    printFahrenheit();
    printCelsius();
}


//converts fahrenheit to celsius
int celsius(int f)
{
    return ((f-32)*((float)5/9));
}

//converts celsius to fahrenheit
int fahrenheit(int c)
{
    return (c*((float)9/5))+32;
}


void printFahrenheit()
{
    printf("Fahrenheit -> Celsius\n");
    for(int i=0; i <=100; i++)
    {
        int cels = celsius(i);
        printf("%3d %3d\n", i, cels);
    }
}


void printCelsius()
{
    printf("Celsius -> Fahrenheit\n");
    for(int i=32; i <=212; i++)
    {
        int fahr = fahrenheit(i);
        printf("%3d %3d\n", i, fahr);
    }
}
