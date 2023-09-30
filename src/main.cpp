//
// Created by PC_volt on 17/07/2023
//

#include <SokuLib.hpp>

#include "SavestateStack.hpp"

#include <iostream>

static bool init = false;

static int (SokuLib::BattleManager::*ogBattleMgrOnProcess)();

static void (SokuLib::BattleManager::*ogBattleMgrOnRender)();

int __fastcall CBattleManager_OnRender(SokuLib::BattleManager *This)
{
    (This->*ogBattleMgrOnRender)();
    return 0;
}

SavestateStack savestateStack;

int __fastcall CBattleManager_OnProcess(SokuLib::BattleManager *This)
{
    if (SokuLib::mainMode == SokuLib::BATTLE_MODE_PRACTICE || SokuLib::mainMode == SokuLib::BATTLE_MODE_VSPLAYER ||
        SokuLib::mainMode == SokuLib::BATTLE_MODE_VSSERVER)
    {
        savestateStack.addSavestate();
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