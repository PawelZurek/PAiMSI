/*!
 *\file
 *\brief
 *
 *Plik zawiera funkcje main() 
 *
 */
#include <iostream>
#include <iomanip>
#include "../inc/graf.hh"
#include "../inc/benchmark.hh"

using namespace std;

int main()
{//do uzytkownika  : 
	int a=0;

	cout<<"Podaj rozmiar ukladu : ";
	cin>>a;
	graf g(a);


	g.A_star();

	cout<<"Uklad po wykonaniu wyszukiwania wyglada nastepujaco : "<<endl;
	cout<<g<<endl;

	//benchmark B; do benchmarku !!!!
	//B.algorytm();

	return 0;
}
