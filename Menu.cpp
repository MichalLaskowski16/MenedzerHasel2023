#include "Menu.h"

vector <string> kategorie;
MenedzerHasel* haslaa = new MenedzerHasel();
Plikadzer* plikachu = new Plikadzer(haslaa);

/*DEFINICJA Menu::menu() -> void
Glowna funkcja programu, menu, w ktorym wybierane sa miedzy innymi opcje pozwalajace edytowac i przegladac swoje hasla

Args:
    brak

Returns:
    brak*/
void Menu::menu() {
    srand(time(0));

    char wyborMenu;
    bool goodbye = false;
    bool zlyWybor = false;
    while (!goodbye)
    {

        if (!zlyWybor)
        {
            cout << endl << "Wybierz, z ktorej opcji chcesz skorzystac, wpisujac cyfre umieszczona obok niej:\n\n"
                << "1. Wyszukaj hasla wedlug wybranych parametrow\n"
                << "2. Sortuj hasla wedlug wybranych parametrow\n"
                << "3. Dodaj nowe haslo\n"
                << "4. Edytuj istniejace haslo\n"
                << "5. Usun istniejace haslo/hasla\n"
                << "6. Dodaj kategorie dla hasel\n"
                << "7. Usun kategorie hasel\n"
                << "8. Wyjdz z programu i zapisz dane\n\n";
        }

        cin >> wyborMenu;
        switch (wyborMenu)
        {
            //WYSZUKIWANIE HASEL
        case '1':
        {
            if (haslaa->pobierzHasla().size() == 0)
            {
                cout << endl << "Brak hasel w programie" << endl
                    << "Wcisnij Enter aby kontynuowac" << endl;
                cin.ignore(100, '\n');
                cin.ignore();
                system("cls");
                break;
            }
            if (haslaa == nullptr)
            {
                cout << endl << "Aby wyswietlic hasla, musisz najpierw dodac co najmniej jedno" << endl;
                break;
            }
            zlyWybor = false;
            cout << endl << "Podaj numer kolumny z ktorej chcesz wyszukac haslo (1 - Nazwa, 2 - Haslo, 3 - Kategoria, 4 - Strona, 5 - Login)\n"
                << "oraz wyszukiwana fraze, oddzielona od numeru spacja (przyklad:3 Rozrywka)\n"
                << "Wyszukiwana fraza moze byc jedynie fragmentem calego sformulowania, ale kolejnosc i wielkosc liter musza sie zgadzac\n"
                << "Aby anulowac wybrana opcje, podaj znak 'q'" << endl;
            string doWyszukania;
            cin.ignore(100, '\n');
            getline(cin, doWyszukania);
            if (doWyszukania == "q")
            {
                system("cls");
                break;
            }
            cout << endl;
            haslaa->wyszukajWypisz(doWyszukania);
            break;

        }
            //SORTOWANIE HASEL
        case '2':
        {
            if (haslaa->pobierzHasla().size() == 0)
            {
                cout << endl << "Brak hasel w programie" << endl
                    << "Wcisnij Enter aby kontynuowac" << endl;
                cin.ignore(100, '\n');
                cin.ignore();
                system("cls");
                break;
            }
            zlyWybor = false;
            cout << endl << "Podaj numery kolumn, w tej kolejnosci, w jakiej chcesz posortowac swoje hasla\n"
                << "(1 - Nazwa, 2 - Haslo, 3 - Kategoria, 4 - Strona, 5 - Login) (przyklad:31)\n"
                << "Aby anulowac wybrana opcje, podaj znak 'q'" << endl;
            string ciag;
            cin >> ciag;
            if (ciag == "q")
            {
                system("cls");
                break;
            }
            cout << endl;
            haslaa->sortujWiele(ciag);
            haslaa->wypisz();
            cout << "Wcisnij Enter aby kontynuowac" << endl;
            cin.ignore(100, '\n');
            cin.ignore();
            system("cls");
            break;
        }
            //DODAWANIE HASEL
        case '3':
        {
            dodajHaslo();
            break;
        }
            //EDYCJA HASEL
        case '4':
        {
            if (haslaa->pobierzHasla().size() == 0)
            {
                cout << endl << "Brak hasel w programie" << endl
                << "Wcisnij Enter aby kontynuowac" << endl;
                cin.ignore(100, '\n');
                cin.ignore();
                system("cls");
                break;
            }
            zlyWybor = false;
            cout << endl << "Podaj numer kolumny, z ktorej dane chcesz edytowac (1 - Nazwa, 2 - Haslo, 3 - Kategoria, 4 - Strona, 5 - Login)\n"
                << "Aby anulowac wybrana opcje, podaj znak 'q'" << endl;

            string wyszukajka, zamieniajka;
            cin.ignore(100, '\n');
            cin >> wyszukajka;
            if (wyszukajka == "q")
            {
                system("cls");
                break;
            }
            wyszukajka.push_back(' ');
            int kolumna;
            kolumna = wyszukajka[0] - '0';
            if (kolumna == 3)
            {
                cout << endl << "Wybierz nazwe kategorii, ktora ma zostac zmieniona, wpisujac jej numer\n"
                    << "W nastepnym kroku bedzie mozna wybrac dokladnie ktore z hasel ma zostac zmienione" << endl;
            
                cout << endl << "Dostepne kategorie to: " << endl;
                for (size_t i = 0; i < kategorie.size(); i++)
                {
                    cout << i + 1 << ". " << kategorie[i] << endl;
                }
                int wyborKategoria;
                bool czyKategoria = false;
                while (!czyKategoria) {                  

                    cin >> wyborKategoria;
                    for (int i = 1; i <= kategorie.size(); i++)
                    {
                        if (i == wyborKategoria) {

                            wyszukajka = wyszukajka + kategorie[i-1];
                            czyKategoria = true;
                            break;
                        }
                    }
                    if (!czyKategoria)
                    {
                        cout << "Error - niepoprawna kategoria, prosze wprowadzic ponownie:" << endl;
                        cin.clear();
                        cin.ignore(100, '\n');
                    }
                }  
                cout << endl << "Nastepnie wybierz nazwe kategorii, na ktora wpis z poprzedniej kategorii ma zostac zmieniony, wpisujac jej numer\n"
                    << "W nastepnym kroku bedzie mozna wybrac dokladnie ktory wpis w bazie hasel ma zostac zmieniony" << endl;
                cout << endl << "Dostepne kategorie to: " << endl;
                for (size_t i = 0; i < kategorie.size(); i++)
                {
                    cout << i + 1 << ". " << kategorie[i] << endl;
                }
                czyKategoria = false;
                while (!czyKategoria) {

                    cin >> wyborKategoria;
                    for (int i = 1; i <= kategorie.size(); i++)
                    {
                        if (i == wyborKategoria) {

                            zamieniajka = kategorie[i-1];
                            czyKategoria = true;
                            break;
                        }
                    }
                    if (!czyKategoria)
                    {
                        cout << "Error - niepoprawna kategoria, prosze wprowadzic ponownie:" << endl;
                        cin.clear();
                        cin.ignore(100, '\n');
                    }
                }
            }
            else
            {
                cout << endl << "Podaj wyszukiwana fraze, ktora zostanie poddana edycji (facebook.com)\n"
                    << "Wyszukiwana fraza moze byc jedynie fragmentem calego sformulowania, ale kolejnosc i wielkosc liter musza sie zgadzac" << endl;
                string temp;
                cin >> temp;
                wyszukajka = wyszukajka + temp;
                cout << endl << "Nastepnie podaj na co wyszukiwane slowo ma zostac zamienione (przyklad:mojaUlubionaStrona)\n"
                    << "W nastepnym kroku bedzie mozna wybrac dokladnie ktory wpis w bazie hasel ma zostac zmieniony" << endl;
                cin >> zamieniajka;
                zamieniajka = czyWZakresie(zamieniajka);
            }
            cout << endl;
            haslaa->edytuj(wyszukajka, kolumna, zamieniajka);
            system("cls");
            break;
        }
            //USUWANIE HASEL
        case '5':
        {
            if (haslaa->pobierzHasla().size() == 0)
            {
                cout << endl << "Brak hasel w programie" << endl
                    << "Wcisnij Enter aby kontynuowac" << endl;
                cin.ignore(100, '\n');
                cin.ignore();
                system("cls");
                break;
            }
            zlyWybor = false;
            zlyWybor = false;
            cout << endl << "Podaj numer kolumny z ktorej chcesz wyszukac haslo (1 - Nazwa, 2 - Haslo, 3 - Kategoria, 4 - Strona, 5 - Login)\n"
                << "oraz wyszukiwana fraze, oddzielona od numeru spacja (przyklad:3 Rozrywka)\n"
                << "Wyszukiwana fraza moze byc jedynie fragmentem calego sformulowania, ale kolejnosc i wielkosc liter musza sie zgadzac\n"
                << "Aby anulowac wybrana opcje, podaj znak 'q'" << endl;

            string doWyszukania;
            cin.ignore(100, '\n');
            getline(cin, doWyszukania);
            if (doWyszukania == "q")
            {
                system("cls");
                break;
            }
            cout << endl;
            haslaa->wyszukajUsun(doWyszukania);
            system("cls");
            break;
        }
            //DODAWANIE KATEGORII
        case '6':
        {
            zlyWybor = false;
            dodajKategorie(kategorie);
            system("cls");
            break;
        }
            //USUWANIE KATEGORII
        case '7':
        {
            if (haslaa->pobierzHasla().size() == 0)
            {
                cout << endl << "Brak hasel w programie" << endl
                    << "Wcisnij Enter aby kontynuowac" << endl;
                cin.ignore(100, '\n');
                cin.ignore();
                system("cls");
                break;
            }
            zlyWybor = false;
            cout << endl << "Dostepne kategorie to:" << endl;
            for (size_t i = 0; i < kategorie.size(); i++)
            {
                cout << i + 1 << ". " << kategorie[i] << endl;
            }
            cout << endl << kategorie.size() + 1 << ". Anuluj usuwanie" << endl;
            cout << endl << "Wybierz nazwe kategorii, ktora ma zostac usunieta, wpisujac jej numer\n"
                << "(UWAGA: spowoduje to rowniez usuniecie hasel w tej kategorii)" << endl;
            int wyborKategoria;
            bool czyKategoria = false, anuluj = false;
            string wyszukajka = "3 ";
            vector<Haslo*> wyszukane;
            string wybranaKategoria;
            while (!czyKategoria) {

                cin >> wyborKategoria;
                if (wyborKategoria > 0 && wyborKategoria <= kategorie.size()+1)
                {
                    if (wyborKategoria == kategorie.size() + 1) 
                    {
                        czyKategoria = true;
                        anuluj = true;
                        break;
                    }
                    else
                    {
                        for (int i = 1; i <= kategorie.size(); i++)
                        {
                            if (i == wyborKategoria) {

                                wybranaKategoria = kategorie[i-1];
                                wyszukajka = wyszukajka + wybranaKategoria;
                                wyszukane = haslaa->wyszukaj(wyszukajka);
                                czyKategoria = true;
                                break;
                            }
                        }
                    }
                }
                if (!czyKategoria)
                {
                    cout << "Error - niepoprawna kategoria, prosze wprowadzic ponownie:+" << endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }
            }
            if (anuluj)
            {
                system("cls");
                break;
            }
            cout << endl;
            for (size_t i = 0; i < wyszukane.size(); i++)
            {
                wyszukane[i]->wypisz();
            }
            cout << endl << "Powyzsze hasla zostana permanetntnie usuniete" << endl
                << "Zatwierdzic? (t - tak , n - nie)" << endl;
            char zatwierdzenie;
            bool final = false;
            while (!final)
            {
                cin >> zatwierdzenie;
                switch (zatwierdzenie) {

                case 't':
                    haslaa->usuwaniePoKategorii(wybranaKategoria);
                    haslaa->usunKategorie(kategorie, wybranaKategoria);
                    cout << endl << "Wybrana kategoria zostala usunieta, wraz ze wszystkimi haslami z nia powiazanymi\n"
                        << "Wcisnij Enter aby kontynuowac" << endl;
                    final = true;
                    cin.ignore(100, '\n');
                    cin.ignore();
                    system("cls");
                    break;
                case 'n':
                    cout << endl << "Usuwanie zostalo anulowane\n"
                        << "Wcisnij Enter aby kontynuowac" << endl;
                    final = true;
                    cin.ignore(100, '\n');
                    cin.ignore();
                    system("cls");
                    break;    
                default:
                    break;
                }
            }
            break;
        }
            //WYJSCIE Z PROGRAMU
        case '8':
        {
            zlyWybor = false;
            bool ladowanko = false;
            bool areYouSure = false;
            while (!ladowanko)
            {
                if (!zlyWybor)
                {
                    cout << endl << "Czy chcesz zapisac dane ze swoimi haslami? (t - tak , n - nie)\n";
                }
                char wyborZapis;
                cin >> wyborZapis;
                switch (wyborZapis)
                {
                case 't':
                    ladowanko = true;
                    haslaa->zaszyfruj();
                    plikachu->zaplikuj();
                    cout << endl << "Dane pomyslnie zapisane do pliku lista_zakupow.doc, znajdujacego sie w folderze Menedzera Hasel" << endl;
                    break;
                case 'n':
                    areYouSure = false;
                    while (!areYouSure)
                    {
                        if (!zlyWybor)
                        {
                            cout << endl << "Czy na pewno? Spowoduje to utrate zmian wprowadzonych podczas aktualnej sesji (t - tak , n - nie)" << endl;
                        }
                        cin >> wyborZapis;
                        switch (wyborZapis)
                        {
                        case 't':
                            ladowanko = true;
                            areYouSure = true;
                            break;
                        case 'n':
                            zlyWybor = false;
                            areYouSure = true;
                            break;
                        default:
                            zlyWybor = true;
                            cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:\n";
                            cin.clear();
                            cin.ignore(100, '\n');
                            break;
                        }
                    }
                    break;
                default:
                    cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:\n";
                    cin.clear();
                    cin.ignore(100, '\n');
                    break;
                }
            }

            goodbye = true;
            cout << endl << "Do zobaczenia!";
            break;
        }
        default:
            cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            zlyWybor = true;
            break;
        }
    }

}

