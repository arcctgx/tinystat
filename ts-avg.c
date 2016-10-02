#include <stdio.h>

int main(void)
{
    int ndata = 0;
    double x, sum = 0.0;

    while (fscanf(stdin, "%lf", &x) != EOF) {
        ++ndata;
        sum += x;
    }

    printf("%f\n", sum/ndata);

    return 0;
}
