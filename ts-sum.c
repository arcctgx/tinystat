#include <stdio.h>

int main(void)
{
    double x, sum = 0.0;

    while (fscanf(stdin, "%lf", &x) != EOF)
        sum += x;

    printf("%f\n", sum);

    return 0;
}
