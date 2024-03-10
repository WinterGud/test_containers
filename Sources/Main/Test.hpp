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
		const int SIZE_ARR = 100;
		int arr[100];
		int n = 0;
		strc1()
		{
			for (int i = 0; i < SIZE_ARR; ++i)
			{
				arr[i] = n + 1;
			}
		}


		strc1(int i): n(i)
		{
			for (int i = 0; i < SIZE_ARR; ++i)
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
	fillContainer<Container, T>(container);
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

template <template<typename...> class ContainerType>
void testFilledContainer(std::function<void(ContainerType<int>& container)>& funcInt
				  ,std::function<void(ContainerType<strc1>& container)>& funcStrc1
				  ,std::function<void(ContainerType<strc2>& container)>& funcStrc2
				  ,std::function<void(ContainerType<matrix>& container)>& funcMatr)
{
	std::cout << "Filled:\n--------------------------------------------------------------------\n";
	{
		std::cout << "IntContainer\n";
		auto intContainer = ContainerType<int>(NUM_TO_TEST);
		intContainer.clear();
		funcInt(intContainer);
		std::cout << "Strc1Container\n";
		auto strc1Container = ContainerType<strc1>(NUM_TO_TEST);
		strc1Container.clear();
		funcStrc1(strc1Container);
		std::cout << "Strc2Container\n";
		auto strc2Container = ContainerType<strc2>(NUM_TO_TEST);
		strc2Container.clear();
		funcStrc2(strc2Container);
		std::cout << "MatrContainer\n";
		auto matrContainer = ContainerType<matrix>(NUM_TO_TEST);
		matrContainer.clear();
		funcMatr(matrContainer);
	}
}

template <template<typename...> class ContainerType>
void testVoidContainer(std::function<void(ContainerType<int>& container)>& funcInt
				  ,std::function<void(ContainerType<strc1>& container)>& funcStrc1
				  ,std::function<void(ContainerType<strc2>& container)>& funcStrc2
				  ,std::function<void(ContainerType<matrix>& container)>& funcMatr)
{
	std::cout << "\nNot Filled:\n--------------------------------------------------------------------\n";
	{
		std::cout << "IntContainer\n";
		auto intContainer = ContainerType<int>();
		funcInt(intContainer);
		std::cout << "Strc1Container\n";
		auto strc1Container = ContainerType<strc1>();
		funcStrc1(strc1Container);
		std::cout << "Strc2Container\n";
		auto strc2Container = ContainerType<strc2>();
		funcStrc2(strc2Container);
		std::cout << "MatrContainer\n";
		auto matrContainer = ContainerType<matrix>();
		funcMatr(matrContainer);
	}
}

template <template<typename...> class ContainerType>
void finalPushBackForVoidContainer()
{
	using intContainer = ContainerType<int>;
	using strc1Container = ContainerType<strc1>;
	using strc2Container = ContainerType<strc2>;
	using matrixContainer = ContainerType<matrix>;
	std::function<void(intContainer&)> intFunc = pushBack<intContainer, int>;
	std::function<void(strc1Container&)> Strc1Func = pushBack<strc1Container, strc1>;
	std::function<void(strc2Container&)> Strc2Func = pushBack<strc2Container, strc2>;
	std::function<void(matrixContainer&)> MatrFunc = pushBack<matrixContainer, matrix>;
	
	testVoidContainer<ContainerType>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}



void testVector()
{
	std::cout << "Vector\n===============================================================================================\n";
	//pushFuncInTestFilledContainer<IntVec, Strc1Vec, Strc2Vec, MatrVec>();
	// testContainer<IntVec, Strc1Vec, Strc2Vec, MatrVec>();
	// testContainer<IntVec, Strc1Vec, Strc2Vec, MatrVec>();
	// testContainer<IntVec, Strc1Vec, Strc2Vec, MatrVec>();
	// testContainer<IntVec, Strc1Vec, Strc2Vec, MatrVec>();
}

void test()
{
	finalPushBackForVoidContainer<std::vector>();
	
}