/*DEFINICJA Menu::menuLadowanie() -> void
Funkcja udostepnia uzytkownikowi zaladowanie juz istniejacego pliku z haslami

Args:
    brak

Returns:
    brak*/
void Menu::menuLadowanie() {

    cout << endl << "----Witaj w menedzerze hasel----\n\n"
        << "Czy chcesz wczytac plik ze swoimi haslami? (t - tak , n - nie)" << endl;

    bool ladowanko = false;
    while (!ladowanko)
    {
        char wyborZapis;
        cin >> wyborZapis;
        switch (wyborZapis)
        {
        case 't':
            ladowanko = true;
            plikachu->odplikuj(kategorie);
            break;
        case 'n':
            ladowanko = true;
            break;
        default:
            cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:\n";
            cin.clear();
            cin.ignore(100, '\n');
            break;
        }
    }

}

/*DEFINICJA Menu::czyWielka(char literka) -> bool
Funkcja sprawdza czy podany znak typu char wielka litera

Args:
    literka (char) : litera do sprawdzenia

Returns:
    bool : czy litera jest wielka litera*/
bool Menu::czyWielka(const char literka) {

    for (char i = 65; i < 91; i++)
    {

        if (literka == i)
        {

            return true;

        }

    }

    return false;
}

/*DEFINICJA Menu::czyCyfra(char literka) -> bool
Funkcja sprawdza czy podany znak typu char jest znakiem specjalnym

Args:
    literka (char) : litera do sprawdzenia

Returns:
    bool : czy litera jest cyfra*/
