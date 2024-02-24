#pragma once
#include "checkVector"


class Test
{
public:
    static void runTest();

	
private:
    constexpr unsigned long long NUM_TO_TEST = 100000;
    struct structForTest
    {
        int arr[1000];
    };
    using whatTesting = int;
    class CheckVector;
    class CheckList;
    class CheckDeque;
    class CheckUnorderedSet;
    class CheckSet;
};