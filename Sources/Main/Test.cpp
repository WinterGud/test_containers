#include "Test.hpp"
#include "CheckVector.h"
#include "CheckList.h"
#include "CheckDeque.h"
#include "CheckUnorderedSet.h"
#include "CheckSet.h"
#include <iostream>

void Test::runTest()
{
    std::cout << "=====================================\n";
    std::cout << "Vector\n";
    m_checkVector.testContainer();
    std::cout << "=====================================\n";
    std::cout << "List\n";
    m_checkList.testContainer();
    std::cout << "=====================================\n";
    std::cout << "Deque\n";
    m_checkDeque.testContainer();
    std::cout << "=====================================\n";
    std::cout << "UnorderedSet\n";
    m_checkUnorderedSet.testContainer();
    std::cout << "=====================================\n";
    std::cout << "Set\n";
    m_checkSet.testContainer();
    std::cout << "=====================================\n";
}
