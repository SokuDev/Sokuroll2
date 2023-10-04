//
// Created by PC_volt on 30/09/2023.
//

#include "Savestate.hpp"

#include <functional>

namespace
{
	void placeTrampoline(std::function<void(unsigned int, unsigned int)> callback, unsigned int size, unsigned int
	address)
	{
		callback(size, address);
	}

	void customHeapFree(unsigned int size, unsigned int address)
	{

	}

	void customHeapAlloc(unsigned int size, unsigned int address)
	{

	}
}

Savestate::Savestate()
{
	SokuLib::BattleManager battleManager = SokuLib::getBattleMgr();
	readCamera();
	readFrame(battleManager);
	readInputs(battleManager);
	readWeather();
	readBattleManager(battleManager);
}

void Savestate::readFrame(const SokuLib::BattleManager &battleManager)
{
	m_frame = battleManager.frameCount;
}

void Savestate::readCamera()
{
	m_camera = SokuLib::camera;
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
	SokuLib::camera = m_camera;

	SokuLib::BattleManager battleManager = SokuLib::getBattleMgr();
	battleManager.frameCount = m_frame;

	battleManager.leftCharacterManager.keyMap = m_savedInputs->inputsP1;
	battleManager.rightCharacterManager.keyMap = m_savedInputs->inputsP2;

	SokuLib::activeWeather = m_weather;
	SokuLib::displayedWeather = m_weatherDisplayed;
	SokuLib::weatherCounter = m_weatherCounter;
}