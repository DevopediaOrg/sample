/* Copyright (c) 2007 the authors listed at the following URL, and/or
the authors of referenced articles or incorporated external code:
http://en.literateprograms.org/Quicksort_(C_Plus_Plus)?action=history&offset=20070928075422
Retrieved from: http://en.literateprograms.org/Quicksort_(C_Plus_Plus)?oldid=10979
*/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <algorithm>	// std::swap()
#include <vector>

template<typename IT> IT partition(IT begin, IT end, IT pivot);

template<typename IT> IT pivot_median(IT begin, IT end);

template<typename IT> struct pivot_random {
	pivot_random();
	IT operator()(IT begin, IT end);
};

template<typename IT, typename PF> void quick_sort(IT begin, IT end, PF pf);

template<typename IT> void quick_sort(IT begin, IT end);

template<typename T> void print(const T &data);

#endif
