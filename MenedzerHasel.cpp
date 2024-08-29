#include "MenedzerHasel.h"

/*DEFINICJA porownajLiterki(const char* x, const char* y) -> bool
Metoda porownuje po jednej literze z dwoch slow, sprawdzajac ktore z nich jest pierwsze w kolejnosci alfabetycznej
Uzywana przy sortowaniu

Args:
	x (const char*) : litera z pierwszego slowa, wywolywana przez wskaznik
	y (const char*) : litera z drugiego slowa, wywolywana przez wskaznik

Returns:
	bool : czy litera z pierwszego slowa jest wczesniej w alfabecie niz z drugiego slowa*/
bool porownajLiterki(const char* x, const char* y) {

	int xlen = strlen(x);
	int ylen = strlen(y);
	int krotsze;

	if (xlen < ylen) {

		krotsze = xlen;

	}
	else {

		krotsze = ylen;

	}
	int i = 0;

	while (x[i] == y[i] && i < krotsze) {

		i++;

	}

	return x[i] < y[i];

}

/*DEFINICJA MenedzerHasel::zaszyfruj() -> void
Metoda szyfruje hasla zawarte w programie, aby zgrac je potem do pliku

Args:
	brak

Returns:
	brak*/
void MenedzerHasel::zaszyfruj()
{

	for (int i = 0; i < tab.size(); i++)
	{

		tab[i]->zaszyfruj();

	}

}

/*DEFINICJA MenedzerHasel::odszyfruj() -> void
Funkcja odszyfrowuje hasla zawarte z podanego przez uzytkownika pliku, aby korzystac z nich w programie

Args:
	brak

Returns:
	brak*/
void MenedzerHasel::odszyfruj()
{

	for (int i = 0; i < tab.size(); i++)
	{

		tab[i]->odszyfruj();

	}

}

/*DEFINICJA MenedzerHasel::dodaj(Haslo* h) -> void
Funkcja dodaje utworzony przez uzytkownika haslo do glownego wektora z haslami

Args:
	h (Haslo*) : obiekt klasy Haslo utworzony przez uzytkownika, do dodania do reszty hasel

Returns:
	brak*/
void MenedzerHasel::dodaj(Haslo* h) {

	tab.push_back(h);

}

/*DEFINICJA MenedzerHasel::usun(const int i) -> void
Funkcja usuwa podane haslo z glownego wektora z haslami

Args:
	i (const int) : indeks hasla, ktore uzytkownik chce usunac

Returns:
	brak*/
void MenedzerHasel::usun(const int i) {

	tab.erase(tab.begin() + i - 1);

}

/*DEFINICJA MenedzerHasel::usuwaniePoKategorii(const string kategoria) -> void
Funkcja usuwa wszystkie hasla z wybranej przez uzytkownika kategorii

Args:
	kategoria (const string) : nazwa kategorii, z ktorej chcemy usunac hasla

Returns:
	brak*/
void MenedzerHasel::usuwaniePoKategorii(const string kategoria) {
	for (size_t i = 0; i < tab.size(); i++)
	{
		if (tab[i]->kategoria == kategoria)
		{
			tab.erase(tab.begin() + i);
			i--;
		}
	}

}

/*DEFINICJA MenedzerHasel::usunKategorie(vector<string> &kategorie, const string kategoriaDoUsuniecia) -> void
Funkcja usuwa wybrana przez uzytkownika kategorie z wektora zawierajacego wszystkie kategorie

Args:
	&kategorie (vector<string>) : glowny wektor zawierajacy wszystkie istniejace kategorie, wywolywany przez referencje
	kategoriaDoUsuniecia (const string) : nazwa kategorii, która ma zostaæ usuniêta

Returns:
	brak*/
void MenedzerHasel::usunKategorie(vector<string> &kategorie, const string kategoriaDoUsuniecia) {

	for (size_t i = 0; i < kategorie.size(); i++)
	{
		if (kategorie[i] == kategoriaDoUsuniecia) 
		{
			kategorie.erase(kategorie.begin() + i);
			break;
		}
	}

}

