#pragma once
#include <memory>
#include <vector>

class CheckVector
{
public:
    CheckVector(unsigned long long n);
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
    std::vector<containerType> m_arr;
    const unsigned long long NUM_TO_TEST;
};
