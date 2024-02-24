#include "CheckSet.h"
#include "chrono"
#include "iostream"

namespace 
{
    using namespace std::chrono;
}

CheckSet::CheckSet(unsigned long long n)
    : NUM_TO_TEST(n)
{
}

void CheckSet::checkPushBack()
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

void CheckSet::checkPushFront()
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

void CheckSet::checkPushInMiddle()
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

void CheckSet::checkFind()
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

void CheckSet::checkErase()
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

void CheckSet::doContainerEmpty()
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

void CheckSet::fillContainer()
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

void CheckSet::testContainer()
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