#pragma once
#include "CheckVector.h"
#include "CheckList.h"
#include "CheckDeque.h"
#include "CheckUnorderedSet.h"
#include "CheckSet.h"

class Test
{
public:
    void runTest();
    unsigned long long NUM = 10000;
	
private:
    
    CheckVector m_checkVector = CheckVector(NUM);
    CheckList m_checkList = CheckList(NUM);
    CheckDeque m_checkDeque = CheckDeque(NUM);
    CheckUnorderedSet m_checkUnorderedSet = CheckUnorderedSet(NUM);
    CheckSet m_checkSet = CheckSet(NUM);
    
};