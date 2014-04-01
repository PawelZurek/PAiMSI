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

	czas = 0;
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

void benchmark::algorytm(){
	stos_tablica tab;
	string nazwa[1];
	czas = 0;
	int ile_razy, size = 0;
	double *quick,*merge,*heap,*czasy;
	cout<<"Podaj nazwe pliku : ";
	cin>>nazwa[0];
	cout<<"Ile razy wykonac algorytm ? :";
	cin>>ile_razy;
	czasy=new double[ile_razy];
	quick=new double[ile_razy];
	merge=new double[ile_razy];
	heap=new double[ile_razy];
	
	for (int i = 0; i < ile_razy; i++){
		czas = 0;
		tab.wczytaj_dane(nazwa[0]);
		tab.przypisz();
		czas_start();
		tab.quick_sort();
		czas_stop();
		quick[i]=ile_czasu();
		czas = czas+ ile_czasu();
		tab.wyzeruj_stos_caly();
	
		tab.wczytaj_dane(nazwa[0]);
		tab.przypisz();
		czas_start();
		tab.merge_sort();
		czas_stop();
		merge[i]=ile_czasu();
		czas = czas+ ile_czasu();
		tab.wyzeruj_stos_caly();
	
		tab.wczytaj_dane(nazwa[0]);
		tab.przypisz();
		czas_start();
		tab.heap_sort();
		czas_stop();
		heap[i]=ile_czasu();
		czas = czas+ ile_czasu();
		size=tab.get_rozmiar();
		tab.wyzeruj_stos_caly();
		czasy[i] =czas;
		czas_caly=czas_caly+czas;
	}

	 wyswietl_wszystko(czasy,quick,merge,heap,ile_razy,size);
}

void benchmark::wyswietl_wszystko(double *c, double *q, double *m, double *h, int n, int s){
	double worst=0, medium=0, best=9999,all = 0;
	
	cout<<"Czasy sortowania za pomoca metody Quick Sort dla "<<s<<" elementow :\n";
	for (int i = 0; i < n; i++){
		cout<<i+1<<" Wykonanie->> "<<q[i]<<" ms "<<endl;
		all=all+q[i];
		medium=medium+q[i];
		if ( q[i] > worst) worst = q[i];
		if ( q[i] < best) best = q[i];

	}
	medium = medium/n;
	cout<<"\n Wyroznione wykonania dla metody Quick Sort : \n"
		<<" -> Najlepsze wykonanie : "<<best<<" ms "<<endl
		<<" -> Najgorsze wykonanie : "<<worst<<" ms "<<endl
		<<" -> Srednia czasu wykonania : "<<medium<<" ms "<<endl
		<<" -> Calkowity czas wykonania Quick Sort: "<<all<<" ms "<<endl;

	worst=0; medium=0; best=9999, all=0;
	
	cout<<"\nCzasy sortowania za pomoca metody Merge Sort dla "<<s<<" elementow :\n";
	for (int i = 0; i < n; i++){
		cout<<i+1<<" Wykonanie->> "<<m[i]<<" ms "<<endl;
		all=all+m[i];
		medium=medium+m[i];
		if ( m[i] > worst) worst = m[i];
		if ( m[i] < best) best = m[i];

	}

	medium = medium/n;
	cout<<"\n Wyroznione wykonania dla metody Merge Sort : \n"
		<<" -> Najlepsze wykonanie : "<<best<<" ms "<<endl
		<<" -> Najgorsze wykonanie : "<<worst<<" ms "<<endl
		<<" -> Srednia czasu wykonania : "<<medium<<" ms "<<endl
		<<" -> Calkowity czas wykonania Merge Sort: "<<all<<" ms "<<endl;

	worst=0; medium=0; best=9999, all=0;
	
	cout<<"\nCzasy sortowania za pomoca metody Heap Sort dla "<<s<<" elementow :\n";
	for (int i = 0; i < n; i++){
		cout<<i+1<<" Wykonanie->> "<<h[i]<<" ms "<<endl;
		all=all+h[i];
		medium=medium+h[i];
		if ( h[i] > worst) worst = h[i];
		if ( h[i] < best) best = h[i];

	}

	medium = medium/n;
	cout<<"\n Wyroznione wykonania dla metody Heap Sort : \n"
		<<" -> Najlepsze wykonanie : "<<best<<" ms "<<endl
		<<" -> Najgorsze wykonanie : "<<worst<<" ms "<<endl
		<<" -> Srednia czasu wykonania : "<<medium<<" ms "<<endl
		<<" -> Calkowity czas wykonania Heap Sort: "<<all<<" ms "<<endl;

	worst=0; medium=0; best=9999, all=0;
	
	
	cout<<"\nCalkowity czas wykonywania dla "<<s<<" elementow to : \n";
	for (int i = 0; i < n; i++)
		cout<<i+1<<" Wykonanie->> "<<c[i]<<" ms "<<endl;

	cout<<"\nCalkowity czas wykonywania to : "<<czas_caly<<" ms "<<endl;


} 