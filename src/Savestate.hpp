//
// Created by PC_volt on 30/09/2023.
//

#ifndef SOKULIB_SAVESTATE_HPP
#define SOKULIB_SAVESTATE_HPP

#include <SokuLib.hpp>

#include <vector>

/**
 * Contains the inputs of both players at a given moment.
 */
struct PlayersInputs
{
	SokuLib::KeyInput inputsP1;
	SokuLib::KeyInput inputsP2;
};

/**
 * A Savestate is the frame with all the data to be recorded, so that it can be loaded after.
 */
class Savestate
{
public:
	Savestate();

	void readCamera();
	void readInputs(const SokuLib::BattleManager &battleManager);
	void readFrame(const SokuLib::BattleManager &battleManager);
	void readWeather();
	void readBattleManager(const SokuLib::BattleManager &battleManager);

	const unsigned int getFrame() const;

	void restore();

private:
	unsigned int m_frame; // Gets reset to 0 when the fight scene changes (see struct BattleManager_VTABLE)
	SokuLib::Camera m_camera;
	PlayersInputs *m_savedInputs;
	SokuLib::Weather m_weather;
	SokuLib::Weather m_weatherDisplayed;
	unsigned short m_weatherCounter;
};


#endif //SOKULIB_SAVESTATE_HPP
