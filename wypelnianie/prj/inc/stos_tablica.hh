#ifndef STOS_TABLICA_HH
#define STOS_TABLICA_HH
/*!
 *\file
 *\brief Definicje funkcji dla klasy Stos zdefiniowanej tablica.
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
 *\brief Modeluje pojecie Stos.
 */

/*!
 *
 * Stos jest klasa zawierajaca dynamicznie zaalokowane 2 tablice
 * Pierwsza z nich to tablica z danymi, na ktorych beda wykonywane 
 * operacje. Druga z nich sluzy jako tablica do przechowywania
 * tymczasowych danych.
 *
 */

class stos_tablica{
	private:
	/*!
	 * \brief Pole typu int, bedzie uzywane jako stosu z danymi.
	*/
  int *dane;
/*!
	 * \brief Pole typu int, bedzie uzywane jako stosu z danymi sprawdzajacymi, pomocniczymi.
	*/
  int *danetmp;

/*!
	 * \brief Pole typu int, bedzie uzywane jako rozmiar tabeli.
	*/
  int rozmiar;
/*!
	 * \brief Pole typu int, bedzie uzywane jako pomocnicza wartosc jako rozmiar stosu.
	*/
  int spr;
public:
	
/*!
 *
 *\brief Konstruktor klasy stos.
 *
 * Konstruktor jest bezparametryczny, inicjalizuje wszystkie skladowe
 * klasy wartosciami zerowymi.
 *
 */
	stos_tablica(){dane = 0, rozmiar = 0, danetmp = 0, spr =0; };
/*!
 *
 *\brief Destruktor klasy stos.
 *
 * Usuwa dynamicznie zaalokawana tablice
 */
	~stos_tablica(){ 
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
 * Wykorzystuje metode push jako funkcje wpisujaca do stosu
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
 * Wykorzystuje metode pushx2 jako funkcje wpisujaca do stosu
 *
 * \param nazwa -> zmienna typu string, przechowuje nazwe otwieranego pliku
 */
	void wczytaj_danex2(string nazwa);

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
	  	  0 -> Stos nie pusty
 */
	bool isEmpty();
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
 *\brief Funkcja usuwajaca ostatni element ze stosu
 * 
 * Funkcja usuwa ostatni element znajdujacy sie na stosie
 * oraz zmniejsza jego rozmiar o jeden.
 */
	void pop();
};

#endif 

