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
#include "tab_hash.hh"
#include "stos_tablica.hh"


using namespace std;

/*!
 *
 *\brief Modeluje pojecie Benchmark.
 */

/*!
 *
 * Klasa sluzy do przeprowadzenia Benchmarku programu, tzn :
 * \n-> wczytania zestawu 100 elementow
 * \n-> Osobno dla trzech struktur danych :
 * \n  ->> Drzewo
 * \n  ->> Tablica Asocjacyjna
 * \n  ->> Tablica Hashujaca
 * \n->Liczony bedzie czas wyszukania dowolnego elemntu dla kazdej struktury
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
/*!
 *
 *\brief Funkcja wykonujaca algorytm.
 *
 * Wykonanie algorytmu ma przebieg :\n
 * -> posortowanie wybranego pliku trzema metodami: \n
		- Quick Sort
		- Merge Sort
		- Heap Sort
 * -> po każdym posortowaniu, obiekt jest całkowicie zerowany\n
 * -> wszystko to wykonuje się zadana przez uzytkownika ilosc razy \n
  */
	void algorytm();
/*!
 *
 *\brief Funkcja wyswietalnia wynikow
 *
 * Funkcja wyswietla wszystkie czasy liczone w programie. Tzn:
 * Czasy wszystkich wykonan dla kazdego sortowania, najwolniejsze, najszybsze oraz srednie wykonanie. Dodatkowo czas wykonania calej petli za kazdym razem
 * 
 * \param c -> wskaznik na zmienna typu double, przechowuje adres pola czasu calkowitego ( czasy )
 * \param q -> wskaznik na zmienna typu double, przechowuje adres pola czasu wykonywania Quick Sort ( quick )
 * \param m -> wskaznik na zmienna typu double, przechowuje adres pola czasu wykonywania Merge Sort ( merge )
 * \param h -> wskaznik na zmienna typu double, przechowuje adres pola czasu wykonywania Heap Sort ( heap )
 * \param n -> zmienna typu int, przechowuje adres pola, w ktorym jest informacja o tym ile razy zostal wykonany algorytm ( ile_razy )
 * \param s -> zmienna typu int, przechowuje adres pola rozmiaru tablicy ( size )
 */
	void wyswietl_wszystko(double h, double a, double d, int s);

	void stworz_plik(string typ, double *dane);

};


#endif 
