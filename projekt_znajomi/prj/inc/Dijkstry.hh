#ifndef DIJKSTRY_HH
#define DIJKSTRY_HH
#pragma once

/*!
 *\file
 *\brief Definicje funkcji dla klasy graf.
 *
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <queue>
#include <ctime>


using namespace std;

/*!
 *\brief Definicje dla klasy Wierzcholek
 * Struktura ta ma zdefiniowane dwie zmienne sasiad oraz waga. Przy wczytywaniu pliku
 * dodajac wierzcholek dodajemy odrazu informacje o aktualnym sasiedzie oraz
 * o wadze polaczenia miedzy wierzcholkiem i sasiadem.
 */
class Wierzcholek{
public:
/*!
	 * \brief Pole typu int, bedzie uzywane do numeru id sasiada dla danego wierzcholka.
	*/
	int sasiad;  // sasiad dla zadanego wierzcholka 
/*!
	 * \brief Pole typu int, bedzie uzywane do przechowywania informacji o wadze polaczenia.
	*/
	int waga;  // waga
/*!
 *
 *\brief Konstruktor klasy Wierzcholek.
 *
 * Konstruktor jest bezparametryczny.
 * Wykonuje wyzerowanie wszystkich skladowych wewnwetrznych klasy
 */
	Wierzcholek(){ sasiad = 0; waga = 0;  };
/*!
 *
 *\brief Funkcja przeciazajaca operator '='.
 *
 */
	Wierzcholek &operator= (Wierzcholek const& c1);
};
/*!
 *\brief Struktura Wezla
 * Struktura ta ma zdefiniowane dwie zmienne nr oraz g, ktore
 * odpowiadaja za przechowywanie numer wierzcholkana oraz droge jaka juz przebyl
 * od poczatku dzialania wyszukiwania
 */
struct Wezel{
/*!
	 * \brief Pole typu int, bedzie uzywane do przechowywania id wierzcholka.
	*/
	int nr; // numer wierzcholka
/*!
	 * \brief Pole typu int, bedzie uzywane do przechowywania informacji o przebytej drodze.
	*/
	int g; // droga 
};
/*!
 *
 *\brief Modeluje pojecie graf.
 * Klasa sluzy glownie do wykonania algorytmu wyszukiwania, czyli 
 * znalezienia polaczenia miedzy dwoma punktami.
 */
