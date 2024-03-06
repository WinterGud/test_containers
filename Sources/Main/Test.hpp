#pragma once
#include <iostream>
#include <vector>
#include <chrono>
#include <deque>
#include <functional>
#include <list>
#include <set>
#include <unordered_set>

namespace
{
	unsigned long long NUM_TO_TEST = 10000;
	struct strc1
	{
		#define sizeArr 100
		int arr[sizeArr];
		int n = 0;
		strc1()
		{
			for (int i = 0; i < sizeArr; ++i)
			{
				arr[i] = n + 1;
			}
		}


		strc1(int i): n(i)
		{
			for (int i = 0; i < sizeArr; ++i)
			{
				arr[i] = n + 1;
			}
		}
	};
	struct strc2
	{
		int* ptr;
		strc2(){}
		strc2(int i){}
		
	};
	struct matrix
	{
		int arr[10][10];
		int n = 0;
		matrix(int i): n(i)
		{
			for (int i = 0; i < 10; ++i)
			{
				for (int j = 0; j < 10; ++j)
				{
					arr[i][j] = n + 1;
				}
			}
		}
		matrix()
		{
			for (int i = 0; i < 10; ++i)
			{
				for (int j = 0; j < 10; ++j)
				{
					arr[i][j] = n + 1;
				}
			}
		}
	};
	
	using IntVec = std::vector<int>;
	using IntList = std::list<int>;
	using IntSet = std::set<int>;
	using IntDeque = std::deque<int>;
	using IntUnSet = std::unordered_set<int>;

	using Strc1Vec = std::vector<strc1>;
	using Strc1List = std::list<strc1>;
	using Strc1Set = std::set<strc1>;
	using Strc1Deque = std::deque<strc1>;
	using Strc1UnSet = std::unordered_set<strc1>;

	using Strc2Vec = std::vector<strc2>;
	using Strc2List = std::list<strc2>;
	using Strc2Set = std::set<strc2>;
	using Strc2Deque = std::deque<strc2>;
	using Strc2UnSet = std::unordered_set<strc2>;

	using MatrVec = std::vector<matrix>;
	using MatrList = std::list<matrix>;
	using MatrSet = std::set<matrix>;
	using MatrDeque = std::deque<matrix>;
	using MatrUnSet = std::unordered_set<matrix>;
}

template <typename Container, typename T>
void fillContainer(Container& container)
{
	for (auto i = 0; i < NUM_TO_TEST / 2; i++)
	{
		container.insert(container.end(), T(i));
	}
}

template <typename Container,typename T>
void pushBack(Container& container)
{
	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();
    
	for (auto i = 0; i < NUM_TO_TEST; i++)
	{
		container.push_back(T(i));
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}

template <typename Container,typename T>
void alternativePushBack(Container& container)
{
	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();
    
	for (auto i = 0; i < NUM_TO_TEST; i++)
	{
		container.insert(container.end(), T(i));
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}

template <typename Container,typename T>
void pushFront(Container& container)
{
	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();
    
	for (auto i = 0; i < NUM_TO_TEST; i++)
	{
		container.push_front(T(i));
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}

template <typename Container,typename T>
void alternativePushFront(Container& container)
{
	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();
    
	for (auto i = 0; i < NUM_TO_TEST; i++)
	{
		container.insert(container.begin(), T(i));
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}

template <typename Container,typename T>
void insertInMiddle(Container& container)
{
	fillContainer(container);
	auto middleIterator = container.begin();
	for(auto i = 0; i < container.size() / 2; i++)
	{
		++middleIterator;
	}
	
	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();
    
	for (auto i = 0; i < NUM_TO_TEST/2; i++)
	{
		container.insert(middleIterator, T(i));
		++middleIterator;
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}

template <typename Container, typename T>
void alternativeInsertInMiddle(Container& container)
{
	fillContainer(container);
	auto middleIterator = container.begin();
	for(auto i = 0; i < container.size() / 2; i++)
	{
		++middleIterator;
	}

	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();
	
	for (auto i = 0; i < NUM_TO_TEST; i++)
	{
		container.insert(middleIterator, T(i));
		if (i > 5 && middleIterator != container.end())
		{
			it++;
		}
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}

template <typename Container,typename T>
void find(Container& container)
{
	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();
    
	for (auto i = 0; i < NUM_TO_TEST; i++)
	{
		std::find(container.begin(), container.end(), T(i));
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}

template <typename Container,typename T>
void erase(Container& container)
{
	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();
    
	for (auto it = container.begin(); it != container.end();)
	{
		it = container.erase(it);
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}


template <typename IntContainer, typename Strc1Container, typename Strc2Container, typename MatrContainer>
void testSomething(std::function<void(IntContainer& container)>& funcInt
				  ,std::function<void(Strc1Container& container)>& funcStrc1
				  ,std::function<void(Strc2Container& container)>& funcStrc2
				  ,std::function<void(MatrContainer& container)>& funcMatr)
{
	std::cout << "Filled:\n--------------------------------------------------------------------\n";
	{
		IntContainer v1(NUM_TO_TEST);
		v1.clear();
		funcInt(v1);
		Strc1Container v2(NUM_TO_TEST);
		v2.clear();
		funcStrc1(v2);
		Strc2Container v3(NUM_TO_TEST);
		v3.clear();
		funcStrc2(v3);
		MatrContainer v4(NUM_TO_TEST);
		v4.clear();
		funcMatr(v4);
	}
	std::cout << "\nNot Filled:\n--------------------------------------------------------------------\n";
	{
		IntContainer v1;
		funcInt(v1);
		Strc1Container v2;
		funcStrc1(v2);
		Strc2Container v3;
		funcStrc2(v3);
		MatrContainer v4;
		funcMatr(v4);
	}
}

void test()
{
	std::function<void(IntVec&)> intFunc = pushBack<IntVec, int>;
	std::function<void(Strc1Vec&)> Strc1Func = pushBack<Strc1Vec, strc1>;
	std::function<void(Strc2Vec&)> Strc2Func = pushBack<Strc2Vec, strc2>;
	std::function<void(MatrVec&)> MatrFunc = pushBack<MatrVec, matrix>;
	testSomething<IntVec, Strc1Vec, Strc2Vec, MatrVec>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}