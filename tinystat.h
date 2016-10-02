#ifndef TINYSTAT_H
#define TINYSTAT_H

#define SIZE (1024)
#define DEF_SIGMA (3.0)
#define DEF_NBINS (10)
#define MAXBINS (128)


double *load_data_stdin(int *N);

void minmax(double *data, int N, double *min, double *max);

double avg(double *data, int N);

double sdev_b(double *data, int N);     /* division by N (biased estimator) */

double sdev(double *data, int N);       /* division by N-1 (unbiased estimator) */

void reject(double *data, int N, int idx);

int sigclip(double *data, int N, double thresh);

#endif