class Graf{
public:
/*!
	 * \brief Pole typu int, bedzie uzywane do przechowywania informacji o ilosci wierzcholkow.
	*/
	int V; // wierzcholki
/*!
	 * \brief Pole typu int, bedzie uzywane do przechowywania informacji o ilosci krawedzi (aktualnie nie uzywane w programie ).
	*/
	int E; // krawedzie
/*!
	 * \brief Pole typu * vector, bedzie uzywane do przechowywania informacji o sasiadach dla poszczegolnych wierzcholkow
	*/
	vector<Wierzcholek> *lista_sasiadujaca; // lista sasiadujaca 
/*!
	 * \brief Pole typu * int, bedzie uzywane jako wektor z prawdziwymi nazwami (id) wierzcholkow
	*/
	int * wierzcholki;
public:
/*!
 *
 *\brief Konstruktor klasy Graf.
 *
 * Konstruktor jest bezparametryczny.
 * Jedyne jego zadanie to zainicjalizowanie zmiennych wewnetrznych klasy Graf
 */
	Graf();
/*!
 *
 *\brief Destruktor klasy Graf.
 *
 * Destruktor jest bezparametryczny.
 * Jedyne jego zadanie to usuniecie obiektow zaalokowanych dynamicznie
 */
	~Graf();
/*!
 *
 *\brief Funkcja generujaca Graf.
 *
 * Funkcja typu void, na podstawie parametrow tworzy graf
 * o zadanej losci :
 * \param ilosc -> wartosc typu int przechowuje informacje o ilosci wierzchokow
 * \param gestosc -> wartosc typu int przechowuje informacje o gestosci polaczen w grafie
 */
	void generuj_liste(int ilosc, int gestosc);//funkcja pomocnicza do tworzenia Graf u
/*!
 *
 *\brief Funkcja tworzaca Graf z pliku.
 *
 * Funkcja typu void, tworzaca graf z pliku, gdzie sa podane polaczenia miedzy wierzcholkami ( tylko )
 * \param nazwapliku -> wartosc typu string przechowuje nazwe pliku 
 */
	void stworz_liste_z_pliku(string nazwapliku);//funkcja pomocnicza do tworzenia Graf u z pliku
/*!
 *
 *\brief Funkcja tworzaca wierzcholki Graf u z pliku.
 *
 * Funkcja typu void, tworzaca wierzcholki z pliku, gdzie sa podane tylko wierzcholki
 * \param nazwapliku -> wartosc typu string przechowuje nazwe pliku 
 */
	void stworz_wierzcholki(string nazwapliku);//funkcja pomocnicza do tworzenia Graf u z pliku
/*!
 *
 *\brief Funkcja przerabiajaca plik z bazy .
 *
 * Funkcja typu void, tworzaca wierzcholki z pliku, gdzie sa podane tylko wierzcholki
 * \param typ -> wartosc typu string przechowuje nazwe pliku wejsciowego, ktorego bedziemy obrabiac
 * \param wyjscie -> wartosc typu string przechowuje nazwe pliku przerobionego ( nowo stworzonego )
 */
	void przerob_z_fb( string typ ,string wyjscie);//funkcja pomocnicza do tworzenia Graf u  z pliku
/*!
 *
 *\brief Funkcja pomocnicza do main .
 *
 * Funkcja jest tak naprawde tylko po to aby plik main.cpp byl bardziej przejrzysty
 * Pyta o nazwe pliku, przerabia go, tworzy wierzcholki z niego i na koncu generuje polaczenia
 */	
	void dowolny_plik();//funkcja pomocnicza do main
/*!
 *
 *\brief Funkcja pomocnicza do main .
 *
 * Funkcja jest tak naprawde tylko po to aby plik main.cpp byl bardziej przejrzysty
 * Bierze domyslny plik (na chwile obecna jest to chyba plik fb.txt) i przerabia go, tworzy wierzcholki z niego i na koncu generuje polaczenia
 */
	void domyslny_plik();//funkcja pomocnicza do main
/*!
 *
 *\brief Funkcja pomocnicza do main .
 *
 * Funkcja jest tak naprawde tylko po to aby plik main.cpp byl bardziej przejrzysty
 * Bierze plik testowy ( test.txt ) przerabia go, tworzy wierzcholki z niego i na koncu generuje polaczenia
 */
	void testowy_plik();//funkcja pomocnicza do main
/*!
 *
 *\brief Funkcja pomocnicza do main .
 *
 * Funkcja jest tak naprawde tylko po to aby plik main.cpp byl bardziej przejrzysty
 * Losuje wierzcholki miedzy ktorymi algorytm bedzie szukal polaczenie i 
 * nastepnie uruchamia go z tymi wartosciami
 */	
	void losowe_dijkstry();//funkcja pomocnicza do main
/*!
 *
 *\brief Funkcja pomocnicza.
 *
 * Funkcja sprawdza czy graf jest spojny.
 * \return 1 -> gdy graf spojny
 		   0 -> gdy graf nie spojny
 */
	bool czy_spojny();//funkcja pomocnicza do poprawnego dzialania algorytmu
/*!
 *
 *\brief Funkcja pomocnicza.
 *
 * Funkcja sprawdza wierzcholki znajduja sie w wektorze z wierzcholkami.
 * \param a -> pole typu int z id drugiego wierzcholka 
 * \param b -> pole typu int z id pierwszego wierzcholka
 * \return 1 -> gdy wierzcholki sa w bazie
 		   0 -> gdy wierzcholkow nie ma w bazie
 */	
	bool czy_poprawne( int a, int b);//funkcja pomocnicza do poprawnego dzialania algorytmu
/*!
 *
 *\brief Funkcja pomocnicza.
 *
 * Funkcja sprawdza czy dane wierzcholki juz sa w bazie aby nie wpisywac ich ponownie
 * \param v1 -> pole typu int z id drugiego wierzcholka 
 * \param v2 -> pole typu int z id pierwszego wierzcholka
 * \return 1 -> gdy wierzcholki sa w bazie
 		   0 -> gdy wierzcholkow nie ma w bazie
 */	
	bool czy_bylo(int v1, int v2);//funkcja pomocnicza do poprawnego dzialania algorytmu
/*!
 *
 *\brief Funkcja pomocnicza.
 *
 * Funkcja sluzy do przypisania indeksu wierzcholkowi po podanym id
 * \param id -> pole typu int z id wierzcholka 
 * \return indeks -> mniejszy musi byc niz ilosc wierzcholkow
 */	
	int przypisz_indeks(int id);//funkcja pomocnicza do poprawnego dzialania algorytmu
/*!
 *
 *\brief Funkcja glowna programu wyszukujaca polaczenie.
 *
 * Funkcja wyszukuje polaczenie miedzy podanymi wierzcholkami
 * \param a -> pole typu int z id wierzcholka z ktorego szukamy polaczenia
 * \param b -> pole typu int z id wierzcholka do ktorego szukamy polaczenia
 * \return 1 -> gdy wystapi blad
 		   0 -> gdy bezblednie znajdzie polaczenie
 */	
	int dijkstry(int a, int b);//podstawowa funkcja klasy
/*!
 *
 *\brief Funkcja wyswietlajaca liste sasiedztwa grafu.
 *
 * Funkcja typu void wyswietla aktualny stan grafu.
 */	
	void wyswietl();//podstawowa funkcja klasy
	
};
/*!
 *\brief Struktura porownywania
 * Struktura ta ma na celu ulatwienie dzialania algorytmu wyszukiwania ( Dijkstry )
 * Prownuje ona wartosci drogi miedzy dwoma wezlami.
 */
struct por{
	bool operator ()(const Wezel & k1, const Wezel& k2)
	{
		//kolejność - rosnąco
		if (k1.g > k2.g) return true;

		if (k1.g < k2.g) return false;

		return false;
	}
};


#endif 