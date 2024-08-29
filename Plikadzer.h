#pragma once
#include "MenedzerHasel.h"
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <windows.h>

class Plikadzer
{

public:

	MenedzerHasel* haslaa;
	char tajmstamp[10];
	Plikadzer(MenedzerHasel* haslaa);
	void odplikuj(vector<string> &kategorie);
	void zaplikuj();
};

