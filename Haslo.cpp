#include "Haslo.h"

Haslo::Haslo(string linijka) {

    sscanf(linijka.c_str(), "%s %s %s %s %s", nazwa, haslo, kategoria, strona, login);
    
}

/*DEFINICJA Haslo::wypisz() -> void
Funkcja sluzaca do wypisywania pojedynczego hasla

Args:
    brak

Returns:
    brak*/
void Haslo::wypisz() {

    cout << "Nazwa: " << nazwa
        << ", Haslo: " << haslo
        << ", Kategoria: " << kategoria
        << ", Strona: " << strona
        << ", Login: " << login
        << endl;

}

/*DEFINICJA Haslo::odszyfruj(char* tekst) -> void
Funkcja, ktora przyjmuje wskaznik na pojedyncza kolumne z jednego hasla, aby ja odszyfrowac

Args:
    tekst (char*) : wskaznik na pojedyncza kolumne hasla

Returns:
    brak*/
void Haslo::odszyfruj(char* tekst) {

    for (int i = 0; i < strlen(tekst); i++) {

        tekst[i] = tekst[i] - 1;

    }

}

/*DEFINICJA Haslo::odszyfruj() -> void
Funkcja sluzaca do odszyfrowania pojedynczego hasla

Args:
    brak

Returns:
    brak*/
void Haslo::odszyfruj() {

    odszyfruj(nazwa);
    odszyfruj(haslo);
    odszyfruj(kategoria);
    odszyfruj(strona);
    odszyfruj(login);

}

/*DEFINICJA Haslo::odszyfruj(char* tekst) -> void
Funkcja, ktora przyjmuje wskaznik na pojedyncza kolumne z jednego hasla, aby ja zaszyfrowac

Args:
    tekst (char*) : wskaznik na pojedyncza kolumne hasla

Returns:
    brak*/
void Haslo::zaszyfruj(char* tekst) {

    for (int i = 0; i < strlen(tekst); i++) {

        tekst[i] = tekst[i] + 1;

    }

}

/*DEFINICJA Haslo::odszyfruj() -> void
Funkcja sluzaca do odszyfrowania pojedynczego hasla

Args:
    brak

Returns:
    brak*/
void Haslo::zaszyfruj() {

    zaszyfruj(nazwa);
    zaszyfruj(haslo);
    zaszyfruj(kategoria);
    zaszyfruj(strona);
    zaszyfruj(login);

}