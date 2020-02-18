// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <memory>
#include <stdio.h>
#include <string>
#include <vector>

/* A Basic Entry Point */

void HookPanoramaUI(const std::vector<std::pair<std::string, std::string>>& FilesToInject);

DWORD __stdcall Run(LPVOID)
{
#ifdef _DEBUG
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);
	freopen("CONOUT$", "w", stderr);
	SetConsoleTitleA("Debug Console");
#endif
	// List Files to inject into panorama.
	// Note Format is { "Place on your disk", "Place in Panorama Zip"  }
	// Also note there is likely a much better way todo this - BUUUUUUUUUUT
	// thats upto you guys im too tired and im done with this
	std::vector<std::pair<std::string, std::string>> FilesToInject{
		{ "C:\\csgo\\panoramadump\\panorama\\layout\\mainmenu.xml", "panorama\\layout\\mainmenu.xml" } // Just an example of how to use
	};

	// Hook Panprama
	HookPanoramaUI(FilesToInject);
	
	return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
	if (DLL_PROCESS_ATTACH)
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Run, 0, 0, 0);
    }

    return TRUE;
}

