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
#include <cmath>
#include "stdlib.h"
#include "time.h"

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
  string *dane;
/*!
	 * \brief Pole typu int, bedzie uzywane jako stosu z danymi sprawdzajacymi, pomocniczymi.
	*/
  string *danetmp;

  string *danetmp2;

  string *tab_kluczy;

/*!
	 * \brief Pole typu int, bedzie uzywane jako rozmiar tabeli.
	*/
  int rozmiar;

  /*!
	 * \brief Pole typu int, bedzie uzywane jako rozmiar tabeli.
	*/
  int rozmiar_tmp;
public:
	
/*!
 *
 *\brief Konstruktor klasy stos.
 *
 * Konstruktor jest bezparametryczny, inicjalizuje wszystkie skladowe
 * klasy wartosciami zerowymi.
 *
 */
	stos_tablica(){rozmiar = 0, rozmiar_tmp = 0; dane = 0,danetmp = 0, danetmp2=0, tab_kluczy=0; };
/*!
 *
 *\brief Destruktor klasy stos.
 *
 * Usuwa dynamicznie zaalokawana tablice
 */
	~stos_tablica(){ 
		delete [] dane;
		if (rozmiar_tmp != 0)
		{
			delete [] danetmp;
		}
		
	}


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
int size();
/*!
 *
 *\brief Funkcja dodajaca element
 * 
 * Funkcja dodaje do stosu element podany przez uzytkownika
 * Funkcja dodaje element poprzez zwiekszenie rozmiaru tablicy
 * o jeden.
 *\param element - pole typu int przechowuje wartosc jaka ma byc wpisana
 */
	void push(string klucz, string wartosc);

	void pop();

	/*!
 *
 *\brief Funkcja dodajaca element
 * 
 * Funkcja dodaje do stosu element podany przez uzytkownika
 * poprzez wywolanie funkcji push().
 *\param element - pole typu int przechowuje wartosc jaka ma byc wpisana
 */
	void dodaj_element();
/*!
 *
 *\brief Funkcja usuwajaca ostatni element ze stosu
 * 
 * Funkcja usuwa z listy pierwszy element i zwraca jego adres. Element zostaje jedynie odłączony od listy, lecz wciąż zajmuje swój obszar pamięci. Program główny coś powinien z takim elementem zrobić - np. dołączyć go w innym miejscu listy, odpowiednio przetworzyć lub usunąć. 

Na początku sprawdzamy, czy lista zawiera jakiś element. Jeśli nie, zwracamy NULL. W przeciwnym razie zapamiętujemy w zmiennej p adres pierwszego elementu. W polu przod umieszczamy adres następnego elementu listy. W ten sposób element p zostaje odłączony logicznie od listy.

Jeśli po odłączeniu pole front zawiera adres NULL, to lista jest obecnie pusta i NULL wpisujemy również do pola tyl.

Zmniejszamy o jeden licznik licznik i zwracamy adres usuniętego z listy elementu.
 */
	void usun();

	void pobierz();

};

#endif 

