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
		const int SIZE_ARR = 50;
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

		bool operator<(const strc1& right) const
		{
			int sumArr1 = 0;
			int sumArr2 = 0;
			for (int i = 0; i < SIZE_ARR; i++)
			{
				sumArr1 += arr[i];
			}
			for (int i = 0; i < SIZE_ARR; i++)
			{
				sumArr2 += right.arr[i];
			}

			return sumArr1 < sumArr2;
		}

		bool operator==(const strc1& right) const
		{
			int sumArr1 = 0;
			int sumArr2 = 0;
			for (int i = 0; i < SIZE_ARR; i++)
			{
				sumArr1 += arr[i];
			}
			for (int i = 0; i < SIZE_ARR; i++)
			{
				sumArr2 += right.arr[i];
			}

			return sumArr1 == sumArr2;
		}

		strc1& operator=(const strc1& right)
		{
			for (int i = 0; i < SIZE_ARR; i++)
			{
				arr[i] = right.arr[i];
			}
			return *this;
		}
	};
	struct strc2
	{
		int* ptr;
		strc2(){}
		strc2(int i)
		{}
		
		bool operator<(const strc2& right) const
		{
			return ptr < right.ptr;
		}
		
		bool operator==(const strc2& right) const
		{
			return ptr == right.ptr;
		}
		
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
		bool operator<(const matrix& right) const
		{
			int sumArr1 = 0;
			int sumArr2 = 0;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					sumArr1 += arr[i][j];
				}
			}
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					sumArr2 += right.arr[i][j];
				}
			}

			return sumArr1 < sumArr2;
		}
		bool operator==(const matrix& right) const
		{
			int sumArr1 = 0;
			int sumArr2 = 0;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					sumArr1 += arr[i][j];
				}
			}
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					sumArr2 += right.arr[i][j];
				}
			}

			return sumArr1 == sumArr2;
		}
	};
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

