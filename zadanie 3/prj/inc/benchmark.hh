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
#include "kolejka_tablica.hh"
#include "kolejka_lista.hh"
#include "stos_tablica.hh"
#include "stos_lista.hh" 

using namespace std;

/*!
 *
 *\brief Modeluje pojecie Benchmark.
 */

/*!
 *
 * Klasa sluzy do przeprowadzenia Benchmarku programu, tzn :
 * -> wczytania 4 zestawu danych o ilosci elementow :
 *   \n-> 10
 *   \n-> 100
 *   \n-> 1000 
 *   \n-> 10000
 * \n Na czterech klasach :
 * \n	-> stos_lista
 * \n	-> stos_tablica
 * \n	-> kolejka_lista
 * \n	-> kolejka_tablica
 * \n-> Na koniec zostana wyswietlone czasy kazdej akcji z osobna
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
 *\brief Funkcja wykonujaca algorytm
 * 
 * Dzialanie funkcji:
 * \n-> stworzenie obiektow klas :
 *	\n	*stos_lista
 *	\n	*stos_tablica
 *	\n	*kolejka_lista
 *	\n	*kolejka_tablica
 * \n-> wypelniana jest wartosciami z plikow z :
 *	\n	* 10 elementami 
 *	\n	* 100 elementami
 *	\n	* 1000 elementami
 *	\n	* 10000 elementami 
 * \n-> wyswietlenie wynikow :
 *   \n- czasu dzialania po kolei kazdego wypelnienia z osobna
 *   \n- czasu dzialania calego algorytmu
 */
	void wykonaj_algorytn();

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

};


#endif 
