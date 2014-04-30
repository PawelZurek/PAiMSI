#ifndef TAB_HASH_HH
#define TAB_HASH_HH
/*!
 *\file
 *\brief Definicje funkcji dla Tablicy Hashujacej
 *
 */
#include <fstream>
#include <iostream>


using namespace std;

class tab_hash{
private:
	int rozmiar;
	int ilosc;
	string *dane;
public:
	tab_hash(int n){
		rozmiar=n, ilosc = 0,
		dane= new string[rozmiar];
		};
	~tab_hash(){
		delete [] dane;
		};

	bool pusta();

	int size();

	void zaczynamy();

	int hash_function(string s);

	void przydziel(int n, string w);

	void wyswietl();

	void pokaz(string s, int n);

	void znajdz();

	void usun();

	void usuwanie(string s);

	void wypelnij(string nazwa);
	
};

#endif 
