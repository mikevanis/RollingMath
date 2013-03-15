/*
* Rolling average routines
* Michail Vanis 2012
* Adapted by Majenki's Average library
*/

#ifndef _ROLLINGMATH_H
#define _ROLLINGMATH_H

template <size_t N, size_t M
/*
* Rolling average
*/
extern int rollingAverage(int *, int, int);

/*
* Rolling median
*/
extern int rollingMode(int *, int, int);

/*
* Rolling minimum
*/
extern int rollingMinimum(int *, int, int);

/*
* Rolling maximum
*/
extern int rollingMaximum(int *, int, int);

#endif