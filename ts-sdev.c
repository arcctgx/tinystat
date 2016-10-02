#include <stdio.h>
#include <stdlib.h>
#include "tinystat.h"

int main(int argc, char *argv[])
{
    int N;
    double *data = NULL;

    if ((data = load_data_stdin(&N)) == NULL) {
        fprintf(stderr, "failed to load data, exiting\n");
        return 1;
    }

    if (argc == 1)
        printf("%f\n", sdev(data, N));     /* unbiased estimator */
    else
        printf("%f\n", sdev_b(data, N));   /* biased estimator */

    free(data);

    return 0;
}
