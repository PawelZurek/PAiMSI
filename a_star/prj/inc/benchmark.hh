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
#include "graf.hh"


using namespace std;

/*!
 *
 *\brief Modeluje pojecie Benchmark.
 */

/*!
 *
 * Klasa sluzy do przeprowadzenia Benchmarku programu, tzn :
 * \n-> przeliczenia czasu wykonywania algorytmu A_star, dla :
 * \n * 100 wiercholkow
 * \n * 400 wiercholkow
 * \n * 900 wiercholkow
 * \n * 1600 wiercholkow
 * \n * 2500 wiercholkow
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
	 * \brief Pole typu double, bedzie uzywane do mierzenia calkowitego czasu dzialania programu. !
	*/
  double czas_caly;
  /*!
	 * \brief Pole typu timeval, pomoc do liczenia czasu dzialania operacji krotkich ( tzn pojedynczego dzialania)
	*/
  timeval t1, t2;

  string tmp;

int size;

public:
/*!
 *
 *\brief Konstruktor klasy Benchmark.
 *
 * Konstruktor jest bezparametryczny, inicjalizuje wszystkie skladowe
 * klasy wartosciami zerowymi.
 *
 */
	benchmark(){ elapsedTime=0, czas = 0, size = 100, czas_caly = 0; }
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
 * -> stworzenie grafow o roznych ilosciach wierzcholkow: \n
 * -> zbadanie czasu wykonywania\n
 * -> zapisanie czasow do pliku \n
  */
	void algorytm();

};


#endif 