/*DEFINICJA MenedzerHasel::wypisz() -> void
Funkcja sluzy do wypisywania hasel

Args:
	brak

Returns:
	brak*/
void MenedzerHasel::wypisz() {
	
	for (int i = 0; i < tab.size(); i++)
	{

		tab[i]->wypisz();

	}
	cout << endl;

}

/*DEFINICJA MenedzerHasel::wyszukaj(const string linijka) -> vector<Haslo*>
Funkcja sluzy do wyszukiwania hasel

Args:
	linijka (const string) : linijka tekstu zawierajaca tekst, ktory wyszukujemy oraz kolumne, z ktorej ten tekst wyszukujemy

Returns:
	vector<Haslo*> : wektor zawierajacy wyszukane hasla*/
vector<Haslo*> MenedzerHasel::wyszukaj(const string linijka) {

	int  kolumna;
	char szukaneSlowo[20];
	sscanf(linijka.c_str(), "%d %s", &kolumna, szukaneSlowo);

	vector<Haslo*> wyszukane;
	switch (kolumna)
	{
	case 1:
		for (size_t i = 0; i < tab.size(); i++)
		{
			if (advancedSzukanko(tab[i]->nazwa, szukaneSlowo)) {

				wyszukane.push_back(tab[i]);

			}
		}
		break;

	case 2:
		for (size_t i = 0; i < tab.size(); i++)
		{
			if (advancedSzukanko(tab[i]->haslo, szukaneSlowo)) {

				wyszukane.push_back(tab[i]);

			}
		}
		break;

	case 3:
		for (size_t i = 0; i < tab.size(); i++)
		{
			if (advancedSzukanko(tab[i]->kategoria, szukaneSlowo)) {

				wyszukane.push_back(tab[i]);

			}
		}
		break;

	case 4:
		for (size_t i = 0; i < tab.size(); i++)
		{
			if (advancedSzukanko(tab[i]->strona, szukaneSlowo)) {

				wyszukane.push_back(tab[i]);

			}
		}
		break;

	case 5:
		for (size_t i = 0; i < tab.size(); i++)
		{
			if (advancedSzukanko(tab[i]->login, szukaneSlowo)) {

				wyszukane.push_back(tab[i]);

			}
		}
		break;

	default:
		cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie\n";
		cin.clear();
		cin.ignore(100, '\n');
		break;

	}
	return wyszukane;
}

/*DEFINICJA MenedzerHasel::wyszukajWypisz(const string linijka) -> void
Funkcja, ktora, za pomoca funkcji wyszukaj(), najpierw wyszukuje hasla, a potem je wypisuje

Args:
	linijka (const string) : linijka tekstu zawierajaca tekst, ktory wyszukujemy oraz kolumne, z ktorej ten tekst wyszukujemy

Returns:
	brak*/
void MenedzerHasel::wyszukajWypisz(const string linijka) {

	vector<Haslo*> wyszukane = wyszukaj(linijka);
	for (size_t i = 0; i < wyszukane.size(); i++)
	{
		wyszukane[i]->wypisz();
	}
	cout << "Wcisnij Enter aby kontynuowac" << endl;
	cin.ignore();
	system("cls");
}

/*DEFINICJA MenedzerHasel::sortuj(const int kolumna) -> void
Funkcja sortuje jeden raz hasla wedlug wybranej kolumny

Args:
	kolumna (const int) : wybrana przez uzytkownika kolumna, wedlug ktorej maja zostac posortowane hasla

Returns:
	brak*/
void MenedzerHasel::sortuj(const int kolumna) {

	switch (kolumna)
	{
	case 1:
		sort(tab.begin(), tab.end(),
			[](const Haslo* x, const Haslo* y) {

				return porownajLiterki(x->nazwa, y->nazwa);
			});
		break;

	case 2:
		sort(tab.begin(), tab.end(),
			[](const Haslo* x, const Haslo* y) {

				return porownajLiterki(x->haslo, y->haslo);
			});
		break;

	case 3:
		sort(tab.begin(), tab.end(),
			[](const Haslo* x, const Haslo* y) {

				return porownajLiterki(x->kategoria, y->kategoria);
			});
		break;

	case 4:
		sort(tab.begin(), tab.end(),
			[](const Haslo* x, const Haslo* y) {

				return porownajLiterki(x->strona, y->strona);
			});
		break;

	case 5:
		sort(tab.begin(), tab.end(),
			[](const Haslo* x, const Haslo* y) {

				return porownajLiterki(x->login, y->login);
			});
		break;

	default:
		cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie\n";
		cin.clear();
		cin.ignore(100, '\n');
		break;
	}

}

