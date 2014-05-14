#ifndef GRAF_HH
#define GRAF_HH
/*!
 *\file
 *\brief Definicje funkcji dla klasy Drzewo.
 *
 */

#include <iostream>
#include <iomanip>
#include <string>
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
  stos_lista otwarte;
  stos_lista zamkniete;
  stos_lista punkty_odwiedzone;
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

  void sasiedztwo(int v);

  void sasiedztwo();

  void dodaj_wierzcholek();

  void usuwanie_wierzcholka(int v);

  void usuwanie_wierzcholka();

  void dodawanie_krawedzi();

  void dodawanie_krawedzi(int v1, int v2, int e);

  void usuwanie_krawedzi();

  void usuwanie_krawedzi( int v1, int v2 );

  void dodaj_wagi( int v1, int v2 , int waga);

  void wypelnij_zerami();

  void ilosc_wierzcholkow();

  int get_wierzcholki();

  void wyswietl_wierzcholki();

  void dfs(int v);

  void dfs();

  void bfs(int v);

  void bfs();  

  void storz_tab_odw();

  void usun_tab_odw();

  void losuj_polaczenia();

  void losuj_polaczenia(int proc);

  void usun_wszystko();

  string oblicz_F_G_H(int indeks);

  void a_star(int start, int koniec);

  void a_star();

  int zdobadz_G(int indeks);

  int zdobadz_F(int indeks);

  int znajdz_g(string tmp);

  int znajdz_f(string tmp);

  int oblicz_H(int indeks);

  int oblicz_G();

  int znajdz_najmniejsze_f();

  int przejdz_do_nastepnego(int indeks);

};

int strToInt(string s);

  string intToStr(int n);

#endif 