# tinystat
This is a set of command line utilities for calculating basic statistics.

The purpose of this set of utilities is to allow to quickly calculate some basic statistics from command line. Some examples:

* calculate sum:
```bash
awk '{print $3}' mydatafile.txt | ts-sum
```

* calculate average value:
```bash
awk '{print $2}' otherdata.txt | ts-avg
```

* calculate the average of sigma-clipped data (using 2 sigma threshold):
```bash
awk '{print $5}' magnitudes.txt | ts-sigclip 2 | ts-avg
```

* create histogram data:
```bash
awk '{print $2}' data.txt | ts-hist
```

And so on...
