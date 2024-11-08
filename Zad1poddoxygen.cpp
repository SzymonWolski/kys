#include <iostream>
using namespace std;

/**
 * @brief Struktura reprezentująca pojedynczy element (węzeł) listy dwukierunkowej.
 */
struct Wezel {
    int dane;               ///< Wartość przechowywana w węźle
    Wezel* poprzedni;       ///< Wskaźnik do poprzedniego elementu
    Wezel* nastepny;        ///< Wskaźnik do następnego elementu
    
    /**
     * @brief Konstruktor inicjujący węzeł z wartością.
     * @param wartosc Wartość do zapisania w węźle
     */
    Wezel(int wartosc) : dane(wartosc), poprzedni(nullptr), nastepny(nullptr) {}
};

/**
 * @brief Klasa implementująca listę dwukierunkową.
 */
class ListaDwukierunkowa {
private:
    Wezel* pierwszy;    ///< Wskaźnik do pierwszego elementu listy
    Wezel* ostatni;     ///< Wskaźnik do ostatniego elementu listy
    
public:
    /**
     * @brief Konstruktor domyślny listy dwukierunkowej.
     */
    ListaDwukierunkowa() : pierwszy(nullptr), ostatni(nullptr) {}
    
    /**
     * @brief Destruktor, który usuwa wszystkie elementy listy.
     */
    ~ListaDwukierunkowa() {
        wyczysc();
    }

    /**
     * @brief Dodaje nowy element na początek listy.
     * @param wartosc Wartość nowego elementu
     */
    void dodajNaPoczatek(int wartosc);

    /**
     * @brief Dodaje nowy element na koniec listy.
     * @param wartosc Wartość nowego elementu
     */
    void dodajNaKoniec(int wartosc);
 
    /**
     * @brief Dodaje nowy element pod określonym indeksem.
     * @param indeks Indeks, pod którym zostanie dodany element
     * @param wartosc Wartość nowego elementu
     */
    void dodajPodIndeksem(int indeks, int wartosc);

    /**
     * @brief Usuwa pierwszy element z listy.
     */
    void usunZPoczatku();

    /**
     * @brief Usuwa ostatni element z listy.
     */
    void usunZKonca();

    /**
     * @brief Usuwa element znajdujący się pod danym indeksem.
     * @param indeks Indeks elementu do usunięcia
     */
    void usunPodIndeksem(int indeks);

    /**
     * @brief Wyświetla zawartość listy od początku do końca.
     */
    void wyswietl();

    /**
     * @brief Wyświetla zawartość listy od końca do początku.
     */
    void wyswietlOdTylu();

    /**
     * @brief Wyświetla wartość następnego elementu dla podanego węzła.
     * @param wezel Wskaźnik do węzła, dla którego wyświetlony zostanie następny element
     */
    void wyswietlNastepny(Wezel* wezel);

    /**
     * @brief Wyświetla wartość poprzedniego elementu dla podanego węzła.
     * @param wezel Wskaźnik do węzła, dla którego wyświetlony zostanie poprzedni element
     */
    void wyswietlPoprzedni(Wezel* wezel);

    /**
     * @brief Usuwa wszystkie elementy z listy.
     */
    void wyczysc();
    
    /**
     * @brief Zwraca wskaźnik do pierwszego elementu listy.
     * @return Wskaźnik do pierwszego węzła
     */
    Wezel* pobierzPierwszy();

    /**
     * @brief Zwraca wskaźnik do ostatniego elementu listy.
     * @return Wskaźnik do ostatniego węzła
     */
    Wezel* pobierzOstatni();
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
