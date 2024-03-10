#include "Test.hpp"
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>


int main()
{
	std::set<int> s1();
	std::vector<int> v1(20);
	std::list<int> l1(20);
	std::deque<int> d1(20);
	std::unordered_set<int> us1(20);
	test();
	
	return 0;
}