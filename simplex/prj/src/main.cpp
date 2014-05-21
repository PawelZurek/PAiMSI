/*!
 *\file
 *\brief
 *
 *Plik zawiera funkcje main() 
 *
 */
#include <iostream>
#include "../inc/simplex.hh"

using namespace std;

int main(){
	simplex s;

	s.wprowadz_dane();
	s.wyswietl();
	s.oblicz();


	return 0;
}