#ifndef STOS_LISTA_HH
#define STOS_LISTA_HH
/*!
 *\file
 *\brief Definicje funkcji dla klasy Stos zdefiniowanej lista.
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
 *\brief Modeluje pojecie element.
 */

/*!
 *
 * Element jest klasa,ktora bedzie wpisywana do stosu
 * Klasa ta zawiera informacje o danej wartosci elementu ( klucz )
 * oraz wskaznik na nastepny element.
 *
 */

class element
{
  public:
/*!
	 * \brief Pole typu element*, wskaznik uzywany do laczenia elementow miedzy soba w stos.
	*/
  element* nastepny;
/*!
	 * \brief Pole typu int, przechowuje informacje o wartosci danego elementu.
	*/
  int klucz;
};
/*!
 *
 *\brief Modeluje pojecie Stos.
 */

/*!
 *
 * Stos jest klasa zawierajaca dynamicznie zaalokowane lista
 *
 */


class stos_lista{
	
private:
/*!
	 * \brief Pole typu element, wskazuje na pierwszy element listy
	*/
  element *przod;
/*!
	 * \brief Pole typu element, wskazuje na ostatni element listy
	*/
  element *tyl;

/*!
	 * \brief Pole typu int, bedzie uzywane jako rozmiar stosu.
	*/
  unsigned licznik;
public:
	
/*!
 *
 *\brief Konstruktor klasy stos.
 *
 * Konstruktor jest bezparametryczny, inicjalizuje wszystkie skladowe
 * klasy wartosciami zerowymi.
 *
 */
	stos_lista(){ przod = tyl = NULL; licznik = 0; }
/*!
 *
 *\brief Destruktor klasy stos.
 *
 * Usuwa dynamicznie zaalokawana liste
 */
	~stos_lista(){element *p;
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
 * Wykorzystuje metode push jako funkcje wpisujaca do stosu
 *
 * \param nazwa -> zmienna typu string, przechowuje nazwe otwieranego pliku
 */
	void wczytaj_dane(string nazwa);
/*!
 *
 *\brief Funkcja wyswietlajaca
 * 
 * Funkcja wyswietla aktualny stan stosu
 *
 */
	void pokaz_elementy();
/*!
 *
 *\brief Funkcja sprawdzania pustosci stosu.
 *
 * Funkcja sprawdza czy stos jest pusty   
 *
 *\return 1 -> Stos pusty
	\n 0 -> Stos nie pusty
 */
	bool isempty();
/*!
 *
 *\brief Funkcja sprawdzania rozmiar stosu.
 *
 * Funkcja podaje aktualny rozmiar stosu 
 *
 *\return rozmiar -> rozmiar stosu
 */
	unsigned size();
/*!
 *
 *\brief Funkcja dodajaca element
 * 
 * Funkcja wstawia nowy element p na początek listy i zwraca jego adres.

Najpierw wpisuje w pole nastpeny elementu p adres pierwszego elementu listy. W efekcie pierwszy element listy staje się elementem następnym dla p. W polu przod zostaje umieszczony adres elementu p, czyli staje się on pierwszym elementem na liście.

Lista mogła być pusta. Jeśli pole tyl zawiera NULL, to wstawiony element jest jedynym jak dotąd elementem listy. Zatem jest on zarówno elementem pierwszym jak i ostatnim. Dlatego w polu tyl umieszczamy w tym przypadku adres pierwszego elementu pobrany z pola przod.

Po wstawieniu elementu zwiększamy licznik licznik i zwracamy adres pierwszego elementu listy.
 *
 *\param p - pole typu element przechowuje wartosc jaka ma byc wpisana
 *\return adres nowego elementu.
 */
	element *push(element *p);
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
 * Funkcja usuwa z listy pierwszy element i zwraca jego adres. Element zostaje jedynie odłączony od listy, lecz wciąż zajmuje swój obszar pamięci. 

Na początku sprawdzamy, czy lista zawiera jakiś element. Jeśli nie, zwracamy NULL. W przeciwnym razie zapamiętujemy w zmiennej p adres pierwszego elementu. W polu przod umieszczamy adres następnego elementu listy. W ten sposób element p zostaje odłączony logicznie od listy.

Jeśli po odłączeniu pole przod zawiera adres NULL, to lista jest obecnie pusta i NULL wpisujemy również do pola tyl.

Zmniejszamy o jeden licznik licznik i zwracamy adres usuniętego z listy elementu.
 */
	element *pop();
};

#endif 

