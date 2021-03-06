# Experimental Results for Splay Tree Variants

This repository contains the code to run the experiments laid out in the paper [Splay Tree Variants: Theory and Experiment](Splay%20Tree%20Variants.pdf);

## Results:
### Deterministic Algorithms:
Trees (Num Rotations, Num Pointers Traversed, Total)|  BST |  Splay |  Even |  1-Rot |  3-Rot |  4-Rot 
--- | --- | --- | --- | --- | --- | --- 
Uniform | 0, 2.58e7, 2.58e7 | 2.59e7, 2.59e7, 8.54e7 | 2.53e7, 2.58e7, 8.40e7 | 2.48e7, 2.48e7, 8.19e7 | 2.69e7, 2.69e7, 8.86e7 | 2.75e7, 2.75e7, 0.91e8
Zipf | 0, 1.14e7, 1.14e7 | 1.37e7, 1.37e7, 4.51e7 | 1.39e7, 1.43e7, 4.62e7 | 1.31e7, 1.31e7, 4.31e7 | 1.43e7, 1.43e7, 4.70e7 | 1.47e7, 1.47e7, 4.86e7
Stack | TLE, TLE, TLE | 1.00e6, 1.00e6, 3.30e6 | 1.00e6, 1.50e6, 3.80e6 | 1.00e6, 1.00e6, 3.30e6 | 1.00e6, 1.00e6, 3.30e6 | 1.00e6, 1.00e6, 3.30e6
Line | TLE, TLE, TLE | 4.41e6, 4.41e6, 1.46e7 | 3.97e6, 4.36e6, 1.35e7 | TLE, TLE, TLE | 3.65e6, 3.65e6, 1.21e7 | 3.37e6, 3.37e6, 1.11e7
Random Line | TLE, TLE, TLE | 6.28e6, 6.28e6, 2.07e7 | 6.00e6, 6.45e6, 2.03e7 | TLE, TLE, TLE | 5.64e6, 5.64e6, 1.86e7 | 5.56e6, 5.56e6, 1.83e7

### Scheme 1:
Trees (Num Rotations, Num Pointers Traversed, Total)|  I-Rand-1 |  I-Rand-2 |  I-Rand-3 |  I-Rand-4 
--- | --- | --- | --- | --- 
Uniform | 1.24e7, 2.49e7, 5.34e7 | 1.29e7, 2.59e7, 5.57e7 | 1.34e7, 2.69e7, 5.77e7 | 1.37e7, 2.75e7, 5.92e7
Zipf | 6.63e6, 1.33e7, 2.85e7 | 6.92e6, 1.38e7, 2.98e7 | 7.22e6, 1.44e7, 3.10e7 | 7.46e6, 1.49e7, 3.21e7
Stack | 1.00e6, 2.00e6, 4.30e6 | 1.00e6, 2.00e6, 4.30e6 | 1.00e6, 2.00e6, 4.30e6 | 1.00e6, 2.00e6, 4.30e6
Line | TLE, TLE, TLE | 3.71e6, 6.43e6, 1.50e7 | 3.04e6, 5.09e6, 1.21e7 | 2.78e6, 4.57e6, 1.10e7
Random Line | TLE, TLE, TLE | 4.87e6, 1.05e7, 2.17e7 | 4.32e6, 0.95e7, 1.94e7 | 4.17e6, 0.93e7, 1.89e7

### Scheme 2:
Trees (Num Rotations, Num Pointers Traversed, Total)|  II-Rand-1 |  II-Rand-2 |  II-Rand-3 |  II-Rand-4
--- | --- | --- | --- | --- 
Uniform | 2.42e7, 2.47e7, 8.05e7 | 2.53e7, 2.58e7, 8.39e7 | 2.62e7, 2.67e7, 8.71e7 | 2.69e7, 2.74e7, 8.93e7
Zipf | 1.32e7, 1.37e7, 4.41e7 | 1.38e7, 1.43e7, 4.61e7 | 1.44e7, 1.49e7, 4.81e7 | 1.49e7, 1.54e7, 4.97e7
Stack | 1.00e6, 1.50e6, 3.80e6 | 1.00e6, 1.50e6, 3.80e6 | 1.00e6, 1.50e6, 3.80e6 | 1.00e6, 1.50e6, 3.80e6
Line | TLE, TLE, TLE | 3.92e6, 4.29e6, 1.33e7 | 3.35e6, 3.81e6, 1.15e7 | 3.16e6, 3.63e6, 1.09e7
Random Line | TLE, TLE, TLE | 5.70e6, 6.16e6, 1.93e7 | 5.30e6, 5.78e6, 1.80e7 | 5.31e6, 5.80e6, 1.80e7

### Scheme 3:
Trees (Num Rotations, Num Pointers Traversed, Total)|  III-Rand-1, 1 |  III-Rand-2, 1 |  III-Rand-3, 1 |  III-Rand-4, 1 
--- | --- | --- | --- | --- 
Uniform | 1.24e7, 3.73e7, 6.59e7 | 1.28e7, 3.21e7, 6.16e7 | 1.35e7, 3.15e7, 6.26e7 | 1.41e7, 3.16e7, 6.41e7
Zipf | 6.77e6, 2.03e7, 3.59e7 | 6.92e6, 1.74e7, 3.33e7 | 7.33e6, 1.72e7, 3.40e7 | 7.74e6, 1.73e7, 3.51e7
Stack | 1.00e6, 3.00e6, 5.30e6 | 1.00e6, 2.67e6, 4.97e6 | 1.00e6, 2.46e6, 4.76e6 | 1.00e6, 2.32e6, 4.62e6
Line | TLE, TLE, TLE | 2.91e6, 7.41e6, 1.41e7 | 2.76e6, 6.48e6, 1.28e7 | 2.77e6, 6.04e6, 1.24e7
Random Line | TLE, TLE, TLE | 4.18e6, 1.06e7, 2.02e7 | 4.18e6, 0.98e7, 1.94e7 | 4.32e6, 0.95e7, 1.95e7

