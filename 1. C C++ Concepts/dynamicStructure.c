#include <stdio.h>
#include <stdlib.h>

typedef struct Complex
{
    int real;
    int imaginary;
} Complex;

void initialize(Complex *p)
{
    printf("Enter real and imaginary values : ");
    scanf("%d %d", &(p->real), &(p->imaginary));
}

void display(Complex *p)
{
    printf("Real Part : %d, Imaginary Part : %d", p->real, p->imaginary);
}

int main(int rgc, char *argv[])
{
    Complex *p;
    p = (Complex *)malloc(1 * (sizeof(Complex)));
    initialize(p);
    display(p);
}