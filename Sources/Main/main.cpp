#include <iostream>
#include <vector>
#include <chrono>
#include <list>

namespace
{
	unsigned long long NUM_TO_TEST = 1000000;
	struct strc1
	{
		int arr[100];
	};

	struct strc2
	{
		int* ptr;
	};
	
	struct matrix
	{
		int arr[10][10];
	};
}

template <typename Container,typename T>
void pushBack(Container container, T p_T)
{
	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();
    
	for (auto i = 0; i < NUM_TO_TEST; i++)
	{
		container.push_back(T());
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}

template <typename Container,typename T>
void alternativePushBack(Container container, T p_T)
{
	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();
    
	for (auto i = 0; i < NUM_TO_TEST; i++)
	{
		container.insert(container.begin());
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}

template <typename Container,typename T>
void pushFront(Container container, T p_T)
{
	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();
    
	for (auto i = 0; i < NUM_TO_TEST; i++)
	{
		container.push_front(T());
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}

template <typename Container,typename T>
void alternativePushFront(Container container, T p_T)
{
	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();
    
	for (auto i = 0; i < NUM_TO_TEST; i++)
	{
		container.insert(container.end(), T());
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}

template <typename Container,typename T>
void insertInMiddle(Container container, T p_T)
{
	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();
    
	for (auto i = 0; i < NUM_TO_TEST; i++)
	{
		container.insert(container.begin()+container.size()/2, T());
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}

template <typename Container,typename T>
void alternativeInsertInMiddle(Container container, T p_T)
{
	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();

	auto it = container.begin();
	for (auto i = 0; i < NUM_TO_TEST; i++)
	{
		container.insert(it, T());
		if (i > 5)
		{
			it++;
		}
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}

template <typename Container,typename T>
void find(Container container, T p_T)
{
	using namespace std::chrono;
	steady_clock::time_point timeStart = steady_clock::now();
    
	for (auto i = 0; i < NUM_TO_TEST; i++)
	{
		std::find(container.begin(), container.end(), T());
	}
    
	steady_clock::time_point timeEnd = steady_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
	std::cout << time_span.count() << " seconds.\n";
}

template <typename Container,typename T>
void erase(Container container, T p_T)
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

void intVector();
void structVector();

void testVector()
{
	std::vector<int> v1=;
	v1.clear();
	std::cout << "PushBack\t";
	pushBack(v1, 0);
	std::cout << "PushFront\t";
	alternativePushFront(v1, 0);
	std::cout << "PushInMiddle\t";
	insertInMiddle(v1, 0);
	std::cout << "FindElement\t";
	find(v1, 0);
	std::cout << "Erase\t\t";
	erase(v1, 0);
}

int main()
{
	testVector();
	
	return 0;
}