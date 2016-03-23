/* Copyright (c) 2007 the authors listed at the following URL, and/or
the authors of referenced articles or incorporated external code:
http://en.literateprograms.org/Quicksort_(C_Plus_Plus)?action=history&offset=20070928075422
Retrieved from: http://en.literateprograms.org/Quicksort_(C_Plus_Plus)?oldid=10979
*/

#include <time.h>
#include <iostream>
#include <string>

#include "quicksort.h"

template<typename IT> IT partition(IT begin, IT end, IT pivot)
{
	typename std::iterator_traits<IT>::value_type piv(*pivot);
	std::swap(*pivot, *(end-1));
	IT store=begin;
	for(IT it=begin; it!=end-1; ++it) {
		if(*it<=piv) {
			std::swap(*store, *it);
			++store;
		}
	}
	std::swap(*(end-1), *store);
	return store;
}


template<typename IT> IT pivot_median(IT begin, IT end)
{
	IT pivot(begin+(end-begin)/2);
	if(*begin<=*pivot && *(end-1)<=*begin) pivot=begin;
	else if(*(end-1)<=*pivot && *begin<=*(end-1)) pivot=end-1;
	return pivot;
}

template<typename IT> pivot_random<IT>::pivot_random()
{
  srand((unsigned int)time(NULL));
}

template<typename IT> IT pivot_random<IT>::operator()(IT begin, IT end) {
	return begin+(rand()%(end-begin));
}

template<typename IT, typename PF> void quick_sort(IT begin, IT end, PF pf)
{
	if(end-1>begin) {
		IT pivot=pf(begin, end);

		pivot=partition(begin, end, pivot);

		quick_sort(begin, pivot, pf);
		quick_sort(pivot+1, end, pf);
	}
}

template<typename IT> void quick_sort(IT begin, IT end)
{
	quick_sort(begin, end, pivot_random<IT>());
}


template<typename T> void print(const T &data)
{
	std::cout<<" "<<data;
}


// dummy definitions for template instantiation
void dummyforInstantiation() // can't make this static: instantiated templates will not be visible to linker
{
  int i;
  std::string str;

  print(i);
  print(str);

  pivot_random<int*> pv;
  quick_sort(&i, &i, pv);

  std::vector<std::string>::iterator iter;
  quick_sort(iter, iter);
}
