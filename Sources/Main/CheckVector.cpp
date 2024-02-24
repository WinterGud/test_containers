#include "CheckVector.h"
#include "chrono"
#include "iostream"

namespace 
{
    using namespace std::chrono;
}

CheckVector::CheckVector(unsigned long long n)
    : NUM_TO_TEST(n)
{
}

void CheckVector::checkPushBack()
{
    doContainerEmpty();
    steady_clock::time_point timeStart = steady_clock::now();
    
    for (auto i = 0; i < NUM_TO_TEST; i++)
    {
        m_arr.push_back(containerType());
    }
    
    steady_clock::time_point timeEnd = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
    std::cout << time_span.count() << " seconds.\n";
}

void CheckVector::checkPushFront()
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

void CheckVector::checkPushInMiddle()
{
    doContainerEmpty();
    steady_clock::time_point timeStart = steady_clock::now();
    
    for (auto i = 0; i < NUM_TO_TEST; i++)
    {
        m_arr.insert(m_arr.begin()+m_arr.size()/2, containerType());
    }
    
    steady_clock::time_point timeEnd = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(timeEnd - timeStart);
    std::cout << time_span.count() << " seconds.\n";
}

void CheckVector::checkFind()
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

void CheckVector::checkErase()
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

void CheckVector::doContainerEmpty()
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

void CheckVector::fillContainer()
{
    if(!m_arr.empty())
    {
        m_arr.clear();
    }
    for (auto i = 0; i < NUM_TO_TEST; i++)
    {
        m_arr.push_back(containerType());
    }
}


void CheckVector::testContainer()
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