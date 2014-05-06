#ifndef GRAF_HH
#define GRAF_HH
/*!
 *\file
 *\brief Definicje funkcji dla klasy Drzewo.
 *
 */

#include <iostream>
#include <iomanip>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "stos_lista.hh"
#include "kolejka_lista.hh"

using namespace std;

class graf{
private:
  int n; //ilosc wierzcholkow
  int m; // ilosc krawedzi
  string *wartosci; //wartosci wierzcholkow
  int *wagi;// wagi krawedzi
  int **tab;//tablica polaczen
  int *wierzcholki;
  bool *odwiedzony;
  stos_lista stos;

public:
  graf(int liczba_wierz);
  ~graf();
  
  void ustaw_polaczenia();

  void dodaj_wartosci();

  void dodaj_wagi();

  void wyswietl();

  void wyswietl_wartosci();

  void wyswietl_wagi();

  void wyswietl_wszystko();

  bool czy_sasiad(int v1,int v2);

  void sasiedzi(int v);

  void sasiedztwo();

  void dodaj_wierzcholek();

  void usun_wierzcholek(int v);

  void usuwanie_wierzcholka();

  void dodawanie_krawedzi();

  void dodaj_krawedz(int v1, int v2, int e);

  void usuwanie_krawedzi();

  void usun_krawedz( int v1, int v2 );

  void wypelnij_zerami();

  void ilosc_wierzcholkow();

  void wyswietl_wierzcholki();

  void dfs(int v);

  void depth();

  void bfs(int v);

  void breth();  

  void storz_tab_odw();

  void usun_tab_odw();

  void wypelnianie();
  /*

  int nastepny_dfs(int v);

  void wyszukanie_depth();

  void szukajcie(int v1, int v2);

  void szukaj();

  void nastepny( int v1, int v2);*/

};


#endif 