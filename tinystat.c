#include <stdio.h>
#include <stdlib.h>
#include <string.h>     /* memset() */
#include <math.h>
#include "tinystat.h"

double *load_data_stdin(int *N)
{
    int max = 0;
    double x, *data = NULL;

    *N = 0;
    while (fscanf(stdin, "%lf", &x) != EOF) {
        ++(*N);
        if (*N > max) {
            max += SIZE;
            if ((data = realloc(data, max*sizeof(double))) == NULL) {
                fprintf(stderr, "failed to allocate memory, exiting\n");
                free(data);
                return NULL;
            }
        }
        data[*N-1] = x;
    }

    return data;
}

void minmax(double *data, int N, double *min, double *max)
{
    int i;

    *min = *max = data[0];

    for (i=0; i < N; i++) {
        if (data[i] < *min) *min = data[i];
        if (data[i] > *max) *max = data[i];
    }

    return;
}

double avg(double *data, int N)
{
    int i;
    double sum = 0.0;

    for (i=0; i < N; i++)
        sum += data[i];

    return sum/N;
}

double sdev_b(double *data, int N)
{
    int i;
    double mean, sum, sdev;

    sum = 0.0;
    mean = avg(data, N);

    for (i=0; i < N; i++)
        sum += (data[i]-mean)*(data[i]-mean);

    sdev = sqrt(sum/N);

    return sdev;
}

double sdev(double *data, int N)
{
    int i;
    double mean, sum, sdev;

    sum = 0.0;
    mean = avg(data, N);

    for (i=0; i < N; i++)
        sum += (data[i]-mean)*(data[i]-mean);

    sdev = sqrt(sum/(N-1));

    return sdev;
}

void reject(double *data, int N, int idx)
{
    int i;

    for (i=idx; i < N-1; i++)
        data[i] = data[i+1];

    memset(data+N-1, 0, sizeof(double));

    return;
}

int sigclip(double *data, int N, double thresh)
{
    int i, rej, left;
    double mean, sd;

    left = N;

    do {
        rej = 0;
        mean = avg(data, left);
        sd = sdev(data, left);

        for (i=0; i < left; i++) {
            if ((data[i] < mean-thresh*sd) || (data[i] > mean+thresh*sd)) {
                reject(data, left, i);
                ++rej;
                --left;
            }
        }
    } while (rej > 0);

    return left;
}

int sigclip2(double *data, int N, double thresh)
{
    int i, rej, left;
    int *mask;
    double mean, sd;

    if ((mask=malloc(N*sizeof(int))) == NULL) {
        return -1;
    }

    for (i=0; i < N; i++) {
        mask[i] = 1;
    }

    left = N;

    do {
        rej = 0;
        mean = avg(data, left);
        sd = sdev(data, left);

        for (i=0; i < left; i++) {
            if ((data[i] < mean-thresh*sd) || (data[i] > mean+thresh*sd)) {
                reject(data, left, i);
                ++rej;
                --left;
            }
        }
    } while (rej > 0);

    free(mask);
    return left;
}
