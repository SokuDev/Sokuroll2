//
// Created by PC_volt on 30/09/2023.
//

#ifndef SOKULIB_SAVESTATESTACK_HPP
#define SOKULIB_SAVESTATESTACK_HPP

#include "Savestate.hpp"

#include <vector>

/**
 * The SavestateStack is a list of Savestates, from which we can select which Savestate to compare and to load.
 */
class SavestateStack
{
public:
    void addSavestate();
    Savestate &getSavestate(unsigned int index);
    const int getSize() const;

private:
    int m_maxSaves = 10;
    std::vector<Savestate *> m_savestates;
};


#endif //SOKULIB_SAVESTATESTACK_HPP