bool Menu::czyCyfra(char literka) {

    for (char i = 48; i < 58; i++)
    {

        if (literka == i)
        {

            return true;

        }

    }

    return false;
}

/*DEFINICJA Menu::czyZnakSpecjalny(char literka) -> bool
Funkcja sprawdza czy podany znak typu char jest znakiem specjalnym

Args:
    literka (char) : litera do sprawdzenia

Returns:
    bool : czy litera jest znakiem specjalnym*/
bool Menu::czyZnakSpecjalny(char literka) {

    char i = 33;
    while (i < 127)
    {

        if (literka == i)
        {

            return true;

        }

        if (i == 47)
        {
            i += 11;
        }
        else if (i == 64 || i == 96)
        {
            i += 27;
        }
        else
        {
            i++;
        }

    }
    return false;
}

/*DEFINICJA Menu::dodajKategorie(vector<string> &kategorie) -> void
Funkcja dodaje nowa kategorie, z ktorej uzytownik moze pozniej skorzystac w celu tworzenia nowych hasel

Args:
    &kategorie(vector<string>) : wektor zawierajacy kategorie, przekazany przez referencje

Returns:
    brak*/
void Menu::dodajKategorie(vector<string> &kategorie) {
    cout << endl << "Podaj nazwe kategorii do dodania" << endl;
    if (kategorie.size()>0)
    {
        cout << "Aby anulowac wybrana opcje, podaj znak 'q'" << endl;
    }

    bool czyKatIstnieje = false;
    int i = 0;
    string kategoriaAdd;
    while (true)
    {

        cin >> kategoriaAdd;
        kategoriaAdd = czyWZakresie(kategoriaAdd);
        if (kategorie.size()>0)
        {
            if (kategoriaAdd == "q")
            {
                system("cls");
                break;
            }
        }


        czyKatIstnieje = false;
        i = 0;
        while (i < kategorie.size() && !czyKatIstnieje)
        {
            if (kategorie[i] == kategoriaAdd)
            {
                cout << endl << "Error - podana kategoria juz istnieje, prosze wprowadzic ponownie" << endl;
                czyKatIstnieje = true;
            }
            i++;
        }
        if (!czyKatIstnieje)
        {
            kategorie.push_back(kategoriaAdd);
            cout << endl << "Kategoria pomyslnie dodana" << endl
                << "Wcisnij Enter aby kontynuowac" << endl;
            cin.ignore(100, '\n');
            cin.ignore();
            break;
        }
    }
}

