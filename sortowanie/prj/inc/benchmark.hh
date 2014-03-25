#ifndef BENCHMARK_HH
#define BENCHMARK_HH
/*!
 *\file
 *\brief Definicje funkcji dla klasy benchmark.
 *
 */
#include <fstream>
#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include "stos_tablica.hh"

using namespace std;

/*!
 *
 *\brief Modeluje pojecie Benchmark.
 */

/*!
 *
 * Klasa sluzy do przeprowadzenia Benchmarku programu, tzn :
 * -> wczytania 6 zestawu danych o ilosci elementow :
 *   \n-> 10
 *   \n-> 100
 *   \n-> 1000 
 *   \n-> 10000
 *   \n-> 100000
 *   \n-> 1000000
 * \n Trzema roznymi metodami :
 * \n	-> Quick Sort
 * \n	-> Merge Sort
 * \n	-> Heap Sort
 * \n-> Na koniec zostana wyswietlone czasy kazdej akcji z osobna oraz czas calkowity
 */

class benchmark{
	
private:
/*!
	 * \brief Pole typu double, bedzie uzywane do mierzenia czasu dzialania pojedynczego wypelniania 
	*/
  double elapsedTime;
/*!
	 * \brief Pole typu double, bedzie uzywane do mierzenia calkowitego czasu dzialania programu.
	*/
  double czas;
  /*!
	 * \brief Pole typu timeval, pomoc do liczenia czasu dzialania operacji krotkich ( tzn pojedynczego dzialania)
	*/
  timeval t1, t2;


public:
/*!
 *
 *\brief Konstruktor klasy Benchmark.
 *
 * Konstruktor jest bezparametryczny, inicjalizuje wszystkie skladowe
 * klasy wartosciami zerowymi.
 *
 */
	benchmark(){ elapsedTime=0, czas = 0;}
/*!
 *
 *\brief Funkcja pomocnicza mierzenia czasu
 *
 * Funkcja zaczyna liczyc czas od momentu wywolania tej metody
 * Sluzy do liczenia czasu wykonywania pojedynczego wypelniania stosu/kolejki
 */
	void czas_start();

/*!
 *
 *\brief Funkcja pomocnicza mierzenia czasu
 *
 * Funkcja konczy liczyc czas od momentu wywolania tej metody
 * Sluzy do liczenia czasu wykonywania pojedynczego wypelniania stosu/kolejki
 */

	void czas_stop();
/*!
 *
 *\brief Funkcja obliczania czasu dzialania programu
 *
 * Funkcja podaje czas wykonywania pojedynczego wypelniania stosu/kolejki
 * 
 * \return elapsedTime -> zmienna typu double ( wynik obliczen )
 */

	double ile_czasu();
/*!
 *
 *\brief Funkcja wykonujaca algorytm.
 *
 * Wykonanie algorytmu ma przebieg :\n
 * -> posortowanie danych metoda Quick Sort\n
 * -> posortowanie danych metoda Merge Sort\n
 * -> posortowanie danych metoda Heap Sort\n
 * \n Dla :\n
 * -      10 elementow \n
 * -     100 elementow \n
 * -    1000 elementow \n
 * -   10000 elementow \n
 * -  100000 elementow \n
 * - 1000000 elementow \n
  */
	void wykonaj_algorytn_sortowanie();

};


#endif 
