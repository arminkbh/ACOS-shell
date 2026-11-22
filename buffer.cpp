/*
Yo armin här, jag ska försöka göra det här utan AI. 
Jag kommer dock lägga till en massa comments eftersom min code är ugly af
*/

#include <windows.h>
#include <iostream>
#include <map>
#include <cwctype>
#include "acosAttributes.h"
#include "functions.h"


using namespace std;

//Get input and output handles
HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

std::wstring input; //Vi kör widestring eftersom vi använder wide funktioner (WriteConsoleW, ReadConsoleW, etc.)

int main() {
	wchar_t buffer[256]; //Make a buffer for max 256
	DWORD readChars;
	
	PlayIntro(L"");
	
	while (true) {
		SetConsoleTextAttribute(hOutput, FOREGROUND_RED); //Sets text to red for the acos > input effect you know
	
		WriteConsoleW(hOutput, ACOS_INPUT_ATLAS, 3, nullptr, nullptr); //The symbol \u795E means god in chinese (cewl)
	
		SetConsoleTextAttribute(hOutput, FOREGROUND_WHITE); //Makes user input white you feel me
		
		if (!ReadConsoleW(hInput, buffer, 255, &readChars, nullptr)) break;
		input.assign(buffer, readChars);
		//input kommer vara [string] \r \n, därmed måste vi ta bort \r och \n:
		while (!input.empty() && (input.back() == L'\r' || input.back() == L'\n')) {
			input.pop_back();
		}

		if (input == L"exit") break;
		std::wstring firstWordInput;
		std::wstring oldInput = input; //Spara gamla inputen
		//Definiera firstwordinput
		for (int i = 0; i < input.size(); ++i) {
			if (input[i] != L' ') {
				firstWordInput.push_back(towlower(input[i]));
			}
			else break;
		}
		input.erase(0, firstWordInput.size() + 1);

		//Check if the command exists, return error if not, and runs command if
		if (functionsMap.find(firstWordInput) != functionsMap.end()) functionsMap[firstWordInput](input);
		else {
			SetConsoleTextAttribute(hOutput, FOREGROUND_RED);
			std::wcerr << L"Command " << firstWordInput << L" does not exist\n";
		}
	}
	return 0;
}