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
  int rozmiar_tmp;
/*!
	 * \brief Pole typu int, bedzie uzywane jako pomocnicza wartosc do metody Quick Sort.
	*/
  	int lewy;
  /*!
	 * \brief Pole typu int, bedzie uzywane jako pomocnicza wartosc do metody Quick Sort.
	*/
    int prawy;
/*!
	 * \brief Pole typu int, bedzie uzywane jako pomocnicza wartosc do metody Heap Size.
	*/
    int heap_size;
public:
	
/*!
 *
 *\brief Konstruktor klasy stos.
 *
 * Konstruktor jest bezparametryczny, inicjalizuje wszystkie skladowe
 * klasy wartosciami zerowymi.
 *
 */
	stos_tablica(){heap_size=0, rozmiar = 0,lewy = 0,prawy = 0, dane = 0, rozmiar = 0, danetmp = 0, rozmiar_tmp =0; };
/*!
 *
 *\brief Destruktor klasy stos.
 *
 * Usuwa dynamicznie zaalokawana tablice
 */
	~stos_tablica(){ 
		if (rozmiar != 0){
			delete [] dane;
		}
		if (rozmiar_tmp!= 0){
			delete [] danetmp;
		}
		
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
 *\brief Funkcja wyswietlajaca
 * 
 * Funkcja wyswietla aktualny stan stosu
 *
 */
	void pokaz_elementy();
/*!
 *
 *\brief Funkcja sprawdzania rozmiar stosu.
 *
 * Funkcja podaje aktualny rozmiar stosu 
 *
 *\return rozmiar -> rozmiar stosu
 */
	int get_rozmiar(){ return rozmiar;}
/*!
 *
 *\brief Funkcja sortujaca.
 *
 * Funkcja sortuje dane za pomoca algorytmu Quick Sort  
 *
 *\param left -> Pole typu int, zawiera informacje indeksie poczatkowym sortowanego zbioru\n
 *\param right -> Pole typu int, zawiera informacje indeksie koncowym sortowanego zbioru
 */
	void quicksort( int left, int right );
/*!
 *
 *\brief Funkcja wywolujaca funkcje sorujaca Quick Sort.
 *
 * Funkcja jest tylko po to, aby mozna bylo w kklasie innej niz
 * ta uruchomic funkcje sortowania bezparametrycznie
 */
	void quick_sort(){ quicksort(lewy, prawy);}
/*!
 *
 *\brief Funkcja zamieniania wartosci
 *
 * Funkcja zamienia wartosciami obiekty, ktore sa argumentami funkcji
 * \param x -> Pole typu *int, zawiera adres obiektu, ktorego wartosc ma byc zamieniona z obiektem y\n
 * \param y -> Pole typu *int, zawiera adres obiektu, ktorego wartosc ma byc zamieniona z obiektem x
 */
	void swap(int *x, int *y);
/*!
 *
 *\brief Funkcja wypelniajaca stos losowymi wartosciami.
 *
 * Funkcja wypelnia stos losowymi wartosciami. Uzytkownik wybiera sam ile elementow ma zostac wpisanych
 */
	void wypelnij_losowo();
/*!
 *
 *\brief Funkcja zerujaca stos.
 *
 * Funkcja kasuje dynamicznie zaalokowana tablice dane, zeby mozna
 * bylo wpisac kolejna tablice z tymi samymi wartosciami
 * Dodatkowo zeruje pola klasy zwiazane z ową tablica
 */
	void wyzeruj_stos();
/*!
 *
 *\brief Funkcja zerujaca caly stos.
 *
 * Funkcja kasuje wszystkie dynamicznie zaalokowane obiekty.
 * Dodatkowo zeruje wszystkie pola klasy stos_tablica
 */
	void wyzeruj_stos_caly();
/*!
 *
 *\brief Funkcja dostepu do prywantego pola klasy lewy
 *
 *\return lewy -> obiekt typu int, indeks pierwszego elementu stosu ( zazwyczaj 0 )
 */
	int get_lewy(){return lewy;}
/*!
 *
 *\brief Funkcja dostepu do prywantego pola klasy prawy
 *
 *\return prawy -> obiekt typu int, indeks ostatniego elementu stosu ( zazwyczaj rowne rozmiarowi )
 */
	int get_prawy(){return prawy;}
/*!
 *
 *\brief Funkcja sortujaca.
 *
 * Funkcja sortuje dane za pomoca algorytmu Merge Sort  
 *
 *\param pocz -> Pole typu int, zawiera informacje indeksie poczatkowym sortowanego zbioru\n
 *\param kon -> Pole typu int, zawiera informacje indeksie koncowym sortowanego zbioru
 */
	void mergesort(int pocz, int kon);
/*!
 *
 *\brief Funkcja wywolujaca funkcje sorujaca Merge Sort.
 *
 * Funkcja jest tylko po to, aby mozna bylo w klasie innej niz
 * ta uruchomic funkcje sortowania bezparametrycznie
 */
	void merge_sort(){ mergesort(0, rozmiar-1);}
/*!
 *
 *\brief Funkcja budujaca kopiec ( Heap ).
 *
 * Funkcja tworzy kopiec z wstepnie posortowanymi danymi.
 * Reszta zostanie posortowana przy jego rozbieraniu.
 */
	void build_heap();
/*!
 *
 *\brief Funkcja rozbierajaca kopiec ( Heap ).
 *
 * Funkcja rozbiera kopiec, jednoczesnie sortujac dane.
 */
	void disassemble_heap();
/*!
 *
 *\brief Funkcja wywolujaca funkcje sorujaca Heap Sort.
 *
 * Funkcja jest tylko po to, aby mozna bylo w klasie innej niz
 * ta uruchomic funkcje sortowania jednym poleceniem
 */
	void heap_sort(){ build_heap(); disassemble_heap(); };
/*!
 *
 *\brief Funkcja przypisujaca.
 *
 * Funkcja przypisuje wartosci dynamicznej, pomocniczej tabeli danetmp
 * do tabeli glownej programu -> dane
 */
	void przypisz();

};

#endif 

