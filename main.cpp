#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

#include "quicksort.h"

int main(int argc, char* argv[])
{
// Real feature-a line 1
// Real feature-a line 2

	std::vector<std::string> v(10);
	v[0]="Paris";
	v[1]="London";
	v[2]="Stockholm";
	v[3]="Berlin";
	v[4]="Oslo";
	v[5]="Rome";
	v[6]="Madrid";
	v[7]="Tallinn";
	v[8]="Amsterdam";
	v[9]="Dublin";

	std::cout<<"v before qsort: ";
	std::for_each(v.begin(), v.end(), print<std::string>);
	std::cout<<'\n';

	quick_sort(v.begin(), v.end());

	std::cout<<"v after qsort: ";
	std::for_each(v.begin(), v.end(), print<std::string>);
	std::cout<<'\n';

	// data
	int a[]={3,8,0,6,7,4,2,1,9,3,1,8,3,9,2,0,9};
	int *a_end=a+sizeof a/sizeof(int);

	std::cout<<"a before qsort: ";
	std::for_each(a, a_end, print<int>);
	std::cout<<'\n';

	quick_sort(a, a_end);
	
	std::cout<<"a after qsort: ";
	std::for_each(a, a_end, print<int>);
	std::cout<<'\n';

	return 0;
}
