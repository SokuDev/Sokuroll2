//
// Created by PC_volt on 30/09/2023.
//

#include "SavestateStack.hpp"
#include <iostream>

void SavestateStack::addSavestate()
{
    m_savestates.push_back(new Savestate());
    if (m_savestates.size() > m_maxSaves)
    {
        m_savestates.erase(m_savestates.begin());
    }
}