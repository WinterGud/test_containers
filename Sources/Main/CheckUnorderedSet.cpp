#include "CheckUnorderedSet.h"
#include "chrono"
#include "iostream"

namespace 
{
    using namespace std::chrono;
}

CheckUnorderedSet::CheckUnorderedSet(unsigned long long n)
    : NUM_TO_TEST(n)
{
}

void CheckUnorderedSet::checkPushBack()
{
    doContainerEmpty();
    steady_clock::time_point timeStart = steady_clock::now();

    for (auto i = 0; i < NUM_TO_TEST; i++)
    {
        m_arr.insert(m_arr.end(), containerType());
    }
    
    steady_clock::time_point timeEnd = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
    std::cout << time_span.count() << " seconds.\n";
}

void CheckUnorderedSet::checkPushFront()
{
    doContainerEmpty();
    steady_clock::time_point timeStart = steady_clock::now();

    for (auto i = 0; i < NUM_TO_TEST; i++)
    {
        m_arr.insert(m_arr.begin(), containerType());
    }
    
    steady_clock::time_point timeEnd = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
    std::cout << time_span.count() << " seconds.\n";
}

void CheckUnorderedSet::checkPushInMiddle()
{
    std::cout << "in process\n";
    // doContainerEmpty();
    // steady_clock::time_point timeStart = steady_clock::now();
    //
    // for (auto i = 0; i < NUM_TO_TEST; i++)
    // {
    //     m_arr.insert(m_arr.begin(), containerType());
    // }
    //
    // steady_clock::time_point timeEnd = steady_clock::now();
    // duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
    // std::cout << time_span.count() << " seconds.\n";
}

void CheckUnorderedSet::checkFind()
{
    fillContainer();
    steady_clock::time_point timeStart = steady_clock::now();
    
    for (auto i = 0; i < NUM_TO_TEST; i++)
    {
        std::find(m_arr.begin(), m_arr.end(), containerType());
    }
    
    steady_clock::time_point timeEnd = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
    std::cout << time_span.count() << " seconds.\n";
}

void CheckUnorderedSet::checkErase()
{
    fillContainer();
    steady_clock::time_point timeStart = steady_clock::now();

    for (auto it = m_arr.begin(); it != m_arr.end();)
    {
        it = m_arr.erase(it);
    }
    
    steady_clock::time_point timeEnd = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
    std::cout << time_span.count() << " seconds.\n";
}

void CheckUnorderedSet::doContainerEmpty()
{
    if(m_arr.empty())
    {
        return;
    }
    else
    {
        m_arr.clear();
    }
}

void CheckUnorderedSet::fillContainer()
{
    if(!m_arr.empty())
    {
        m_arr.clear();
    }
    for (auto i = 0; i < NUM_TO_TEST; i++)
    {
        m_arr.insert(m_arr.begin(), containerType());
    }
}

void CheckUnorderedSet::testContainer()
{
    std::cout << "PushBack\t";
    checkPushBack();
    std::cout << "PushFront\t";
    checkPushFront();
    std::cout << "PushInMiddle\t";
    checkPushInMiddle();
    std::cout << "FindElement\t";
    checkFind();
    std::cout << "Erase\t\t";
    checkErase();
}