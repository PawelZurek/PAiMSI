#ifndef KOLEJKA_LISTA_HH
#define KOLEJKA_LISTA_HH
/*!
 *\file
 *\brief Definicje funkcji dla klasy Kolejka zdefiniowanej lista.
 *
 */
#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>

using namespace std;

/*!
 *
 *\brief Modeluje pojecie elementk (zmieniona nazwa, poniewaz
 * stos_lista tez ma klase o nazwie element).
 *
 */

 /*!
 *
 * Element jest klasa,ktora bedzie wpisywana do stosu
 * Klasa ta zawiera informacje o danej wartosci elementu ( klucz )
 * oraz wskaznik na nastepny element.
 *
 */
class elementk
{
  public:
/*!
	 * \brief Pole typu element*, wskaznik uzywany do laczenia elementow miedzy soba w stos.
	*/
  elementk* nastepny;
/*!
	 * \brief Pole typu int, przechowuje informacje o wartosci danego elementu.
	*/
  int klucz;
};
/*!
 *
 *\brief Modeluje pojecie Kolejka.
 *
 */

/*!
 * Stos jest klasa zawierajaca dynamicznie zaalokowane liste
 *
 */
class kolejka_lista{
	
private:
/*!
	 * \brief Pole typu element, wskazuje na pierwszy element listy
	*/
  elementk *przod;
/*!
	 * \brief Pole typu element, wskazuje na ostatni element listy
	*/
  elementk *tyl;

/*!
	 * \brief Pole typu int, bedzie uzywane jako rozmiar kolejki.
	*/
  unsigned licznik;
public:
	
/*!
 *
 *\brief Konstruktor klasy kolejka.
 *
 * Konstruktor jest bezparametryczny, inicjalizuje wszystkie skladowe
 * klasy wartosciami zerowymi.
 *
 */
	kolejka_lista(){ przod = tyl = NULL; licznik = 0; }
/*!
 *
 *\brief Destruktor klasy Kolejka.
 *
 * Usuwa dynamicznie zaalokawana liste
 */
	~kolejka_lista(){elementk *p;
		while(przod){
			p = przod -> nastepny;
			delete przod;
			przod = p;
		}
	}
/*!
 *
 *\brief Funkcja wczytywania.
 *
 * Funkcja wczytuje wartosci do stosu z podanego pliku przez   
 * uzytkownika.  
 *
 */

	void wczytaj_dane();
/*!
 *
 *\brief Funkcja wczytywania.
 *
 * Funkcja wczytuje wartosci do tabeli    
 * po przez wpisanie nazwy jako argument metody
 * Wykorzystuje metode push jako funkcje wpisujaca do kolejki
 *
 * \param nazwa -> zmienna typu string, przechowuje nazwe otwieranego pliku
 */
	void wczytaj_dane(string nazwa);
/*!
 *
 *\brief Funkcja wyswietlajaca
 * 
 * Funkcja wyswietla aktualny stan kolejki
 *
 */
	void pokaz_elementy();
/*!
 *
 *\brief Funkcja sprawdzania pustosci kolejki.
 *
 * Funkcja sprawdza czy kolejka jest pusty   
 *
 *\return 1 -> Kolejka pusta
	  	  0 -> kolejka nie pusta
 */
	bool isempty();
/*!
 *
 *\brief Funkcja sprawdzania rozmiar kolejki.
 *
 * Funkcja podaje aktualny rozmiar kolejki 
 *
 *\return rozmiar -> rozmiar kolejki
 */
	unsigned size();
/*!
 *
 *\brief Funkcja dodajaca element
 * 
 * Funkcja wstawia nowy element p na koniec kolejki i zwraca jego adres.

Jeśli lista zawiera jakieś elementy, to tyl zawsze wskazuje ostatni element listy. W pole nastepny ostatniego elementu wpisujemy w takim przypadku adres wstawianego elementu. W efekcie zostanie on dołączony do końca listy. W polu nastepny nowego elementu umieszczamy adres zerowy NULL, ponieważ jest on teraz ostatnim elementem i nie posiada następnika.

Lista mogła być pusta. W takim przypadku wstawiony element jest jednocześnie pierwszym i ostatnim. Dlatego do pola przod wpisujemy adres pobrany z pola tyl.

Po wstawieniu elementu zwiększamy licznik licznik i zwracamy adres końca kolejki.
 *
 *\param p - pole typu element przechowuje wartosc jaka ma byc wpisana
 *\return adres nowego elementu.
 */
	elementk *push(elementk *p);
/*!
 *
 *\brief Funkcja dodajaca element
 * 
 * Funkcja dodaje do stosu element podany przez uzytkownika
 * poprzez wywolanie funkcji push().
 *\param a - pole typu int przechowuje wartosc jaka ma byc wpisana
 */
	void dodaj_element(int a);
/*!
 *
 *\brief Funkcja usuwajaca ostatni element ze stosu
 * 
 * Funkcja  usuwa z listy ostatni element i zwraca jego adres. 

Jeśli lista jest pusta, to pole tyl zawiera NULL. W takim przypadku zwracamy NULL i kończymy.

W przeciwnym razie zapamiętujemy adres ostatniego elementu listy w p. Jeśli lista zawiera tylko jeden element , to pola przod i tyl zawierają ten sam adres. W takim przypadku lista staje się pusta po odłączeniu ostatniego elementu, dlatego wpisujemy w nie adres pusty NULL.

Jeśli lista zawiera więcej niż jeden element, to przechodzimy kolejno przez wszystkie elementy listy ustawiając pole tyl na adres poprzednika ostatniego elementu. W poprzedniku zerujemy następnik.

Zmniejszamy licznik i zwracamy zapamiętany w p adres ostatniego elementu.
 */
	elementk *pop();
};
#endif 

