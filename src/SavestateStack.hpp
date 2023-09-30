//
// Created by PC_volt on 30/09/2023.
//

#ifndef SOKULIB_SAVESTATESTACK_HPP
#define SOKULIB_SAVESTATESTACK_HPP

#include "Savestate.hpp"

#include <vector>

class SavestateStack
{
public:
    void addSavestate();

private:
    int m_maxSaves = 10;
    std::vector<Savestate *> m_savestates;
};


#endif //SOKULIB_SAVESTATESTACK_HPP
