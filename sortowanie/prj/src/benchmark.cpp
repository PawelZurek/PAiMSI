/*!
 *\file
 *\brief
 *
 *Plik zawiera funkcje z klasy benchmark
 *
 */
#include "../inc/benchmark.hh"

#include <iostream>

using namespace std;

void benchmark::czas_start(){
	gettimeofday(&t1, NULL);
}
void benchmark::czas_stop(){
	gettimeofday(&t2, NULL);
}
double benchmark::ile_czasu(){
	elapsedTime = (t2.tv_sec - t1.tv_sec)*1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	//cout <<"Czas operacji: " << elapsedTime << "ms.\n";	
	return elapsedTime;
}

void benchmark::wykonaj_algorytn_sortowanie(){
	stos_tablica tab;
	
	

	double quick[6], merge[6], heap[6];


	string nazwa[6];
	nazwa[0]="losowo10.txt";
	nazwa[1]="losowo100.txt";
	nazwa[2]="losowo1000.txt";
	nazwa[3]="losowo10000.txt";
	nazwa[4]="losowo100000.txt";
	nazwa[5]="losowo1000000.txt";

	for (int i = 0; i < 6; i++)
	{
		tab.wczytaj_dane(nazwa[i]);
		tab.przypisz();
		czas_start();
		tab.quick_sort();
		czas_stop();
		quick[i]=ile_czasu();
		czas = czas+ ile_czasu();
		tab.wyzeruj_stos_caly();
	}

	for (int i = 0; i < 6; i++)
	{
		tab.wczytaj_dane(nazwa[i]);
		tab.przypisz();
		czas_start();
		tab.merge_sort();
		czas_stop();
		merge[i]=ile_czasu();
		czas = czas+ ile_czasu();
		tab.wyzeruj_stos_caly();
	}

	for (int i = 0; i < 6; i++)
	{
		tab.wczytaj_dane(nazwa[i]);
		tab.przypisz();
		czas_start();
		tab.heap_sort();
		czas_stop();
		heap[i]=ile_czasu();
		czas = czas+ ile_czasu();
		tab.wyzeruj_stos_caly();
	}

	
	cout<<"Czasy sortowania za pomoca metody Quick Sort:\n";
	for (int i = 0; i < 6; i++)
	{
		cout<<" ("<<10*pow( 10, i )<<" elementow) ->> "<<quick[i]<<" ms "<<endl;
	}

	cout<<"Czasy sortowania za pomoca metody Merge Sort:\n";
	for (int i = 0; i < 6; i++)
	{
		cout<<" ("<<10*pow( 10, i )<<" elementow) ->> "<<merge[i]<<" ms "<<endl;
	}

	cout<<"Czasy sortowania za pomoca metody Heap Sort:\n";
	for (int i = 0; i < 6; i++)
	{
		cout<<" ("<<10*pow( 10, i )<<" elementow) ->> "<<heap[i]<<" ms "<<endl;
	}
	
	cout<<" Calkowity czas wykonywania to : "<<czas<<" ms "<<endl;

}

