#ifndef GRAF_HH_INCLUDED
#define GRAF_HH_INCLUDED
/*!
 *\file
 *\brief Definicje funkcji dla klasy graf.
 *
 */
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <fstream>


using namespace std;
/*!
 *\brief Rodzaje wierzcholkow
 * Zdefiniowanie 3 roznych rodzajow wierzcholka :
 * -> normalne dla wierzcholkow wolnych,
 * -> sciana dla wierzcholkow bedacych przeszkodą,
 * -> punkt dla wierzcholkow, ktore sa punktami poczatkowymi i koncowymi.
 */
typedef enum
{
	normalne, 

	sciana, 

	punkt

}Wierzcholek_Typ;
/*!
 *\brief Struktura punktu
 * Struktura ta ma zdefiniowane dwie zmienne x oraz y, ktore
 * odpowiadaja za przechowywanie pozycji na siatce.
 * Rowniez zdefiniowane sa operator przypisania oraz operator logiczny relacji.
 */
struct Punkt
{
/*!
	 * \brief Pole typu int, bedzie uzywane do przechowywania wspolrzednej x-owej.
	*/
	int x;
/*!
	 * \brief Pole typu int, bedzie uzywane do przechowywania wspolrzednej y-kowej.
	*/
	int y;
	/*!
	*\brief Zdefiniowany operator porownania.
	* Jezeli zmienne x i y sa rowne wspolrzednym tych zmiennych to zwracana jest wartosc 1.
	*/
	bool operator == (Punkt wsp)
	{
		return x == wsp.x && y == wsp.y;
	}
	/*!
	*\brief Zdefiniowany operator relacji.
	*/
	bool operator != (Punkt wsp)
	{
		return !(*this == wsp);
	}
};
/*!
*\brief Struktura Wierzcholek.
* Opisuje wlasnosci wierzcholka.
*/
struct Wierzcholek{
/*!
	 * \brief Pole typu Wierzcholek_Typ, bedzie uzywane do przechowywania informacji o typie wierzcholka.
	*/
	Wierzcholek_Typ typ;
/*!
	 * \brief Pola typu int, beda uzywane do przechowywania wartosci funkcji f, g oraz h.
	*/
	int f, g, h;
/*!
	 * \brief Pole typu Punkt, bedzie uzywane do odnoszenia sie do aktualnego punktu na ukladzie.
	*/
	Punkt punkt;
/*!
	 * \brief Pole typu Punkt, bedzie uzywane do odnoszenia sie do porzpedniego punktu na ukladzie.
	*/
	Punkt rodzic;
};
/*!
 *
 *\brief Modeluje pojecie graf.
 * Klasa sluzy glownie do wykonania algorytmu a_star, czyli 
 * znalezienia najlepszej drogi miedzy dwoma punktami.
 *
 */
class graf{
/*!
	 * \brief Pole typu Punkt, bedzie uzywane do przechowywania informacji o punkcie poczatkowym.
	*/
		Punkt poczatek;
/*!
	 * \brief Pole typu Punkt, bedzie uzywane do przechowywania informacji o punkcie koncowym.
	*/
		Punkt koniec;
/*!
 *\brief Funkcja tworzaca sciane.
 * Funkcja tworzy sciane, przez ktora algorytm nie moze przejsc. 
 * Jest zmuszony do szukania drogi obok
 * \param startX
 * \param startY
 * \param stopX
 * \param stopY
 */
		void Stworz_Sciane(int startX, int startY, int stopX, int stopY);
/*!
 *\brief Funkcja ustawiajace punkty do znalezienia.
 * Funkcja ustala wspolrzedne punkty poczatkowego oraz koncowego.
 * Nastepnie przydziela je do danego typu wierzcholka.
 * \param startX
 * \param startY
 * \param stopX
 * \param stopY
 */
		void Ustaw_punkty(int startX, int startY, int stopX, int stopY);
/*!
 *\brief Funkcja heurestyczna.
 * Funkcja oblicza przyblizona droge jaka algorytm musi przejsc, aby odnalezc cel.
 */
		void H();
/*!
 *\brief Funkcja obliczajaca poniesiony.
 * Funkcja oblicza koszt poniesiony miedzy wierzcholkiem poczatkowym a obecnym punktem.
 */
		void G();
/*!
 *\brief Funkcja obliczajaca wspolczynnik f.
 * Wspolczynnik ten to suma arytmetyczna wspolczynnika g i h.
 * Na podstawie tego algorytm A_star wybiera wierzcholek o najnizszym wspolczynniku
 * przez ktory przeszukuje graf.
 */
		void F();
/*!
 *\brief Funkcja heurestyczna obliczajaca droge o zdanym punkcie.
 * \param _w
 */
		void H(Punkt _w);
/*!
 *\brief Funkcja obliczajaca wspolczynnik f o zadanym punkcie.
 * \param _w
 */
		void F(Punkt _w);
/*!
 *\brief Funkcja interpretujaca rozwiazanie przeszukiwania przez algorytm.
 */
		void Rozwiazanie();

	public:
/*!
	 * \brief Pole typu vector<vector<>>, bedzie uzywane do przechowywania informacji o wierzcholku.
	*/
		vector< vector<Wierzcholek> > w;
/*!
 *
 *\brief Konstruktor klasy graf.
 *
 * Konstruktor jest parametryczny. Parametrem tym jest rozmiar, ktory dediniuje
 * rozmiar siatki i tym razem ilosc wierzcholkow ( rozmiar^2 ).
 * Nastepnie pozwala ustawic sciane w dowolnym miejscu oraz dowolnie wybrac
 * punkty : poczatkowy i koncowy.
 * \param rozmiar
 */
		graf(int rozmiar);
/*!
 *\brief Zdefiniowany operator wyswietlania
 * Operator wypisuje na wyjsciu utworzone dane.
 * \return wyjscie 
 */
		friend ostream& operator << (ostream& wyjscie, graf& zmienna)
		{
			for(unsigned int i = 0; i < zmienna.w.size(); i++)
			{
				for(unsigned int j = 0; j < zmienna.w.size(); j++)
				{
					wyjscie << zmienna.w[i][j].typ << " ";
				}
				wyjscie << endl;
			}
		return wyjscie;
		}
/*!
 *\brief Funkcja A_star.
 * Funkcja implementujaca algorytm przeszukiwania A_star.
 * Wywolywana bezparametrycznie, poniewaz punkt poczatkowy
 * jak i koncowy ustalane sa w konstruktorze klasy graf.
 */
		void A_star();

};
#endif
