#include "Test.hpp"

int main()
{
	Test test;
	test.runTest();
	
	return 0;
}


//
// void checkVector()
// {
// 	using namespace std::chrono;
// 	std::cout << "VECTOR:\n";
// 	std::vector<whatTesting> currentContainer;
// 	//push_back
// 	std::cout << "push_back\n";
// 	steady_clock::time_point timeStart = steady_clock::now();
// 	for (auto i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		currentContainer.push_back(whatTesting());
// 	}
// 	steady_clock::time_point timeEnd = steady_clock::now();
// 	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	//push_front
// 	currentContainer.clear();
// 	std::cout << "push_front\n";
// 	timeStart = steady_clock::now();
// 	
// 	for (auto i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		currentContainer.insert(currentContainer.begin(), whatTesting());
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	//insert in middle
// 	currentContainer.clear();
// 	std::cout << "insert in middle\n";
// 	timeStart = steady_clock::now();
// 	
// 	for (auto i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		currentContainer.insert(currentContainer.begin()+currentContainer.size()/2, whatTesting());
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	
// 	//find element
// 	std::cout << "find element\n";	
// 	timeStart = steady_clock::now();
// 	
// 	for (unsigned long long i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		std::find(currentContainer.begin(), currentContainer.end(), i);
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	
// 	//erase
// 	std::cout << "erase\n";
// 	timeStart = steady_clock::now();
// 	for (auto it = currentContainer.begin(); it != currentContainer.end();)
// 	{
// 		it = currentContainer.erase(it);
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	
// 	
// }
//
// void checkList()
// {
// 	using namespace std::chrono;
// 	
// 	std::cout << "LIST:\n";
// 	std::list<whatTesting> currentContainer;
// 	//push_back
// 	std::cout << "push_back\n";
// 	steady_clock::time_point timeStart = steady_clock::now();
// 	for (unsigned long long i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		currentContainer.push_back(whatTesting());
// 	}
// 	steady_clock::time_point timeEnd = steady_clock::now();
// 	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	//push_front
// 	currentContainer.clear();
// 	std::cout << "push_front\n";
// 	timeStart = steady_clock::now();
// 	
// 	for (unsigned long long i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		currentContainer.push_front(whatTesting());
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	//insert in middle
// 	currentContainer.clear();
// 	std::cout << "insert in middle\n";
// 	timeStart = steady_clock::now();
// 	currentContainer.insert(currentContainer.begin(), whatTesting());
//
// 	for (unsigned long long i = 0; i < NUM_TO_TEST/2; i += 2) {
// 		currentContainer.push_back(whatTesting());
// 	}
//
// 	auto listIterator = currentContainer.begin();
// 	for (unsigned long long i = 1; i < NUM_TO_TEST/2; i += 2) {
// 		currentContainer.insert(std::next(listIterator), whatTesting());
// 		listIterator = std::next(listIterator, 2);
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	
// 	//find element
// 	std::cout << "find element\n";	
// 	timeStart = steady_clock::now();
// 	
// 	for (unsigned long long i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		std::find(currentContainer.begin(), currentContainer.end(), whatTesting());
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	
// 	//erase
// 	std::cout << "erase\n";
// 	timeStart = steady_clock::now();
// 	for (auto it = currentContainer.begin(); it != currentContainer.end();)
// 	{
// 		it = currentContainer.erase(it);
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// }
//
// void checkSet()
// {
// 	using namespace std::chrono;
// 	std::cout << "SET:\n";
// 	std::set<whatTesting> currentContainer;
// 	
// 	//push_back
// 	std::cout << "push_back\n";
// 	steady_clock::time_point timeStart = steady_clock::now();
// 	for (unsigned long long i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		//currentContainer.push_back(i);
// 	}
// 	steady_clock::time_point timeEnd = steady_clock::now();
// 	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	//push_front
// 	currentContainer.clear();
// 	std::cout << "push_front\n";
// 	timeStart = steady_clock::now();
// 	
// 	for (unsigned long long i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		//currentContainer.push_front(i);
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	//insert in middle
// 	currentContainer.clear();
// 	std::cout << "insert in middle\n";
// 	timeStart = steady_clock::now();
// 	currentContainer.insert(currentContainer.begin(), whatTesting());
//
// 	for (unsigned long long i = 0; i < NUM_TO_TEST/2; i += 2) {
// 		currentContainer.insert(currentContainer.begin(), whatTesting());
// 	}
//
// 	auto listIterator = currentContainer.begin();
// 	for (unsigned long long i = 1; i < NUM_TO_TEST/2; i += 2) {
// 		currentContainer.insert(std::next(listIterator), whatTesting());
// 		listIterator = std::next(listIterator, 2);
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	
// 	//find element
// 	std::cout << "find element\n";	
// 	timeStart = steady_clock::now();
// 	
// 	for (unsigned long long i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		std::find(currentContainer.begin(), currentContainer.end(), i);
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	
// 	//erase
// 	std::cout << "erase\n";
// 	timeStart = steady_clock::now();
// 	for (auto it = currentContainer.begin(); it != currentContainer.end();)
// 	{
// 		it = currentContainer.erase(it);
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// }
//
// void checkDeque()
// {
// 	using namespace std::chrono;
// 	std::cout << "DEQUE:\n";
// 	std::deque<whatTesting> currentContainer;
// 	//push_back
// 	std::cout << "push_back\n";
// 	steady_clock::time_point timeStart = steady_clock::now();
// 	for (unsigned long long i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		currentContainer.push_back(whatTesting());
// 	}
// 	steady_clock::time_point timeEnd = steady_clock::now();
// 	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	//push_front
// 	currentContainer.clear();
// 	std::cout << "push_front\n";
// 	timeStart = steady_clock::now();
// 	
// 	for (unsigned long long i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		currentContainer.push_front(whatTesting());
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	//insert in middle
// 	/*currentContainer.clear();
// 	std::cout << "insert in middle\n";
// 	timeStart = steady_clock::now();
//
// 	for (unsigned long long i = 0; i < NUM_TO_TEST/2; i += 2) {
// 		currentContainer.push_back(i);
// 	}
// 	
// 	auto listIterator = currentContainer.begin();
// 	for (unsigned long long i = 1; i < NUM_TO_TEST/2; i += 2) {
// 		currentContainer.insert(std::next(listIterator), i);
// 		listIterator = std::next(listIterator, 2);
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";*/
// 	
// 	//find element
// 	std::cout << "find element\n";	
// 	timeStart = steady_clock::now();
// 	
// 	for (unsigned long long i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		std::find(currentContainer.begin(), currentContainer.end(), i);
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	
// 	//erase
// 	std::cout << "erase\n";
// 	timeStart = steady_clock::now();
// 	for (auto it = currentContainer.begin(); it != currentContainer.end();)
// 	{
// 		it = currentContainer.erase(it);
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// }
//
// void checkUnorderedSet()
// {
// 	using namespace std::chrono;
// 	std::cout << "UNORDERED SET:\n";
// 	std::unordered_set<whatTesting> currentContainer;
// 	//push_back
// 	std::cout << "push_back\n";
// 	steady_clock::time_point timeStart = steady_clock::now();
// 	for (unsigned long long i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		//currentContainer.push_back(i);
// 	}
// 	steady_clock::time_point timeEnd = steady_clock::now();
// 	duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	//push_front
// 	currentContainer.clear();
// 	std::cout << "push_front\n";
// 	timeStart = steady_clock::now();
// 	
// 	for (unsigned long long i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		//currentContainer.push_front(i);
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	//insert in middle
// 	currentContainer.clear();
// 	std::cout << "insert in middle\n";
// 	timeStart = steady_clock::now();
// 	/*currentContainer.insert(currentContainer.begin(), 0);
//
// 	for (unsigned long long i = 0; i < NUM_TO_TEST/2; i += 2) {
// 		currentContainer.insert(currentContainer.begin(), i);
// 	}
//
// 	std::unordered_set<unsigned long long>::iterator listIterator = currentContainer.begin();
// 	for (unsigned long long i = 1; i < NUM_TO_TEST/2; i += 2) {
// 		currentContainer.insert(std::next(listIterator), i);
// 		listIterator = std::next(listIterator, 2);
// 	}*/
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	
// 	//find element
// 	std::cout << "find element\n";	
// 	timeStart = steady_clock::now();
// 	
// 	for (unsigned long long i = 0; i < NUM_TO_TEST; i++)
// 	{
// 		std::find(currentContainer.begin(), currentContainer.end(), i);
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// 	
// 	//erase
// 	std::cout << "erase\n";
// 	timeStart = steady_clock::now();
// 	for (auto it = currentContainer.begin(); it != currentContainer.end();)
// 	{
// 		it = currentContainer.erase(it);
// 	}
// 	timeEnd = steady_clock::now();
// 	time_span = duration_cast<duration<double>>(timeEnd - timeStart);
// 	std::cout << time_span.count() << " seconds.\n";
// }