/*
OBS: Jag använder en map för att få tag på alla funktioner, men det betyder att
alla funktioner måste heta [funktionsnamn][suffix] eller [prefix][funktionsnamn]

Vi kommer använda suffixet _UIF__
(meaning user input function)
*/


#include <map>
#include <string>
#include <fstream>
#include <iostream>

#pragma once
#ifndef ACOS_FUNCTIONS_HPP


extern std::map<std::wstring, void(*)(std::wstring)> functionsMap;

//Funktions definitioner

void echo_UIF__(std::wstring); //echo function
void encrypt_UIF__(std::wstring); //encryption function
void decrypt_UIF__(std::wstring); //decryption function

void PlayIntro(std::wstring);

//Funktioner i map:


#define ACOS_FUNCTIONS_HPP
#endif