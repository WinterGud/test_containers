#pragma once
#include <memory>
#include <unordered_set>

class CheckUnorderedSet
{
public:
    CheckUnorderedSet(unsigned long long n);
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
    std::unordered_set<containerType> m_arr;
    const unsigned long long NUM_TO_TEST;
};
