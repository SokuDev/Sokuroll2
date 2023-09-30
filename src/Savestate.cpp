//
// Created by PC_volt on 30/09/2023.
//

#include "Savestate.hpp"

#include <string>

Savestate::Savestate()
{
    readFrame();
    readInputs();
    readWeather();
}

void Savestate::readFrame()
{
    SokuLib::BattleManager battleManager = SokuLib::getBattleMgr();
    m_frame = battleManager.frameCount;
}

void Savestate::readInputs()
{
    SokuLib::BattleManager battleManager = SokuLib::getBattleMgr();
    PlayersInputs *playersInputs = new PlayersInputs();
    playersInputs->inputsP1 = battleManager.leftCharacterManager.keyMap;
    playersInputs->inputsP2 = battleManager.rightCharacterManager.keyMap;
}

void Savestate::readWeather()
{
    m_weather = SokuLib::activeWeather;
    m_weatherDisplayed = SokuLib::displayedWeather;
    m_weatherCounter = SokuLib::weatherCounter;
}