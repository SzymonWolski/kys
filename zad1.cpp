#include <iostream>
using namespace std;

struct Wezel {
    int dane;
    Wezel* poprzedni;
    Wezel* nastepny;
    
    Wezel(int wartość) : dane(wartość), poprzedni(nullptr), nastepny(nullptr) {}
};

class ListaDwukierunkowa{
private:
    Wezel* pierwszy;
    Wezel* ostatni;
    
public:
    ListaDwukierunkowa() : pierwszy(nullptr), ostatni(nullptr) {}
    
    ~ListaDwukierunkowa() {
        wyczyść();
    }

    void dodajNaPoczątek(int wartość) {
        Wezel* nowyWezel = new Wezel(wartość);
        if (!pierwszy) {
            pierwszy = ostatni = nowyWezel;
        } else {
            nowyWezel->nastepny = pierwszy;
            pierwszy->poprzedni = nowyWezel;
            pierwszy = nowyWezel;
        }
    }
    
    void dodajNaKoniec(int wartość) {
        Wezel* nowyWezel = new Wezel(wartość);
        if (!ostatni) {
            pierwszy = ostatni = nowyWezel;
        } else {
            nowyWezel->poprzedni = ostatni;
            ostatni->nastepny = nowyWezel;
            ostatni = nowyWezel;
        }
    }
 
    void dodajPodIndeksem(int indeks, int wartość) {
        if (indeks == 0) {
            dodajNaPoczątek(wartość);
            return;
        }
        Wezel* aktualny = pierwszy;
        int aktualnyIndeks = 0;
        while (aktualny && aktualnyIndeks < indeks) {
            aktualny = aktualny->nastepny;
            aktualnyIndeks++;
        }
        if (!aktualny) {
            dodajNaKoniec(wartość);
        } else {
            Wezel* nowyWezel = new Wezel(wartość);
            nowyWezel->poprzedni = aktualny->poprzedni;
            nowyWezel->nastepny = aktualny;
            if (aktualny->poprzedni) {
                aktualny->poprzedni->nastepny = nowyWezel;
            }
            aktualny->poprzedni = nowyWezel;
        }
    }

    void usuńZPoczątku() {
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

    void usuńZKońca() {
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

    void usuńPodIndeksem(int indeks) {
        if (indeks == 0) {
            usuńZPoczątku();
            return;
        }
        
        Wezel* aktualny = pierwszy;
        int aktualnyIndeks = 0;
        
        while (aktualny && aktualnyIndeks < indeks) {
            aktualny = aktualny->nastepny;
            aktualnyIndeks++;
        }
        
        if (!aktualny) return;
        
        if (aktualny->poprzedni) aktualny->poprzedni->nastepny = aktualny->nastepny;
        if (aktualny->nastepny) aktualny->nastepny->poprzedni = aktualny->poprzedni;
        
        if (aktualny == pierwszy) pierwszy = aktualny->nastepny;
        if (aktualny == ostatni) ostatni = aktualny->poprzedni;
        
        delete aktualny;
    }

    void wyświetl() {
        Wezel* aktualny = pierwszy;
        while (aktualny) {
            cout << aktualny->dane << " ";
            aktualny = aktualny->nastepny;
        }
        cout << endl;
    }

    void wyświetlOdTyłu() {
        Wezel* aktualny = ostatni;
        while (aktualny) {
            cout << aktualny->dane << " ";
            aktualny = aktualny->poprzedni;
        }
        cout << endl;
    }

    void wyświetlNastępny(Wezel* wezel) {
        if (wezel && wezel->nastepny) {
            cout << "Następny element: " << wezel->nastepny->dane << endl;
        } else {
            cout << "Brak nastepnego elementu." << endl;
        }
    }

    void wyświetlPoprzedni(Wezel* wezel) {
        if (wezel && wezel->poprzedni) {
            cout << "Poprzedni element: " << wezel->poprzedni->dane << endl;
        } else {
            cout << "Brak poprzedniego elementu." << endl;
        }
    }

    void wyczyść() {
        while (pierwszy) {
            usuńZPoczątku();
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

    lista.dodajNaPoczątek(10);
    lista.dodajNaPoczątek(20);
    lista.dodajNaKoniec(30);
    lista.dodajPodIndeksem(1, 25);
  
    cout << "Lista: ";
    lista.wyświetl();
    
    cout << "Lista w odwrotnej kolejnosci: ";
    lista.wyświetlOdTyłu();
    
    lista.usuńZPoczątku();
    lista.usuńZKońca();
    
    cout << "Lista po usunieciach: ";
    lista.wyświetl();
    
    lista.usuńPodIndeksem(1);
    
    cout << "Lista po usunieciu elementu pod indeksem 1: ";
    lista.wyświetl();
    
    Wezel* pierwszyElement = lista.pobierzPierwszy();
    Wezel* ostatniElement = lista.pobierzOstatni();
    lista.wyświetlNastępny(pierwszyElement);
    lista.wyświetlPoprzedni(ostatniElement);
    
    lista.wyczyść();
    cout << "Lista po wyczyszczeniu:: ";
    lista.wyświetl();
    
    return 0;
}