/*DEFINICJA Menu::czyWZakresie(string linijka) -> string
Funkcja sprawdza czy rozwiar podanego ciagu znakow znajduje sie w przedziale do 20 znakow

Args:
    linijka(string) : ciag znakow do sprawdzenia

Returns:
    string : ewentualnie zmieniony ciag znakow, w razie gdyby przyjety ciag wykraczal poza zakres*/
string Menu::czyWZakresie(string linijka) {

    bool wZakresie = false;
    while (!wZakresie) {

        if (linijka.size() > 20) {

            cout << "Error - podana fraza nie miesci sie w limicie znakow, sprobuj ponownie" << endl;
            cin >> linijka;

        }
        else {

            wZakresie = true;

        }
    }
    return linijka;
}

/*DEFINICJA Menu::dejLiterke() -> char
Funkcja zwraca losowo wybrana mala litere

Args:
    brak

Returns:
    char : losowo wybrana mala litera*/
char Menu::dejLiterke() {

    char literka = rand()%(123 - 97) + 97;
    return literka;

}

/*DEFINICJA Menu::dejCyferke() -> char
Funkcja zwraca losowo wybrana cyfre

Args:
    brak

Returns:
    char : losowo wybrana cyfra*/
char Menu::dejCyferke() {

    char literka = rand()%(58 - 48) + 48;
    return literka;

}

