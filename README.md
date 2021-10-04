Tester code for Bangle JS algorithms
====================================

# Prerequisites

- C compiler
- [Cmake](https://cmake.org/)

# Compile and run

```
cd build
cmake ../
cmake --build .
./banglejs-algos-tester
```

The executable assumes that data files are in `../data/`. It outputs a comma-separated table like the following:

```
steps-controlled, dummy, 100_5.csv, 100, 100
steps-controlled, oxford, 100_5.csv, 1790, 100
steps-uncontrolled, dummy, 3058.csv, 100, 3058
steps-uncontrolled, oxford, 3058.csv, 3301, 3058
```

the first column is the type of data, the second is the name of the algorithm, the third is the name of the file, the fourth is the step count detected by the algorithm and the last column is the reference.

You can easily import this table into Excel to do run your statistics for example by calling `./banglejs-algos-tester > algos.csv`.


# Datasets

There are 2 datasets for step counting:
- controlled: usually short and taken with a reliable reference like manual counting
- uncotnrolled: usually longer and with a less reliable reference, like another step counter

each file name must start with the reference step counter value. For example 125_test.csv means that the reference step value count is 125.

To test new datasets just drop a file with the correct name and format in one of the two folders.

# Algorithms

There are currently 2 algorithms: dummy, which always returns 100, and oxford-step-count, which is based on [this](https://oxford-step-counter.github.io/).

To add a new algorithm:

1. place the source code inside the stepcounters folder, possibly in a subfolder
2. modify stepcounters.c to add calls to the new algorithm
3. recompile and run