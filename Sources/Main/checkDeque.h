#pragma once
#include <deque>
#include <memory>

class CheckDeque
{
public:
    CheckDeque(unsigned long long n);
    void testContainer();
private:
    void checkPushBack();
    void checkPushFront();
    void checkPushInMiddle();
    void checkFind();
    void checkErase();
    void doContainerEmpty();
    void fillContainer();

    using containerType = std::unique_ptr<int>;
    std::deque<containerType> m_arr;
    const unsigned long long NUM_TO_TEST;
};
