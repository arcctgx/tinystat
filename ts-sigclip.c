#include <stdio.h>
#include <stdlib.h>
#include "tinystat.h"


int main(int argc, char *argv[])
{
    int i, N, left;
    double thresh, *data = NULL;

    if (argc == 1)
        thresh = DEF_SIGMA;
    else
        thresh = atof(argv[1]);

    if ((data = load_data_stdin(&N)) == NULL) {
        fprintf(stderr, "failed to load data, exiting\n");
        return 1;
    }

    left = sigclip(data, N, thresh);

    for (i=0; i < left; i++)
        printf("%f\n", data[i]);

    free(data);

    return 0;
}
