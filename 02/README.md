# Exercise 02

Deadline: 2022-11-17 10:00AM

## Written

The following two figures show different depictions of the function $`f(x,y) = \textrm{sin}(x^2 + y^2 )`$, which have been created with different sampling patterns.

* In figure a) a regular grid is used for sampling. Sampling points are located at the center of grid cells, where the function is evaluated.
* In b) the same grid is used for sampling, however the actual sampling point is offset randomly within the grid cell (_Jittering_).

Explain ...
1. ... how the patterns (_Moiré_-Artifacts) which can be seen in figure a) arise. (1 Point)
2. ... why these artifacts show up much less in figure b). (1 Point)

| a)                                               | b)                                               |
| ------------------------------------------------ | ------------------------------------------------ |
| ![Figure a)](resources/01.png "Abbildung a)")    | ![Figure b)](resources/02.png "Abbildung b)")    |



## Programming
Implement the function $`f`$ in `C++` using `std::sin()` from `<cmath>`. Recreate figures a) and b), by creating a new image of $`500 \times 500`$ pixels and rendering $`f`$ to it. The shown figures cover a quadratic area between the points  $`(0,0)`$ and $`(30,30)`$.

Use this code fragment to generate your random numbers:

```
#include <random>

...
std::uniform_real_distribution<double> distribution(-unit, unit);
std::default_random_engine generator;
...
const double random_value = distribution(generator);
```

**Important hint:**, the sine function will give you result values in $`[-1; 1]`$ which you should map to $`[0; 255]`$ in order to obtain a suitable grey value for the image.

Points:

* Recreating figure a) (3 Points)
* Recreating figure b) (3 Points)
* Jittering (1 Point)
* Correct section of the function (1 Point)

Total: 10 Points