/*DEFINICJA MenedzerHasel::sortujWiele(const string ciag) -> void
Funkcja, ktora, za pomoca funkcji sortuj(), sortuje hasla na wielu kolumnach

Args:
	ciag (const string) : ciag cyfr, oznaczajacych kolumny, po ktorych maja zostac posortowane hasla

Returns:
	brak*/
void MenedzerHasel::sortujWiele(const string ciag) {

	for (int i = ciag.size() - 1; i >= 0; i--)
	{

		sortuj(ciag[i] - '0');

	}

}

/*DEFINICJA MenedzerHasel::edytuj(const string wyszukajka, const int kolumna, const string zamieniajka) -> void
Funkcja majaca na celu edycje kolumny jednego z hasel istniejacych w programie

Args:
	wyszukajka (const string) : linijka tekstu zawierajaca wyszukiwana fraze oraz kolumne, z ktorej nalezy dokonac wyszukiwania
	kolumna (const int) : kolumna, z ktorej nalezy dokonac wyszukiwania
	zamieniajka (const string) : fraza, na ktora chcemy zamienic wybrany wpis

Returns:
	brak*/
void MenedzerHasel::edytuj(const string wyszukajka, const int kolumna, const string zamieniajka) {

	vector<Haslo*> wyszukane = wyszukaj(wyszukajka);

	for (size_t i = 0; i < wyszukane.size(); i++)
	{
		cout << i + 1 << ". ";
		wyszukane[i]->wypisz();
	}

	bool wyborWZakresie = false;	
	cout << endl << "Wybierz jedna z powyzszych opcji wpisujac jej numer" << endl;
	cin.clear();
	int wybor;

	bool wybieranie = false;
	bool fail = false;
	while (!wybieranie) {
		do
		{
			cin >> wybor; 
			if (wybor > 0 && wybor <= wyszukane.size())
			{
				wyborWZakresie = true;
			}
			else
			{
				cout << "Error - wpisana wartosc jest poza zakresem, sprobuj ponownie\n";
				cin.clear();
				cin.ignore(100, '\n');
			}
		} while (!wyborWZakresie);
		switch (kolumna)
		{
		case 1:

			strcpy(wyszukane[wybor - 1]->nazwa, zamieniajka.c_str());
			wybieranie = true;
			break;

		case 2:

			strcpy(wyszukane[wybor - 1]->haslo, zamieniajka.c_str());
			wybieranie = true;
			break;

		case 3:

			strcpy(wyszukane[wybor - 1]->kategoria, zamieniajka.c_str());
			wybieranie = true;
			break;

		case 4:

			strcpy(wyszukane[wybor - 1]->strona, zamieniajka.c_str());
			wybieranie = true;
			break;

		case 5:

			strcpy(wyszukane[wybor - 1]->strona, zamieniajka.c_str());
			wybieranie = true;
			break;

		default:
			cout << "Error - niepoprawna wartosc kolumny, wprowadz ponownie\n";
			cout << "Wcisnij Enter aby kontynuowac" << endl;
			cin.ignore();
			wybieranie = true;
			fail = true;
			break;

		}
	}
	if (fail)
	{
		system("cls");
		return;
	}
	cout << endl << "Wartosc zostala pomyslnie edytowana" << endl;
	cout << "Wcisnij Enter aby kontynuowac" << endl;
	cin.ignore(100, '\n');
	cin.ignore();
	system("cls");
}

/*DEFINICJA MenedzerHasel::wyszukajUsun(const string linijka) -> void
Funkcja, ktora wyszukuje a nastepnie pozwala na usuniecie wybranego hasla, moze byc wywolywana rekursyjnie 

Args:
	linijka (const string) : linijka tekstu zawierajaca wyszukiwana fraze oraz kolumne, z ktorej nalezy dokonac wyszukiwania

Returns:
	brak*/