### Varying p for Scheme 1:
Tests | Uniform| Zipf| Stack| Line| Random Line
--- | --- | --- | --- | --- | --- 
1 - 2^{-7}  | 8.50e7 | 4.48e7 | 3.31e6 | 1.46e7 | 2.07e7
1 - 2^{-6}  | 8.45e7 | 4.46e7 | 3.32e6 | 1.46e7 | 2.07e7
1 - 2^{-5}  | 8.36e7 | 4.41e7 | 3.33e6 | 1.46e7 | 2.06e7
1 - 2^{-4}  | 8.17e7 | 4.31e7 | 3.37e6 | 1.45e7 | 2.08e7
1 - 2^{-3}  | 7.80e7 | 4.12e7 | 3.44e6 | 1.45e7 | 2.05e7
1 - 2^{-2}  | 7.06e7 | 3.74e7 | 3.63e6 | 1.59e7 | 2.01e7
2^{-1}  | 5.57e7 | 2.98e7 | 4.30e6 | 1.50e7 | 2.17e7
2^{-2}  | 4.08e7 | 2.22e7 | 6.28e6 | 1.59e7 | 2.41e7
2^{-3}  | 3.34e7 | 1.85e7 | 1.03e7 | 2.55e7 | 3.34e7
2^{-4}  | 2.97e7 | 1.69e7 | 1.82e7 | 2.66e7 | 4.41e7
2^{-5}  | 2.78e7 | 1.63e7 | 3.40e7 | 7.31e7 | 1.40e8
2^{-6}  | 2.69e7 | 1.62e7 | 6.58e7 | 8.68e7 | 3.19e8
2^{-7}  | 2.64e7 | 1.64e7 | 1.29e8 | 2.07e8 | 4.67e8

### Varying p for Scheme 2:
Tests | Uniform| Zipf| Stack| Line| Random Line
--- | --- | --- | --- | --- | --- 
1 - 2^{-7}  | 8.54e7 | 4.51e7 | 3.31e6 | 1.46e7 | 2.07e7
1 - 2^{-6}  | 8.54e7 | 4.51e7 | 3.32e6 | 1.45e7 | 2.07e7
1 - 2^{-5}  | 8.53e7 | 4.51e7 | 3.33e6 | 1.45e7 | 2.06e7
1 - 2^{-4}  | 8.52e7 | 4.51e7 | 3.36e6 | 1.45e7 | 2.06e7
1 - 2^{-3}  | 8.51e7 | 4.52e7 | 3.43e6 | 1.44e7 | 2.04e7
1 - 2^{-2}  | 8.47e7 | 4.54e7 | 3.55e6 | 1.41e7 | 2.00e7
2^{-1}  | 8.39e7 | 4.61e7 | 3.80e6 | 1.33e7 | 1.93e7
2^{-2}  | 8.31e7 | 4.77e7 | 4.05e6 | 1.23e7 | 1.85e7
2^{-3}  | 8.27e7 | 4.92e7 | 4.17e6 | 1.17e7 | 1.81e7
2^{-4}  | 8.25e7 | 5.04e7 | 4.24e6 | 1.14e7 | 1.79e7
2^{-5}  | 8.24e7 | 5.12e7 | 4.27e6 | 1.12e7 | 1.78e7
2^{-6}  | 8.24e7 | 5.17e7 | 4.28e6 | 1.12e7 | 1.77e7
2^{-7}  | 8.24e7 | 5.21e7 | 4.29e6 | 1.11e7 | 1.77e7

### Varying p for Scheme 3:
Tests | Uniform| Zipf| Stack| Line| Random Line
--- | --- | --- | --- | --- | --- 
1 - 2^{-7}  | 8.51e7 | 4.49e7 | 3.32e6 | 1.43e7 | 2.03e7
1 - 2^{-6}  | 8.47e7 | 4.47e7 | 3.33e6 | 1.40e7 | 2.00e7
1 - 2^{-5}  | 8.39e7 | 4.43e7 | 3.36e6 | 1.39e7 | 1.97e7
1 - 2^{-4}  | 8.24e7 | 4.36e7 | 3.43e6 | 1.37e7 | 1.94e7
1 - 2^{-3}  | 7.94e7 | 4.21e7 | 3.57e6 | 1.35e7 | 1.91e7
1 - 2^{-2}  | 7.34e7 | 3.91e7 | 3.90e6 | 1.34e7 | 1.91e7
2^{-1}  | 6.16e7 | 3.33e7 | 4.97e6 | 1.40e7 | 2.02e7
2^{-2}  | 4.99e7 | 2.77e7 | 8.00e6 | 1.77e7 | 2.54e7
2^{-3}  | 4.42e7 | 2.52e7 | 1.40e7 | 2.50e7 | 3.66e7
2^{-4}  | 4.13e7 | 2.43e7 | 2.60e7 | 3.88e7 | 5.87e7
2^{-5}  | 3.99e7 | 2.43e7 | 5.00e7 | 6.47e7 | 1.02e8
2^{-6}  | 3.93e7 | 2.48e7 | 0.98e8 | 1.15e8 | 1.87e8
2^{-7}  | 3.89e7 | 2.55e7 | 1.94e8 | 2.13e8 | 3.57e8