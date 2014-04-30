#ifndef DRZEWO_HH
#define DRZEWO_HH
/*!
 *\file
 *\brief Definicje funkcji dla klasy Drzewo.
 *
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class node{
private:
  string key;
  string wart;
  node *lewy;
  node *prawy;
public:
  node();
  ~node();

void pushuj(struct node *&korzen,string x,string w);

void showrek(struct node *korzen);

void wypelnij(string nazwa);

void UsunDrzewo (node *&wezel);

node*  ZnajdzWezel (node* wezel, string wartosc);

void znajduj();

};

#endif 

