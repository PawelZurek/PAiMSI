#ifndef KOLEJKA_TABLICA_HH
#define KOLEJKA_TABLICA_HH
/*!
 *\file
 *\brief Definicje funkcji dla klasy Kolejka zdefiniowanej tablica.
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
 *\brief Modeluje pojecie Kolejka.
 *
 */

/*!
 * Kolejka_tab jest klasa zawierajaca dynamicznie zaalokowana 
 * tablice i tablice pomocnicza przy dodawaniu i usuwaniu
 * elementow z kolejki.
 *
 */

class kolejka_tablica{
	
private:
/*!
	 * \brief Pole typu int, bedzie uzywane jako kolejki z danymi.
	*/
  int *dane;
/*!
	 * \brief Pole typu int, bedzie uzywane jako kolejko z danymi sprawdzajacymi, pomocniczymi.
	*/
  int *danetmp;

/*!
	 * \brief Pole typu int, bedzie uzywane jako rozmiar tabeli.
	*/
  int rozmiar;
/*!
	 * \brief Pole typu int, bedzie uzywane jako pomocnicza wartosc jako rozmiar kolejki.
	*/
  int spr;
public:
	
/*!
 *
 *\brief Konstruktor klasy kolejka.
 *
 * Konstruktor jest bezparametryczny, inicjalizuje wszystkie skladowe
 * klasy wartosciami zerowymi.
 *
 */
	kolejka_tablica(){dane = 0, rozmiar = 0, danetmp = 0, spr =0; };
/*!
 *
 *\brief Destruktor klasy kolejka.
 *
 * Usuwa dynamicznie zaalokawana tablice
 */
	~kolejka_tablica(){ 
		delete [] dane;
		rozmiar = 0;
	}
/*!
 *
 *\brief Funkcja wczytywania.
 *
 * Funkcja wczytuje wartosci do tabeli z podanego pliku przez   
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
 *\brief Funkcja wczytywania.
 *
 * Funkcja wczytuje wartosci do tabeli    
 * po przez wpisanie nazwy jako argument metody
 * Wykorzystuje metode pushx2 jako funkcje wpisujaca do kolejki
 *
 * \param nazwa -> zmienna typu string, przechowuje nazwe otwieranego pliku
 */
	void wczytaj_danex2(string nazwa);

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
 *\brief Funkcja sprawdzania pustosci kolejki
 *
 * Funkcja sprawdza czy kolejka jest pusty   
 *
 *\return 1 -> Kolejka pusta
	  	  0 -> Kolejka nie pusta
 */
	bool isEmpty();
/*!
 *
 *\brief Funkcja sprawdzania rozmiar kolejki
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
 * Funkcja dodaje do stosu element podany przez uzytkownika
 * Funkcja dodaje element poprzez zwiekszenie rozmiaru tablicy
 * o jeden.
 *\param element - pole typu int przechowuje wartosc jaka ma byc wpisana
 */
	void push(int element);
/*!
 *
 *\brief Funkcja dodajaca element
 * 
 * Funkcja dodaje do stosu element podany przez uzytkownika
 * Funkcja dodaje element poprzez zwiekszenie rozmiaru tablicy
 * o dwa razy niz aktualny stan.
 *\param element - pole typu int przechowuje wartosc jaka ma byc wpisana
 */
	void pushx2(int element);
/*!
 *
 *\brief Funkcja usuwajaca ostatni element ze kolejki
 * 
 * Funkcja usuwa ostatni element znajdujacy sie na kolejce
 * oraz zmniejsza jego rozmiar o jeden.
 */
	void pop();
};

#endif 

