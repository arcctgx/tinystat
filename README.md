# tinystat

The purpose of this set of utilities is to allow to quickly calculate some
basic sample statistics from the command line. All programs read data from
the standard input and write results to the standard output, making them
suitable to use in pipelines. Calculations are done on double precision
floating point numbers.

## Examples

Calculate sum:

```bash
awk '{print $3}' mydatafile.txt | ts-sum
```

Calculate average value of the last column in `data.csv`:

```bash
rev data.csv | cut -d, -f1 | rev | ts-avg
```

Calculate the average of sigma-clipped data (using 2 sigma threshold):

```bash
cut -f5 magnitudes.txt | ts-sigclip 2 | ts-avg
```

Create histogram data:

```bash
awk '{print $2}' data.txt | ts-hist
```

And so on...
