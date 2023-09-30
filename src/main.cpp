//
// Created by PC_volt on 17/07/2023
//

#include <SokuLib.hpp>
#include <iostream>

static bool init = false;

static int (SokuLib::BattleManager::*ogBattleMgrOnProcess)();

static void (SokuLib::BattleManager::*ogBattleMgrOnRender)();

static SokuLib::DrawUtils::Sprite text;
static SokuLib::SWRFont font;

namespace
{
    SokuLib::KeyInput readCharacterInputs(SokuLib::CharacterManager &characterManager)
    {
        return characterManager.keyMap;
    }
}

int __fastcall CBattleManager_OnRender(SokuLib::BattleManager *This)
{
    (This->*ogBattleMgrOnRender)();
    text.draw();
    return 0;
}

/**
 * Holds the inputs of both players at a given moment.
 * Each member of KeyInput holds the time for which a button (directions A B C D Sw Sp) have been held.
 */
struct PlayersInputs
{
    SokuLib::KeyInput inputsP1;
    SokuLib::KeyInput inputsP2;
};

struct SaveState
{
    unsigned int frame;
    std::vector<PlayersInputs *> savedInputs;
};
SaveState savestate;

int __fastcall CBattleManager_OnProcess(SokuLib::BattleManager *This)
{
    if (SokuLib::mainMode == SokuLib::BATTLE_MODE_PRACTICE || SokuLib::mainMode == SokuLib::BATTLE_MODE_VSPLAYER ||
        SokuLib::mainMode == SokuLib::BATTLE_MODE_VSSERVER)
    {
        SokuLib::BattleManager battleManager = SokuLib::getBattleMgr();
        PlayersInputs *playersInputs = new PlayersInputs();
        playersInputs->inputsP1 = ::readCharacterInputs(battleManager.leftCharacterManager);
        playersInputs->inputsP2 = ::readCharacterInputs(battleManager.rightCharacterManager);

        savestate.savedInputs.push_back(playersInputs);
        savestate.frame = battleManager.frameCount;

        if (savestate.savedInputs.size() > 10) // magic number
        {
            savestate.savedInputs.erase(savestate.savedInputs.begin());
        }
    }

    return (This->*ogBattleMgrOnProcess)();
}

// -------------------------------------------------------------------------------------------------
extern "C" __declspec(dllexport) bool CheckVersion(const BYTE hash[16])
{
    return memcmp(hash, SokuLib::targetHash, sizeof(SokuLib::targetHash)) == 0;
}

extern "C" __declspec(dllexport) bool Initialize(HMODULE hMyModule, HMODULE hParentModule)
{
    DWORD old;

#ifdef _DEBUG
    FILE *_;

    AllocConsole();
    freopen_s(&_, "CONOUT$", "w", stdout);
    freopen_s(&_, "CONOUT$", "w", stderr);
#endif

    puts("Console Init");
    VirtualProtect((PVOID) RDATA_SECTION_OFFSET, RDATA_SECTION_SIZE, PAGE_EXECUTE_WRITECOPY, &old);
    ogBattleMgrOnRender = SokuLib::TamperDword(&SokuLib::VTable_BattleManager.onRender, CBattleManager_OnRender);
    ogBattleMgrOnProcess = SokuLib::TamperDword(&SokuLib::VTable_BattleManager.onProcess, CBattleManager_OnProcess);
    VirtualProtect((PVOID) RDATA_SECTION_OFFSET, RDATA_SECTION_SIZE, old, &old);

    VirtualProtect((PVOID) TEXT_SECTION_OFFSET, TEXT_SECTION_SIZE, PAGE_EXECUTE_WRITECOPY, &old);
    //original_onHit = SokuLib::union_cast<int (SokuLib::CharacterManager::*)(int)>(SokuLib::TamperNearJmpOpr(0x47c5a9, reinterpret_cast<DWORD>(isHit)));
    VirtualProtect((PVOID) TEXT_SECTION_OFFSET, TEXT_SECTION_SIZE, old, &old);

    FlushInstructionCache(GetCurrentProcess(), nullptr, 0);
    return true;
}

extern "C" int APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved)
{
    return TRUE;
}

extern "C" __declspec(dllexport) int getPriority()
{
    return 0;
}