void MenedzerHasel::wyszukajUsun(const string linijka) {

	vector<Haslo*> wyszukane = wyszukaj(linijka);

	for (size_t i = 0; i < wyszukane.size(); i++)
	{
		cout << i + 1 << ". ";
		wyszukane[i]->wypisz();
	}
	cout << endl << wyszukane.size() + 1 << ". Anuluj wybor" << endl;
	cout << endl << "Wybierz opcje do usuniecia z powyzszych wpisujac jej numer" << endl;

	int wybor;
	bool done = false;
	while (!done)
	{
		cin >> wybor;
		if (wybor == wyszukane.size() + 1)
		{
			break;
		} 
		if (wybor >= 1 && wybor <= wyszukane.size())
		{
			for (size_t i = 0; i < tab.size(); i++)
			{
				if (wyszukane[wybor - 1] == tab[i])
				{
					bool areYouSure = false, zlyWybor = true;
					char  wyborFinal;
					while (!areYouSure)
					{
						if (zlyWybor)
						{
							cout << endl << "Czy na pewno? Spowoduje nieodwracalna utrate wybranego wpisu z haslem (t - tak , n - nie)" << endl;
						}
						cin >> wyborFinal;
						switch (wyborFinal)
						{
						case 't':
						{
							areYouSure = true;
							usun(i);
							done = true;
							cout << endl << "Haslo zostalo usuniete\n"
								<< "Czy chcesz usunac jeszcze jedno haslo z wyzej wymienionych? (t - tak , n - nie)" << endl;
							bool czyPonowic = false;
							while (!czyPonowic)
							{
								cin >> wyborFinal;
								switch (wyborFinal)
								{
								case 't':
									wyszukajUsun(linijka);
									areYouSure = true;
									done = true;
									czyPonowic = true;
									break;
								case 'n':
									areYouSure = true;
									done = true;
									czyPonowic = true;
									system("cls");
									break;
								default:
									cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:\n";
									cin.clear();
									cin.ignore(100, '\n');
									break;
								}
							}
							break;
						}
						case 'n':
							cout << endl << "Haslo NIE zostalo usuniete\n"
								<< "Wcisnij Enter aby kontynuowac" << endl;
							cin.ignore(100, '\n');
							cin.ignore();
							system("cls");
							areYouSure = true;
							done = true;
							break;
						default:
							zlyWybor = true;
							cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:\n";
							cin.clear();
							cin.ignore(100, '\n');
							break;
						}
					}
				}
			}
		}
		else
		{
			cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
	}

}

/*DEFINICJA MenedzerHasel::pobierzHasla() -> vector<Haslo*>
Funkcja, ktora zwraca wszystkie hasla istniejace w programie

Args:
	brak

Returns:
	vector<Haslo*> : wektor zawierajacy wszystkie hasla istniejace w programie*/
vector<Haslo*> MenedzerHasel::pobierzHasla()
{

	return tab;

}

/*DEFINICJA MenedzerHasel::advancedSzukanko(const string slowo1, const string slowo2) -> bool
Funkcja, ktora sprawdza, czy slowo2 jest zawarte w slowo1

Args:
	slowo1 (const string) : glowne slowo, w ktorym wyszukujemy mniejsze slowo
	slowo2 (const string) : mniejsze slowo, ktorego szukamy w glownym slowie

Returns:
	bool : czy mniejsze slowo jest zawarte w wiekszym slowie*/
bool MenedzerHasel::advancedSzukanko(const string slowo1, const string slowo2) {
	bool zawiera = false;
	int i = 0;
	while (i < slowo1.size() && !zawiera)
	{
		if (slowo1[i] == slowo2[0])
		{
			int j = 0;
			zawiera = true;
			while (j < slowo2.size() && zawiera)
			{
				if (slowo1[i] != slowo2[j])
				{
					zawiera = false;
					i--;
				}
				else
				{
					i++;
					j++;
				}
			}
		}

		i++;
	}
	return zawiera;
}