template <typename Container, typename T>
void insertInMiddle(Container& container)
{
    fillContainer<Container, T>(container);
    auto middleIterator = container.begin();
    for (auto i = 0; i < container.size() / 2; i++)
    {
        ++middleIterator;
    }

    using namespace std::chrono;
    steady_clock::time_point timeStart = steady_clock::now();

    for (auto i = 0; i < NUM_TO_TEST / 2; i++)
    {
        container.insert(middleIterator, T(i));
        middleIterator = container.begin(); // Перераховуємо ітератор знову
        std::advance(middleIterator, container.size() / 2);
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

template <template<typename...> class ContainerType>
void finalAltPushBackForVoidContainer()
{
	using intContainer = ContainerType<int>;
	using strc1Container = ContainerType<strc1>;
	using strc2Container = ContainerType<strc2>;
	using matrixContainer = ContainerType<matrix>;
	
	std::function<void(intContainer&)> intFunc = alternativePushBack<intContainer, int>;
	std::function<void(strc1Container&)> Strc1Func = alternativePushBack<strc1Container, strc1>;
	std::function<void(strc2Container&)> Strc2Func = alternativePushBack<strc2Container, strc2>;
	std::function<void(matrixContainer&)> MatrFunc = alternativePushBack<matrixContainer, matrix>;
	
	testVoidContainer<ContainerType>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}

template <template<typename...> class ContainerType>
void finalPushFrontForVoidContainer()
{
	using intContainer = ContainerType<int>;
	using strc1Container = ContainerType<strc1>;
	using strc2Container = ContainerType<strc2>;
	using matrixContainer = ContainerType<matrix>;
	
	std::function<void(intContainer&)> intFunc = pushFront<intContainer, int>;
	std::function<void(strc1Container&)> Strc1Func = pushFront<strc1Container, strc1>;
	std::function<void(strc2Container&)> Strc2Func = pushFront<strc2Container, strc2>;
	std::function<void(matrixContainer&)> MatrFunc = pushFront<matrixContainer, matrix>;
	
	testVoidContainer<ContainerType>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}

template <template<typename...> class ContainerType>
void finalAltPushFrontForVoidContainer()
{
	using intContainer = ContainerType<int>;
	using strc1Container = ContainerType<strc1>;
	using strc2Container = ContainerType<strc2>;
	using matrixContainer = ContainerType<matrix>;
	
	std::function<void(intContainer&)> intFunc = alternativePushFront<intContainer, int>;
	std::function<void(strc1Container&)> Strc1Func = alternativePushFront<strc1Container, strc1>;
	std::function<void(strc2Container&)> Strc2Func = alternativePushFront<strc2Container, strc2>;
	std::function<void(matrixContainer&)> MatrFunc = alternativePushFront<matrixContainer, matrix>;
	
	testVoidContainer<ContainerType>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}

template <template<typename...> class ContainerType>
void finalInsertInMiddleForVoidContainer()
{
	using intContainer = ContainerType<int>;
	using strc1Container = ContainerType<strc1>;
	using strc2Container = ContainerType<strc2>;
	using matrixContainer = ContainerType<matrix>;
	
	std::function<void(intContainer&)> intFunc = insertInMiddle<intContainer, int>;
	std::function<void(strc1Container&)> Strc1Func = insertInMiddle<strc1Container, strc1>;
	std::function<void(strc2Container&)> Strc2Func = insertInMiddle<strc2Container, strc2>;
	std::function<void(matrixContainer&)> MatrFunc = insertInMiddle<matrixContainer, matrix>;
	
	testVoidContainer<ContainerType>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}

template <template<typename...> class ContainerType>
void finalFindForVoidContainer()
{
	using intContainer = ContainerType<int>;
	using strc1Container = ContainerType<strc1>;
	using strc2Container = ContainerType<strc2>;
	using matrixContainer = ContainerType<matrix>;
	
	std::function<void(intContainer&)> intFunc = find<intContainer, int>;
	std::function<void(strc1Container&)> Strc1Func = find<strc1Container, strc1>;
	std::function<void(strc2Container&)> Strc2Func = find<strc2Container, strc2>;
	std::function<void(matrixContainer&)> MatrFunc = find<matrixContainer, matrix>;
	
	testVoidContainer<ContainerType>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}

template <template<typename...> class ContainerType>
void finalEraseForVoidContainer()
{
	using intContainer = ContainerType<int>;
	using strc1Container = ContainerType<strc1>;
	using strc2Container = ContainerType<strc2>;
	using matrixContainer = ContainerType<matrix>;
	
	std::function<void(intContainer&)> intFunc = erase<intContainer, int>;
	std::function<void(strc1Container&)> Strc1Func = erase<strc1Container, strc1>;
	std::function<void(strc2Container&)> Strc2Func = erase<strc2Container, strc2>;
	std::function<void(matrixContainer&)> MatrFunc = erase<matrixContainer, matrix>;
	
	testVoidContainer<ContainerType>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}

template <template<typename...> class ContainerType>
void finalPushBackForFilledContainer()
{
	using intContainer = ContainerType<int>;
	using strc1Container = ContainerType<strc1>;
	using strc2Container = ContainerType<strc2>;
	using matrixContainer = ContainerType<matrix>;
	
	std::function<void(intContainer&)> intFunc = pushBack<intContainer, int>;
	std::function<void(strc1Container&)> Strc1Func = pushBack<strc1Container, strc1>;
	std::function<void(strc2Container&)> Strc2Func = pushBack<strc2Container, strc2>;
	std::function<void(matrixContainer&)> MatrFunc = pushBack<matrixContainer, matrix>;
	
	testFilledContainer<ContainerType>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}

template <template<typename...> class ContainerType>
void finalAltPushBackForFilledContainer()
{
	using intContainer = ContainerType<int>;
	using strc1Container = ContainerType<strc1>;
	using strc2Container = ContainerType<strc2>;
	using matrixContainer = ContainerType<matrix>;
	
	std::function<void(intContainer&)> intFunc = alternativePushBack<intContainer, int>;
	std::function<void(strc1Container&)> Strc1Func = alternativePushBack<strc1Container, strc1>;
	std::function<void(strc2Container&)> Strc2Func = alternativePushBack<strc2Container, strc2>;
	std::function<void(matrixContainer&)> MatrFunc = alternativePushBack<matrixContainer, matrix>;
	
	testFilledContainer<ContainerType>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}

template <template<typename...> class ContainerType>
void finalPushFrontForFilledContainer()
{
	using intContainer = ContainerType<int>;
	using strc1Container = ContainerType<strc1>;
	using strc2Container = ContainerType<strc2>;
	using matrixContainer = ContainerType<matrix>;
	
	std::function<void(intContainer&)> intFunc = pushFront<intContainer, int>;
	std::function<void(strc1Container&)> Strc1Func = pushFront<strc1Container, strc1>;
	std::function<void(strc2Container&)> Strc2Func = pushFront<strc2Container, strc2>;
	std::function<void(matrixContainer&)> MatrFunc = pushFront<matrixContainer, matrix>;
	
	testFilledContainer<ContainerType>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}

template <template<typename...> class ContainerType>
void finalAltPushFrontForFilledContainer()
{
	using intContainer = ContainerType<int>;
	using strc1Container = ContainerType<strc1>;
	using strc2Container = ContainerType<strc2>;
	using matrixContainer = ContainerType<matrix>;
	
	std::function<void(intContainer&)> intFunc = alternativePushFront<intContainer, int>;
	std::function<void(strc1Container&)> Strc1Func = alternativePushFront<strc1Container, strc1>;
	std::function<void(strc2Container&)> Strc2Func = alternativePushFront<strc2Container, strc2>;
	std::function<void(matrixContainer&)> MatrFunc = alternativePushFront<matrixContainer, matrix>;
	
	testFilledContainer<ContainerType>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}

template <template<typename...> class ContainerType>
void finalInsertInMiddleForFilledContainer()
{
	using intContainer = ContainerType<int>;
	using strc1Container = ContainerType<strc1>;
	using strc2Container = ContainerType<strc2>;
	using matrixContainer = ContainerType<matrix>;
	
	std::function<void(intContainer&)> intFunc = insertInMiddle<intContainer, int>;
	std::function<void(strc1Container&)> Strc1Func = insertInMiddle<strc1Container, strc1>;
	std::function<void(strc2Container&)> Strc2Func = insertInMiddle<strc2Container, strc2>;
	std::function<void(matrixContainer&)> MatrFunc = insertInMiddle<matrixContainer, matrix>;
	
	testFilledContainer<ContainerType>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}

template <template<typename...> class ContainerType>
void finalFindForFilledContainer()
{
	using intContainer = ContainerType<int>;
	using strc1Container = ContainerType<strc1>;
	using strc2Container = ContainerType<strc2>;
	using matrixContainer = ContainerType<matrix>;
	
	std::function<void(intContainer&)> intFunc = find<intContainer, int>;
	std::function<void(strc1Container&)> Strc1Func = find<strc1Container, strc1>;
	std::function<void(strc2Container&)> Strc2Func = find<strc2Container, strc2>;
	std::function<void(matrixContainer&)> MatrFunc = find<matrixContainer, matrix>;
	
	testFilledContainer<ContainerType>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}

template <template<typename...> class ContainerType>
void finalEraseForFilledContainer()
{
	using intContainer = ContainerType<int>;
	using strc1Container = ContainerType<strc1>;
	using strc2Container = ContainerType<strc2>;
	using matrixContainer = ContainerType<matrix>;
	
	std::function<void(intContainer&)> intFunc = erase<intContainer, int>;
	std::function<void(strc1Container&)> Strc1Func = erase<strc1Container, strc1>;
	std::function<void(strc2Container&)> Strc2Func = erase<strc2Container, strc2>;
	std::function<void(matrixContainer&)> MatrFunc = erase<matrixContainer, matrix>;
	
	testFilledContainer<ContainerType>(intFunc, Strc1Func, Strc2Func, MatrFunc);
}

void testPushBack()
{
	std::cout << "\n\nPUSH_BACK\n\n";
	std::cout << "Vector\n================================================================================================================================================================\n";
	finalPushBackForVoidContainer<std::vector>();
	std::cout << "List\n================================================================================================================================================================\n";
	finalPushBackForVoidContainer<std::list>();
	std::cout << "Deque\n================================================================================================================================================================\n";
	finalPushBackForVoidContainer<std::deque>();
	std::cout << "Set\n================================================================================================================================================================\n";
	finalAltPushBackForVoidContainer<std::set>();
	std::cout << "UnorderedSet\n================================================================================================================================================================\n";
	//finalAltPushBackForVoidContainer<std::unordered_set>();
	
	std::cout << "Vector\n================================================================================================================================================================\n";
	finalPushBackForFilledContainer<std::vector>();
	std::cout << "List\n================================================================================================================================================================\n";
	finalPushBackForFilledContainer<std::list>();
	std::cout << "Deque\n================================================================================================================================================================\n";
	finalPushBackForFilledContainer<std::deque>();
	std::cout << "Set\n================================================================================================================================================================\n";
	std::cout << "\nSet cannot be filled.\n";
	std::cout << "UnorderedSet\n================================================================================================================================================================\n";
	//finalAltPushBackForVoidContainer<std::unordered_set>();
}

void testPushFront()
{
	std::cout << "\n\nPUSH_FRONT\n\n";
	std::cout << "Vector\n================================================================================================================================================================\n";
	finalAltPushFrontForVoidContainer<std::vector>();
	std::cout << "List\n================================================================================================================================================================\n";
	finalPushFrontForVoidContainer<std::list>();
	std::cout << "Deque\n================================================================================================================================================================\n";
	finalPushFrontForVoidContainer<std::deque>();
	std::cout << "Set\n================================================================================================================================================================\n";
	finalAltPushFrontForVoidContainer<std::set>();
	std::cout << "UnorderedSet\n================================================================================================================================================================\n";
	//finalAltPushFrontForFilledContainer<std::unordered_set>();
	
	std::cout << "Vector\n================================================================================================================================================================\n";
	finalAltPushFrontForFilledContainer<std::vector>();
	std::cout << "List\n================================================================================================================================================================\n";
	finalPushFrontForFilledContainer<std::list>();
	std::cout << "Deque\n================================================================================================================================================================\n";
	finalPushFrontForFilledContainer<std::deque>();
	std::cout << "Set\n================================================================================================================================================================\n";
	std::cout << "\nSet cannot be filled.\n";
	std::cout << "UnorderedSet\n================================================================================================================================================================\n";
	//finalAltPushFrontForFilledContainer<std::unordered_set>();
}
void testInsertInMiddle()
{
	std::cout << "\n\nINSERT_IN_MIDDLE\n\n";
	std::cout << "Vector\n================================================================================================================================================================\n";
	finalInsertInMiddleForVoidContainer<std::vector>();
	std::cout << "List\n================================================================================================================================================================\n";
	finalInsertInMiddleForVoidContainer<std::list>();
	std::cout << "Deque\n================================================================================================================================================================\n";
	finalInsertInMiddleForVoidContainer<std::deque>();
	std::cout << "Set\n================================================================================================================================================================\n";
	finalInsertInMiddleForVoidContainer<std::set>();
	std::cout << "UnorderedSet\n================================================================================================================================================================\n";
	//finalInsertInMiddleForVoidContainer<std::unordered_set>();
	
	std::cout << "Vector\n================================================================================================================================================================\n";
	finalInsertInMiddleForFilledContainer<std::vector>();
	std::cout << "List\n================================================================================================================================================================\n";
	finalInsertInMiddleForFilledContainer<std::list>();
	std::cout << "Deque\n================================================================================================================================================================\n";
	finalInsertInMiddleForFilledContainer<std::deque>();
	std::cout << "Set\n================================================================================================================================================================\n";
	std::cout << "\nSet cannot be filled.\n";
	std::cout << "UnorderedSet\n================================================================================================================================================================\n";
	//finalInsertInMiddleForFilledContainer<std::unordered_set>();
}

void testFind()
{
	std::cout << "\n\nFIND\n\n";
	std::cout << "Vector\n================================================================================================================================================================\n";
	finalFindForVoidContainer<std::vector>();
	std::cout << "List\n================================================================================================================================================================\n";
	finalFindForVoidContainer<std::list>();
	std::cout << "Deque\n================================================================================================================================================================\n";
	finalFindForVoidContainer<std::deque>();
	std::cout << "Set\n================================================================================================================================================================\n";
	finalFindForVoidContainer<std::set>();
	std::cout << "UnorderedSet\n================================================================================================================================================================\n";
	//finalFindForVoidContainer<std::unordered_set>();
}

void testErase()
{
	std::cout << "\n\nERASE\n\n";
	std::cout << "Vector\n================================================================================================================================================================\n";
	finalEraseForVoidContainer<std::vector>();
	std::cout << "List\n================================================================================================================================================================\n";
	finalEraseForVoidContainer<std::list>();
	std::cout << "Deque\n================================================================================================================================================================\n";
	finalEraseForVoidContainer<std::deque>();
	std::cout << "Set\n================================================================================================================================================================\n";
	finalEraseForVoidContainer<std::set>();
	std::cout << "UnorderedSet\n================================================================================================================================================================\n";
	//finalEraseForVoidContainer<std::unordered_set>();
}


void test()
{
	testPushBack();
	testPushFront();
	testInsertInMiddle();
	testFind();
	testErase();
}