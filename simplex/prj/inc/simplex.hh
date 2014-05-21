#ifndef SIMPLEX_HH
#define SIMPLEX_HH
/*!
 *\file
 *\brief Definicje funkcji dla klasy simplex.
 *
 */
#include <iostream>

using namespace std;

/*!
 *
 *\brief Modeluje pojecie Simplex.
 * Klasa sluzy do wykonania uprostrzonego algorytmu simplex tzn :
 * -> znalezienia najwiekszego zysku z funkcji celu
 *
 */

class simplex{
private:
/*!
	 * \brief Pole typu **double, bedzie uzywane do przechowywania macierzy ukladu rownan.
	*/
	double **tab;
/*!
	 * \brief Pole typu *double, bedzie uzywane do przechowywania ograniczen poszczegolnych rowan.
	*/
	double *ograniczenia;
/*!
	 * \brief Pole typu int, bedzie uzywane do przechowywania kosztow 2och zmiennych.
	*/
	int koszt[2];
/*!
	 * \brief Pole typu double, bedzie uzywane do liczenia najlepszego zysku.
	*/
	double zysk[7];
/*!
	 * \brief Pole typu int, bedzie uzywane do przechowywania ilosci rownan.
	*/
	int n;
/*!
	 * \brief Pola typu double, beda uzywane do zapisywania pozycji kluczowych punktow.
	*/
	double y[4],x[4];
public:
/*!
 *
 *\brief Konstruktor klasy simplex.
 *
 * Konstruktor jest bezparametryczny, inicjalizuje wszystkie skladowe
 * klasy wartosciami zerowymi.
 *
 */
	simplex();
/*!
 *
 *\brief Destruktor klasy simplex.
 *
 * Konstruktor jest bezparametryczny, usuwa wszystkie zmienne zaalokowane dynamicznie.
 *
 */
	~simplex();
/*!
 *
 *\brief Funkcja do wprowadzania danych
 * 
 * Dzialanie funkcji:
 * -> wpisanie ilosci rownan
 * -> wpisanie poszczegolnych wspolczynnikow
 * -> wpisanie poszczegolnych ograniczen
 * -> wpisanie poszczegolnych kosztow
 */
	void wprowadz_dane();
/*!
 *
 *\brief Funkcja wyswietaljaca uklad rownan
 * 
 * Dzialanie funkcji:
 * -> wyswietlenie wynikow :
 *   - zmienne z wspolczynikami
 *   - oraniczenia dla danego rownania
 */
	void wyswietl();
/*!
 *
 *\brief Funkcja liczaca najlepszy zysk
 * 
 * Dzialanie funkcji:
 * -> obliczenie kluczowych punktow
 * -> obliczenie wartosci zysku w tych punktach
 * -> wybor punktu,  w ktorym zysk jest najlepszy
 * -> wyswietlenie wynikow :
 *   - wartosc zysku
 *   - punkty, dla ktorych ten zysk jest osiagniety
 */
	void oblicz();
};


#endif