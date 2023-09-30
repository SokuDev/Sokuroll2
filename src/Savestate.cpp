//
// Created by PC_volt on 30/09/2023.
//

#include "Savestate.hpp"

Savestate::Savestate()
{
    SokuLib::BattleManager battleManager = SokuLib::getBattleMgr();
    readFrame(battleManager);
    readInputs(battleManager);
    readWeather();
}

void Savestate::readFrame(const SokuLib::BattleManager &battleManager)
{
    m_frame = battleManager.frameCount;
}

void Savestate::readInputs(const SokuLib::BattleManager &battleManager)
{
    m_savedInputs = new PlayersInputs();
    m_savedInputs->inputsP1 = battleManager.leftCharacterManager.keyMap;
    m_savedInputs->inputsP2 = battleManager.rightCharacterManager.keyMap;
}

void Savestate::readWeather()
{
    m_weather = SokuLib::activeWeather;
    m_weatherDisplayed = SokuLib::displayedWeather;
    m_weatherCounter = SokuLib::weatherCounter;
}

const unsigned int Savestate::getFrame() const
{
    return m_frame;
}

void Savestate::restore()
{
    SokuLib::BattleManager battleManager = SokuLib::getBattleMgr();
    battleManager.frameCount = m_frame;

    battleManager.leftCharacterManager.keyMap = m_savedInputs->inputsP1;
    battleManager.rightCharacterManager.keyMap = m_savedInputs->inputsP2;

    SokuLib::activeWeather = m_weather;
    SokuLib::displayedWeather = m_weatherDisplayed;
    SokuLib::weatherCounter = m_weatherCounter;
}