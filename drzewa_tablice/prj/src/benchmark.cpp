/*!
 *\file
 *\brief
 *
 *Plik zawiera funkcje z klasy benchmark
 *
 */
#include "../inc/benchmark.hh"
#include "test.cpp"
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

void benchmark::algorytm(){

	string znaki[100];
	tab_hash tab(size);
	stos_tablica tab1;
	double *ha,hash=0,*as,asoc=0,*dr,drzewo=0;

	ha = new double[size];
	as = new double[size];
	dr = new double[size];

	string nazwa="dane/test.txt";
	int j=0;
	ifstream liczby(nazwa.c_str());
	if (!liczby){
        cout << "\n***********Nie mozna otworzyc pliku !!**********\n";
    }
    else
    	while (liczby>>znaki[j])
    		j++;

	tab.wypelnij("test.txt");
	//tab.wyswietl();
	tab1.wypelnij("test2.txt");
	wypelniaj("test2.txt");

	for (int i = 0; i < size; i++){
		czas_start();
		tab.pokaz(znaki[i],tab.hash_function(znaki[i]));
		czas_stop();
		ha[i]=ile_czasu();
		hash=ile_czasu()+hash;
		czas = czas+ ile_czasu();
	}

	for (int i = 0; i < size; i++){
		czas_start();
		tab1.szukaj(znaki[i]);
		czas_stop();
		as[i]=ile_czasu();
		asoc=ile_czasu()+asoc;
		czas = czas+ ile_czasu();
	}

	for (int i = 0; i < size; i++){
		czas_start();
		ZnajdzWezel(korzen,znaki[i]);
		czas_stop();
		dr[i]=ile_czasu();
		drzewo=ile_czasu()+drzewo;
		czas = czas+ ile_czasu();
	}

	wyswietl_wszystko(hash,asoc,drzewo,size);
	stworz_plik("hash",ha);
	stworz_plik("asoc",as);
	stworz_plik("drzewo",dr);


	delete [] ha;
	delete [] as;
	delete [] dr;

}

void benchmark::wyswietl_wszystko(double h, double a, double d, int s){
	cout<<"\nCzas znalezienia slow w zbiorze tablicy hashujacej zawierajacej "<<s<<" elementow : ";
	cout<<h<<" ms "<<endl;

	cout<<"\nCzas znalezienia slow w zbiorze tablicy asocjacyjej zawierajacej "<<s<<" elementow : ";
	cout<<a<<" ms "<<endl;

	cout<<"\nCzas znalezienia slow w zbiorze drzewa zawierajacego "<<s<<" elementow : ";
	cout<<d<<" ms "<<endl;

	cout<<"\nCalkowity czas wykonywania to : "<<czas<<" ms "<<endl;


} 

void benchmark::stworz_plik(string typ, double *dane){
	typ="dane/"+typ;
	ofstream plik(typ.c_str());
	if (size>0){		
		for (int i = 0; i < size; i++)
		{
			plik<<i+1<<"		"<<dane[i]<<endl;
		}
	}
}