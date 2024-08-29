#include "Plikadzer.h"

Plikadzer::Plikadzer(MenedzerHasel* haslaa)
{

	this->haslaa = haslaa;

}

/*DEFINICJA vector<string> list_files(const char* path) -> vector<string>
Metoda sluzy do zwrocenia wektora z wszystkimi plikami, okreslonymi przez path

Args:
	path (const char*) : sciezka folderu, z ktorego wypisujemy i zpisujemy nazwy plikow

Returns:
	vector<string> : lista plikow spelniajaca wymagania path*/
vector<string> list_files(const char* path)
{
	vector<string> listaPlikow;
	int i = 1;
    WIN32_FIND_DATAA data;
    HANDLE hFind;

    hFind = FindFirstFileA(path, &data);
    if (hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
			listaPlikow.push_back(data.cFileName);
            std::cout << i << ". " << data.cFileName << std::endl;
			i++;
        } while (FindNextFileA(hFind, &data));
        FindClose(hFind);
    }
	return listaPlikow;
}

/*DEFINICJA Plikadzer::odplikuj(vector<string> &kategorie) -> void
Funkcja sluzy przekazania danych z wybranego pliku do programu

Args:
	&kategorie (vector<string>) : wektor z kategoriami hasel

Returns:
	brak*/
void Plikadzer::odplikuj(vector<string> &kategorie)
{

	string sciezka;
	vector<string> listaPlikow;
	cout << endl << "Czy chcesz podac absolutna sciezke do pliku czy chcesz wybrac plik z folderu z programem?" << endl
		<< "(p - podaj sciezke , w - wybierz plik)" << endl;
	char wyborWczytywania;
	int numereczekPliku;
	bool wczytywanie = false;
	while (!wczytywanie)
	{
		cin >> wyborWczytywania;
		switch (wyborWczytywania)
		{
		case 'p':
			cout << endl << "Podaj sciezke do pliku:" << endl;
			cin >> sciezka;
			wczytywanie = true;
			break;
		case 'w':
		{
			cout << endl << "Dostepne pliki: " << endl;
			listaPlikow = list_files("./*.doc");
			cout << endl << "Wpisz pelna nazwe pliku do wczytania" << endl;
			bool wZakresie = false;
			do
			{
				cin >> numereczekPliku;
				wZakresie = !(numereczekPliku <= 0 || numereczekPliku > listaPlikow.size());
				if (!wZakresie)
				{
					cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:" << endl;
					cin.clear();
					cin.ignore(100, '\n');
				}
			} while (!wZakresie);
			sciezka = listaPlikow[numereczekPliku - 1];
			wczytywanie = true;
			break;
		}
		default:
			cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			break;
		}
	}

	fstream plik(sciezka, ios::in);
	char dane[255];

	plik.getline(dane, 255);
	Haslo* h = new Haslo(dane);

	string s = h->login;
	string delimiter = ":";
	string token = s.substr(0, s.find(delimiter));
	strcat(tajmstamp, token.c_str());
	string token2 = s.substr(s.find(delimiter) + 1, s.length());
	strcpy(h->login, token2.c_str());
	strcat(tajmstamp, ":");
	s = h->nazwa;
	token = s.substr(0, s.find(delimiter));
	strcat(tajmstamp, token.c_str());
	token2 = s.substr(s.find(delimiter) + 1, s.length());
	strcpy(h->nazwa, token2.c_str());
	strcat(tajmstamp, ":");
	s = h->kategoria;
	token = s.substr(0, s.find(delimiter));
	strcat(tajmstamp, token.c_str());
	token2 = s.substr(s.find(delimiter) + 1, s.length());
	strcpy(h->kategoria, token2.c_str());

	system("cls");
	cout << "Ostatnia proba odszyfrowania pliku miala miejsce o godzinie: " << tajmstamp << endl;

	haslaa->dodaj(h);

	kategorie.push_back(h->kategoria);

	while (plik.getline(dane, 255))
	{
		h = new Haslo(dane);
		haslaa->dodaj(h);
		bool czyNalezy = false;

		for (size_t i = 0; i < kategorie.size(); i++)
		{
			
			if (kategorie[i] == h->kategoria)
			{

				czyNalezy = true;
				break;
			
			}

		}

		if (!czyNalezy)
		{

			kategorie.push_back(h->kategoria);

		}

	}

	//oddzielne odszyfrowywanie kategorii
	for (size_t i = 0; i < kategorie.size(); i++)
	{
		for (int j = 0; j < kategorie[i].size(); j++) {

			kategorie[i][j] = kategorie[i][j] - 1;

		}
	}
	plik.close();
	zaplikuj();
	haslaa->odszyfruj();

}

/*DEFINICJA Plikadzer::zaplikuj() -> void
Funkcja sluzy przekazania danych z programu do pliku

Args:
	brak

Returns:
	brak*/
void Plikadzer::zaplikuj()
{
		
		using namespace std;
		using namespace std::chrono;
		system_clock::time_point now = system_clock::now();
		time_t tt = system_clock::to_time_t(now);
		tm local_tm = *localtime(&tt);
		strcpy(tajmstamp, "");
		strcat(tajmstamp, to_string(local_tm.tm_hour).c_str());
		strcat(tajmstamp, ":");
		strcat(tajmstamp, to_string(local_tm.tm_min).c_str());
		strcat(tajmstamp, ":");
		strcat(tajmstamp, to_string(local_tm.tm_sec).c_str());

		fstream plik("lista_zakupow.doc", ios::out);
		char dane[255];
		
		vector<Haslo*> tab = haslaa->pobierzHasla();

		plik << local_tm.tm_min << ':';
		plik << tab[0]->nazwa << ' ';
		plik << tab[0]->haslo << ' ';
		plik << local_tm.tm_sec << ':';
		plik << tab[0]->kategoria << ' ';
		plik << tab[0]->strona << ' ';
		plik << local_tm.tm_hour << ':';
		plik << tab[0]->login << '\n';

		for (size_t i = 1; i < tab.size(); i++)
		{

			plik << tab[i]->nazwa << ' ';
			plik << tab[i]->haslo << ' ';
			plik << tab[i]->kategoria << ' ';
			plik << tab[i]->strona << ' ';
			plik << tab[i]->login << '\n';

		}

		plik.close();

}