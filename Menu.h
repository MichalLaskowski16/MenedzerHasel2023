#pragma once
#include "Plikadzer.h"
#include <random>

class Menu
{
	public:
		void menu();
		void menuLadowanie();

		bool czyWielka(char literka);
		bool czyCyfra(char literka);
		bool czyZnakSpecjalny(char literka);

		void dodajKategorie(vector<string> &kategorie);
		string czyWZakresie(string linijka);
		char dejLiterke();
		char dejCyferke();
		char dejBigLiterke();
		char dejZnak();

		void dodajHaslo();
};