/*DEFINICJA Menu::dejBigLiterke() -> char
Funkcja zwraca losowo wybrana wielka litere

Args:
    brak

Returns:
    char : losowo wybrana wielka litera*/
char Menu::dejBigLiterke() {

    char literka = rand()%(91 - 65) + 65;
    return literka;

}

/*DEFINICJA Menu::dejZnak() -> char
Funkcja zwraca losowo wybrany znak specjalny

Args:
    brak

Returns:
    char : losowo wybrany znak specjalny*/
char Menu::dejZnak() {

    string znaki = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}";
    int i = rand() % znaki.size();
    return znaki[i];
    
}

/*DEFINICJA Menu::dodajHaslo() -> void
Funkcja sluzaca do dodawania nowego wpisu z haslem przez uzytkownika. Nalezy podac nazwe, 
haslo, wlasne lub automatycznie wygenerowane na podstawie wybranych przez uzytkownika parametrow,
nastepnie wybrac kategorie, i ewentualnie dopisac domene WWW i login

Args:
    brak

Returns:
    brak*/
void Menu::dodajHaslo() {

    Haslo* temp = new Haslo("$ $ $ $ $");

    //WPROWADZANIE NAZWY
    cout << endl << "Podaj nazwe, do ktorej bedzie przypisane nowe haslo (maksymalnie 20 znakow) (nie korzystaj ze znaku SPACJI)\n"
        << "Aby anulowac wybrana opcje, podaj znak 'q'" << endl;
    string newNazwa;
    cin >> newNazwa;
    newNazwa = czyWZakresie(newNazwa);

    if (newNazwa == "q")
    {
        system("cls");
        return;
    }
    strcpy(temp->nazwa, newNazwa.c_str());
    
    //WPROWADZANIE HASLA
    bool czyHaslo = false, errorHaslo = false;
    char wyborHaslo;
    while (!czyHaslo)
    {
             
        if (!errorHaslo)
        {
            cout << endl << "Czy chcesz dostac automatycznie wygenerowane haslo? (t - tak , n - nie)" << endl;
        }
        cin >> wyborHaslo;
        switch (wyborHaslo)
        {
        case 't':
        {
            //AUTOMATYCZNE GENEROWANIE HASLA
            errorHaslo = false;
            int iloscZnakow;
            bool znakiHaslo = false, detaleHaslo = false;
            cout << endl << "Podaj ile znakow ma miec wygenerowane haslo (minimalnie 5, maksymalnie 20)" << endl;
            while (!znakiHaslo) {

                cin >> iloscZnakow;
                if (iloscZnakow <= 20 && iloscZnakow >= 5) {
                    znakiHaslo = true;
                    break;
                }
                else {
                    cout << "Error - niepoprawna ilosc, prosze wprowadzic ponownie:\n";
                    cin.clear();
                    cin.ignore(100, '\n');
                }
            }
            bool zawieraWielkie, zawieraCyfry, zawieraZnaki, wybieranko = false;
            char decyzja;
            cout << endl << "Czy haslo ma zawierac wielkie litery? (t - tak , n - nie)" << endl;
            while (!wybieranko) {

                cin >> decyzja;
                switch (decyzja)
                {
                case 't':
                    zawieraWielkie = true;
                    wybieranko = true;
                    break;
                case 'n':
                    zawieraWielkie = false;
                    wybieranko = true;
                    break;
                default:
                    cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:\n";
                    cin.clear();
                    cin.ignore(100, '\n');
                    break;
                }
            }
            wybieranko = false;
            cout << endl << "Czy haslo ma zawierac cyfry? (t - tak , n - nie)" << endl;
            while (!wybieranko) {

                cin >> decyzja;
                switch (decyzja)
                {
                case 't':
                    zawieraCyfry = true;
                    wybieranko = true;
                    break;
                case 'n':
                    zawieraCyfry = false;
                    wybieranko = true;
                    break;
                default:
                    cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:\n";
                    cin.clear();
                    cin.ignore(100, '\n');
                    break;
                }
            }
            wybieranko = false;
            cout << endl << "Czy haslo ma zawierac znaki specjalne? (t - tak , n - nie)" << endl;
            while (!wybieranko) {

                cin >> decyzja;
                switch (decyzja)
                {
                case 't':
                    zawieraZnaki = true;
                    wybieranko = true;
                    break;
                case 'n':
                    zawieraZnaki = false;
                    wybieranko = true;
                    break;
                default:
                    cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:\n";
                    cin.clear();
                    cin.ignore(100, '\n');
                    break;
                }
            }
            string newHaslo;
            bool dobreHaslo = false;
            while (!dobreHaslo)
            {
                while (newHaslo.size() < iloscZnakow) {
                    int losuj = rand() % 4;

                    switch (losuj)
                    {
                    case 0:
                        if (zawieraZnaki)
                        {
                            newHaslo.push_back(dejZnak());
                        }
                        break;

                    case 1:
                        if (zawieraCyfry)
                        {
                            newHaslo.push_back(dejCyferke());
                        }
                        break;

                    case 2:
                        if (zawieraWielkie)
                        {
                            newHaslo.push_back(dejBigLiterke());
                        }
                        break;

                    case 3:
                        newHaslo.push_back(dejLiterke());
                        break;

                    default:
                        cout << "easter egg";
                        break;
                    }
                }
                bool wielkie = false, cyfry = false , znaki = false;
                for (int i = 0; i < newHaslo.size(); i++)
                {
                    if (zawieraWielkie && czyWielka(newHaslo[i])) {
                            
                        wielkie = true;                        
                    }
                    if (zawieraCyfry && czyCyfra(newHaslo[i])) {

                        cyfry = true;
                    }
                    if (zawieraZnaki && czyZnakSpecjalny(newHaslo[i])) {

                        znaki = true;
                    }
                }
                if (zawieraWielkie == wielkie && zawieraCyfry == cyfry && zawieraZnaki == znaki)
                {
                    dobreHaslo = true;
                }
                else 
                {
                    newHaslo = "";
                }

            }
            cout << endl << "Wygenerowane haslo to: " << newHaslo << endl;
            strcpy(temp->haslo, newHaslo.c_str());
            czyHaslo = true;
            break;
        }
        case 'n':
        {
            //WLASNE WPROWADZANIE HASLA
            errorHaslo = false;
            string newHaslo;
            cout << endl << "Podaj nowe haslo (maksymalnie 20 znakow) (nie korzystaj ze znaku SPACJI)\n"
                << "Zostanie wyswietlona sila bezpieczenstwa wpisanego hasla i w jaki sposob bedzie mozna ja zwiekszyc" << endl;

            cin >> newHaslo;
            newHaslo = czyWZakresie(newHaslo);

            bool wielka = false, cyfra = false, znak = false;
            for (size_t i = 0; i < newHaslo.size(); i++)
            {
                if (czyWielka(newHaslo[i]))
                {
                    wielka = true;
                }
                if (czyCyfra(newHaslo[i]))
                {
                    cyfra = true;
                }
                if (czyZnakSpecjalny(newHaslo[i]))
                {
                    znak = true;
                }
            }
            cout << endl << "Twoje haslo: " << newHaslo << endl << endl;
            if (wielka)
            {
                cout << "Zawiera co najmniej jedna wielka litere" << endl;
            }
            else
            {
                cout << "Nie zawiera wielkich liter" << endl;
            }
            if (cyfra)
            {
                cout << "Zawiera co najmniej jedna cyfre" << endl;
            }
            else
            {
                cout << "Nie zawiera cyfr" << endl;
            }
            if (znak)
            {
                cout << "Zawiera co najmniej jeden znak specjalny" << endl;
            }
            else
            {
                cout << "Nie zawiera znakow specjalnych" << endl;
            }
            if (wielka && cyfra && znak)
            {
                cout << endl << "Jest to bardzo bezpieczne haslo, gratulacje!" << endl;
            }
            else
            {
                cout << endl << "To haslo moze byc bezpieczniejsze, jezeli dodasz do niego brakujace elementy wyswietlone wyzej" << endl;
            }
            bool potwierdzHaslo = false;
            char czyNaPewnoHaslo;
            cout << endl << "Czy chcesz zostawic takie haslo? (t - tak , n - nie)" << endl;
            cin.clear();
            while (!potwierdzHaslo)
            {
                cin >> czyNaPewnoHaslo;
                switch (czyNaPewnoHaslo)
                {
                case 't':
                    strcpy(temp->haslo, newHaslo.c_str());
                    potwierdzHaslo = true;
                    czyHaslo = true;
                    break;
                case 'n':
                    potwierdzHaslo = true;
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
        default:
            errorHaslo = true;
            cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:\n";
            cin.clear();
            cin.ignore(100, '\n');
            break;
        }
    }
    //WPROWADZENIE KATEGORII
    if (kategorie.size() > 0)
    {
        cout << endl << "Dostepne kategorie to: " << endl;
        for (size_t i = 0; i < kategorie.size(); i++)
        {
            cout << i + 1 << ". " << kategorie[i] << endl;
        }
        cout << endl << kategorie.size() + 1 << ". " << "Stworz nowa kategorie\n" << endl;
        cout << "Ktora kategorie chcesz wybrac? (wpisz odpowiedni numer)" << endl;
        int wyborKategoria;
        bool czyKategoria = false, tworzonaKategoria = false;
        while (!czyKategoria) {

            if (tworzonaKategoria)
            {
                cout << kategorie.size() << endl;
                for (size_t i = 0; i < kategorie.size(); i++)
                {
                    cout << i + 1 << ". " << kategorie[i] << endl;
                }
                cout << endl << kategorie.size() + 1 << ". " << "Stworz nowa kategorie\n" << endl;
                cout << "Ktora kategorie chcesz wybrac? (wpisz odpowiedni numer)" << endl;
            }

            tworzonaKategoria = false;
            cin >> wyborKategoria;
            if (wyborKategoria == kategorie.size() + 1)
            {
                dodajKategorie(kategorie);
                tworzonaKategoria = true;
            }
            for (int i = 1; i <= kategorie.size(); i++)
            {
                if (i == wyborKategoria) {

                    strcpy(temp->kategoria, kategorie[i - 1].c_str());
                    czyKategoria = true;
                    break;
                }
            }

            if (!czyKategoria && !tworzonaKategoria)
            {
                cout << "Error - niepoprawna kategoria, prosze wprowadzic ponownie:" << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
        }
    }
    else
    {
        dodajKategorie(kategorie);
        strcpy(temp->kategoria, kategorie[0].c_str());     
    }

    //WPROWADZENIE STRONY
    cout << endl << "Podaj adres domeny internetowej, w ktorej jest uzywane to haslo (OPCJONALNE, wpisz znak '$', jesli chcesz zostawic puste) "
        << "(maksymalnie 20 znakow) (nie korzystaj ze znaku SPACJI)" << endl;
    string newStrona;
    cin >> newStrona;
    newStrona = czyWZakresie(newStrona);
    strcpy(temp->strona, newStrona.c_str());

    //WPROWADZENIE LOGINU
    cout << endl << "Podaj login przynalezacy do tego hasla "
        << "(OPCJONALNE, wpisz znak '$', jesli chcesz zostawic puste) (maksymalnie 20 znakow) (nie korzystaj ze znaku SPACJI)" << endl;
    string newLogin;
    cin >> newLogin;
    newLogin = czyWZakresie(newLogin);
    strcpy(temp->login, newLogin.c_str());

    //ZATWIERDZENIE HASLA
    bool zlyWybor = false;
    bool areYouSure = false;
    bool final = false;
    while (!final)
    {
        if (!zlyWybor)
        {
            cout << endl;
            temp->wypisz();
            cout << endl << "Czy chcesz aby takie haslo zostalo utworzone? (t - tak , n - nie)" << endl;
        }
        char wyborFinal;
        cin >> wyborFinal;
        switch (wyborFinal)
        {
        case 't':
            haslaa->dodaj(temp);
            cout << endl << "Nowe haslo zostalo pomyslnie utworzone" << endl;
            cout << "Wcisnij Enter aby kontynuowac" << endl;
            cin.ignore(100, '\n');
            cin.ignore();
            final = true;
            break;
        case 'n':
            areYouSure = false;
            while (!areYouSure)
            {
                if (!zlyWybor)
                {
                    cout << endl << "Czy na pewno? Spowoduje to utrate aktualnego wzorca (t - tak , n - nie)" << endl;
                }
                cin >> wyborFinal;
                switch (wyborFinal)
                {
                case 't':
                    areYouSure = true;
                    final = true;
                    break;
                case 'n':
                    zlyWybor = false;
                    areYouSure = true;
                    break;
                default:
                    zlyWybor = true;
                    cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:\n";
                    cin.clear();
                    cin.ignore(100, '\n');
                    break;
                }
            }
            break;
        default:
            cout << "Error - niepoprawna opcja, prosze wprowadzic ponownie:\n";
            cin.clear();
            cin.ignore(100, '\n');
            break;
        }
    }
    system("cls");
    return;
}