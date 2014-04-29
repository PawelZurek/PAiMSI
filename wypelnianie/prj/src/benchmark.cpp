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

void benchmark::wykonaj_algorytn(){
	kolejka_lista KL;
	kolejka_tablica KT, KTx2;
	stos_tablica ST, STx2;
	stos_lista SL;
	double czasKL[4], czasKT[4], czasST[4], czasSL[4];
	double czasKTx2[4], czasSTx2[4];

	string nazwa[4];
	nazwa[0]="liczby.txt";
	nazwa[1]="liczby100.txt";
	nazwa[2]="liczby1000.txt";
	nazwa[3]="liczby10000.txt";

	for (int i = 0; i < 4; i++)
	{
		czas_start();
		KL.wczytaj_dane(nazwa[i]);
		czas_stop();
		czasKL[i]=ile_czasu();
		czas = czas+ ile_czasu();
	}

	for (int i = 0; i < 4; i++)
	{
		czas_start();
		KT.wczytaj_dane(nazwa[i]);
		czas_stop();
		czasKT[i]=ile_czasu();
		czas = czas+ ile_czasu();
	}

	for (int i = 0; i < 4; i++)
	{
		czas_start();
		ST.wczytaj_dane(nazwa[i]);
		czas_stop();
		czasST[i]=ile_czasu();
		czas = czas+ ile_czasu();
	}

	for (int i = 0; i < 4; i++)
	{
		czas_start();
		SL.wczytaj_dane(nazwa[i]);
		czas_stop();
		czasSL[i]=ile_czasu();
		czas = czas+ ile_czasu();
	}

	for (int i = 0; i < 4; i++)
	{
		czas_start();
		STx2.wczytaj_danex2(nazwa[i]);
		czas_stop();
		czasSTx2[i]=ile_czasu();
		czas = czas+ ile_czasu();
	}

	for (int i = 0; i < 4; i++)
	{
		czas_start();
		KTx2.wczytaj_danex2(nazwa[i]);
		czas_stop();
		czasKTx2[i]=ile_czasu();
		czas = czas+ ile_czasu();
	}

	cout<<"Czasy zapelniania kolejki za pomoca Listy:\n";
	for (int i = 0; i < 4; i++)
	{
		cout<<" ("<<10*pow( 10, i )<<" elementow) ->> "<<czasKL[i]<<" ms "<<endl;
	}
	cout<<"\nCzasy zapelniania kolejki za pomoca Tablicy:\n";
	for (int i = 0; i < 4; i++)
	{
		cout<<" ("<<10*pow( 10, i )<<" elementow) ->> "<<czasKT[i]<<" ms"<<endl;
	}
	cout<<"\nCzasy zapelniania kolejkiza pomoca Tablicy (rozmiar powiekszany dwu krotnie):\n";
	for (int i = 0; i < 4; i++)
	{
		cout<<" ("<<10*pow( 10, i )<<" elementow) ->> "<<czasKTx2[i]<<" ms"<<endl;
	}
	cout<<"\nCzasy zapelniania stosu za pomoca Listy\n";
	for (int i = 0; i < 4; i++)
	{
		cout<<" ("<<10*pow( 10, i )<<" elementow) ->> "<<czasSL[i]<<" ms"<<endl;
	}
	cout<<"\nCzasy zapelniania stosu za pomoca Tablicy\n";
	for (int i = 0; i < 4; i++)
	{
		cout<<" ("<<10*pow( 10, i )<<" elementow) ->> "<<czasST[i]<<" ms"<<endl;
	}
	cout<<"\nCzasy zapelniania stosu za pomoca Tablicy (rozmiar powiekszany dwu krotnie):\n";
	for (int i = 0; i < 4; i++)
	{
		cout<<" ("<<10*pow( 10, i )<<" elementow) ->> "<<czasSTx2[i]<<" ms"<<endl;
	}

	cout<<"\n\nCzasy dzialania calego programu to : "<<czas<<" ms"<<endl;
}

