#pragma once
#include "GameManager.h"
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
	char getCharInput() { return charInput; }
};

