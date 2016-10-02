#include <stdio.h>
#include <stdlib.h>
#include "tinystat.h"

int main(int argc, char *argv[])
{
    int i, j, N, nbins, binpop[MAXBINS], sumpop;
    double min, max, range, binw, *data = NULL;
    double midbin[MAXBINS], binsta, binend;

    if ((data = load_data_stdin(&N)) == NULL) {
        fprintf(stderr, "failed to load data, exiting\n");
        return 1;
    }

    if (argc == 1)
        nbins = DEF_NBINS;
    else if ((nbins = atoi(argv[1])) <= 1)
        nbins = DEF_NBINS;
    else if ((nbins = atoi(argv[1])) > MAXBINS)
        nbins = MAXBINS;

    minmax(data, N, &min, &max);
    range = max - min;
    binw = range/nbins;

    printf("# %d data, %d classes, min = %f, max = %f, range = %f, binw = %f\n", N, nbins, min, max, range, binw);

    for (i=0; i < nbins; i++) {
        binpop[i] = 0;
        midbin[i] = min + binw/2.0 + i*binw;
        binsta = midbin[i] - binw/2.0;
        binend = midbin[i] + binw/2.0;

        for (j=0; j < N; j++)
            if (data[j] > binsta && data[j] <= binend) ++(binpop[i]);
    }

    /* get missing elements */
    for (j=0; j < N; j++) {
        if (data[j] <= min)
            ++(binpop[0]);
        else if (data[j] > binend)
            ++(binpop[nbins-1]);
    }

    sumpop = 0;
    for (i=0; i < nbins; i++) {
        printf("%12f %7d\n", midbin[i], binpop[i]);
        sumpop += binpop[i];
    }

    if (sumpop == N)
        printf("# %d = %d\n", sumpop, N);
    else
        printf("# %d != %d\n", sumpop, N);

    free(data);

    return 0;
}
