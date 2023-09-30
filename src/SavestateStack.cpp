//
// Created by PC_volt on 30/09/2023.
//

#include "SavestateStack.hpp"

void SavestateStack::addSavestate()
{
    m_savestates.push_back(new Savestate());
    if (m_savestates.size() > m_maxSaves)
    {
        m_savestates.erase(m_savestates.begin());
    }
}

Savestate &SavestateStack::getSavestate(unsigned int index)
{
    if (index + 1 > m_savestates.size())
    {
        throw std::runtime_error("Accessing index out of range.");
    }

    return *m_savestates[index];
}

const int SavestateStack::getSize() const
{
    return m_savestates.size();
}