#pragma once
#include "Haslo.h"
#include <algorithm>

using namespace std;

class MenedzerHasel
{

private:

	vector<Haslo*> tab;

public:

	void zaszyfruj();
	void odszyfruj();
	void dodaj(Haslo* h);
	void usun(const int i);
	void usuwaniePoKategorii(const string kategoria);
	void usunKategorie(vector<string>& kategorie, const string kategoriaDoUsuniecia);
	void wypisz();
	vector<Haslo*> wyszukaj(const string linijka);
	void wyszukajWypisz(const string linijka);
	void sortuj(const int kolumna);
	void sortujWiele(const string ciag);
	void edytuj(const string wyszukajka, const int kolumna, const string zamieniajka);
	void wyszukajUsun(const string linijka);
	vector<Haslo*> pobierzHasla();
	bool advancedSzukanko(const string slowo1, const string slowo2);

};

