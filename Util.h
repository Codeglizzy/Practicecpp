#pragma once
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <cctype>
#include <vector>
using namespace std;

//Quick solution to grab inputs
class Utility
{
private:
	int numericInput;
	double floatingPointInput;
	string stringInput;
	char charInput;

public:
	string PromptString()
	{
		cin >> stringInput;
		return stringInput;
	}

	int PromptInt()
	{
		cin >> numericInput;
		return numericInput;
	}

	double PromptDouble()
	{
		cin >> floatingPointInput;
		return floatingPointInput;
	}

	char PromptChar()
	{
		cin >> charInput;
		return charInput;
	}


	int getPrevIntInput() { return numericInput; }
	double getPrevDoubleInput() { return floatingPointInput; }
	string getPrevStringInput() { return stringInput; }
	char getPrevCharInput() { return charInput; }
};

