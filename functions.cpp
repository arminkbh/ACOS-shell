#include "functions.h"
#include <Windows.h>

extern HANDLE hOutput;

std::map<std::wstring, void(*)(std::wstring)> functionsMap = {
	{L"echo", echo_UIF__},
	{L"intro", PlayIntro}
};


void echo_UIF__(std::wstring wstr) {
	if (!WriteConsoleW(hOutput, wstr.c_str(), wstr.size(), nullptr, nullptr)) std::cout << "Wrong with echo function!";
	std::cout << std::endl;
}

void PlayIntro(std::wstring NOTNEEDED) {
	unsigned int oldconsoleCP = GetConsoleOutputCP();
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleTextAttribute(hOutput, FOREGROUND_RED);
	
	std::wifstream introFile("other/asciiIntro.txt");
	std::wstring currentLine;
	while (std::getline(introFile, currentLine)) {
		std::wcout << currentLine << L'\n';
	}
	SetConsoleOutputCP(oldconsoleCP);
}

//Function to set variable in variablemanagement.cpp