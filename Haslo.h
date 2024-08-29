#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Haslo {

public:
    char nazwa[21], haslo[21], kategoria[21], strona[21], login[21];

    Haslo(string linijka);
    void wypisz();
    void odszyfruj(char* tekst);
    void odszyfruj();
    void zaszyfruj(char* tekst);
    void zaszyfruj();

};