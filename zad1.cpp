
struct Wezel {
    int dane;
    Wezel* poprzedni;
    Wezel* nastepny;
    
    Wezel(int wartosc) : dane(wartosc), poprzedni(nullptr), nastepny(nullptr) {}
};


        class ListaDwukierunkowa{
private:
    Wezel* pierwszy;
    Wezel* ostatni;
    
public:
    ListaDwukierunkowa() : pierwszy(nullptr), ostatni(nullptr) {}
    
    ~ListaDwukierunkowa() {
        wyczysc();
    }

    void dodajNaPoczatek(int wartosc) {
        Wezel* nowyWezel = new Wezel(wartosc);
        if (!pierwszy) {
            pierwszy = ostatni = nowyWezel;
        } else {
            nowyWezel->nastepny = pierwszy;
            pierwszy->poprzedni = nowyWezel;
            pierwszy = nowyWezel;
        }
    }
    
    void dodajNaKoniec(int wartosc) {
        Wezel* nowyWezel = new Wezel(wartosc);
        if (!ostatni) {
            pierwszy = ostatni = nowyWezel;
        } else {
            nowyWezel->poprzedni = ostatni;
            ostatni->nastepny = nowyWezel;
            ostatni = nowyWezel;
        }
    }
 
    void dodajPodIndeksem(int indeks, int wartosc) {
        if (indeks == 0) {
            dodajNaPoczatek(wartosc);
            return;
        }
        
        Wezel* aktualny = pierwszy;
        int aktualnyIndeks = 0;
        while (aktualny && aktualnyIndeks < indeks) {
            aktualny = aktualny->nastepny;
            aktualnyIndeks++;
        }
        if (!aktualny) {
            dodajNaKoniec(wartosc);
        } else {
            Wezel* nowyWezel = new Wezel(wartosc);
            nowyWezel->poprzedni = aktualny->poprzedni;
            nowyWezel->nastepny = aktualny;
            if (aktualny->poprzedni) {
                aktualny->poprzedni->nastepny = nowyWezel;
            }
            aktualny->poprzedni = nowyWezel;
            if (aktualny == pierwszy) pierwszy = nowyWezel; 
        }
    }

    void usunZPoczatku() {
        if (!pierwszy) return;
        
        Wezel* temp = pierwszy;
        if (pierwszy == ostatni) {
            pierwszy = ostatni = nullptr;
        } else {
            pierwszy = pierwszy->nastepny;
            pierwszy->poprzedni = nullptr;
        }
        delete temp;
    }

    void usunZKonca() {
        if (!ostatni) return;
        
        Wezel* temp = ostatni;
        if (pierwszy == ostatni) {
            pierwszy = ostatni = nullptr;
        } else {
            ostatni = ostatni->poprzedni;
            ostatni->nastepny = nullptr;
        }
        delete temp;
    }

    void usunPodIndeksem(int indeks) {
        if (indeks == 0) {
            usunZPoczatku();
            return;
        }
        
        Wezel* aktualny = pierwszy;
        int aktualnyIndeks = 0;
        
        while (aktualny && aktualnyIndeks < indeks) {
            aktualny = aktualny->nastepny;
            aktualnyIndeks++;
        }
        
        if (!aktualny) return;  // Index out of bounds
        
        if (aktualny->poprzedni) aktualny->poprzedni->nastepny = aktualny->nastepny;
        if (aktualny->nastepny) aktualny->nastepny->poprzedni = aktualny->poprzedni;
        
        if (aktualny == pierwszy) pierwszy = aktualny->nastepny;
        if (aktualny == ostatni) ostatni = aktualny->poprzedni;
        
        delete aktualny;
    }

    void wyswietl() {
        if (!pierwszy) {
            cout << "Lista jest pusta." << endl;
            return;
        }
        Wezel* aktualny = pierwszy;
        while (aktualny) {
            cout << aktualny->dane << " ";
            aktualny = aktualny->nastepny;
        }
        cout << endl;
    }

    void wyswietlOdTylu() {
        if (!ostatni) {
            cout << "Lista jest pusta." << endl;
            return;
        }
        Wezel* aktualny = ostatni;
        while (aktualny) {
            cout << aktualny->dane << " ";
            aktualny = aktualny->poprzedni;
        }
        cout << endl;
    }

    void wyswietlNastepny(Wezel* wezel) {
        if (wezel && wezel->nastepny) {
            cout << "Nastepny element: " << wezel->nastepny->dane << endl;
        } else {
            cout << "Brak nastepnego elementu." << endl;
        }
    }

    void wyswietlPoprzedni(Wezel* wezel) {
        if (wezel && wezel->poprzedni) {
            cout << "Poprzedni element: " << wezel->poprzedni->dane << endl;
        } else {
            cout << "Brak poprzedniego elementu." << endl;
        }
    }

    void wyczysc() {
        while (pierwszy) {
            usunZPoczatku();
        }
    }
    
    Wezel* pobierzPierwszy() {
        return pierwszy;
    }
    
    Wezel* pobierzOstatni() {
        return ostatni;
    }
};

int main() {
    ListaDwukierunkowa lista;

    lista.dodajNaPoczatek(10);
    lista.dodajNaPoczatek(20);
    lista.dodajNaKoniec(30);
    lista.dodajPodIndeksem(1, 25);
  
    cout << "Lista: ";
    lista.wyswietl();
    
    cout << "Lista w odwrotnej kolejnosci: ";
    lista.wyswietlOdTylu();
    
    lista.usunZPoczatku();
    lista.usunZKonca();
    
    cout << "Lista po usunieciach: ";
    lista.wyswietl();
    
    lista.usunPodIndeksem(1);
    
    cout << "Lista po usunieciu elementu pod indeksem 1: ";
    lista.wyswietl();
    
    Wezel* pierwszyElement = lista.pobierzPierwszy();
    Wezel* ostatniElement = lista.pobierzOstatni();
    lista.wyswietlNastepny(pierwszyElement);
    lista.wyswietlPoprzedni(ostatniElement);
    
    lista.wyczysc();
    cout << "Lista po wyczyszczeniu: ";
    lista.wyswietl();
    
    return 0;
}
