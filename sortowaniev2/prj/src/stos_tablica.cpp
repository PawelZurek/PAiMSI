#include "../inc/stos_tablica.hh"
#include <iostream>

using namespace std;		


void stos_tablica::pokaz_elementy(){
		if (rozmiar !=0)
		{
			cout<<"Elementy stosu to :\n";
			for (int i = 0; i <rozmiar; i++)
			{
				cout<<dane[i]<<endl;
			}
		}
		else cout<<"Stos PUSTY ! "<<endl;

	}
	void stos_tablica::wczytaj_dane(){
	int tmp = 0, i =0;
	string nazwa;
	cout<<"Podaj nazwe pliku: ";
	cin>>nazwa;
   	nazwa="dane/"+nazwa;
	ifstream liczby(nazwa.c_str());
	if (!liczby){
        cout << "\n***********Nie mozna otworzyc pliku !!**********\n";
        getchar();
    }
    else{
    	liczby>>rozmiar_tmp;
    	if (rozmiar_tmp > 0){
    		danetmp = new int[rozmiar_tmp];
    		while (liczby>>tmp){
    		danetmp[i] = tmp;
    		i++;	
    		}
    	}
       		
    	}	
	}

void stos_tablica::wczytaj_dane(string nazwa){
	int tmp = 0, i =0 ;
   	nazwa="dane/"+nazwa;
	ifstream liczby(nazwa.c_str());
	if (!liczby){
        cout << "\n***********Nie mozna otworzyc pliku !!**********\n";
        getchar();
        exit(5);
        
    }
    else{
    	liczby>>rozmiar_tmp;
    	if (rozmiar_tmp > 0){
    		danetmp = new int[rozmiar_tmp];
    		while (liczby>>tmp){
    		danetmp[i] = tmp;
    		i++;	
    		}
    	}
       		
    	}
	}

void stos_tablica::przypisz(){
	if (rozmiar == 0)
	{
		rozmiar = rozmiar_tmp;
		dane = new int[rozmiar];
		lewy = 0;
		prawy = rozmiar;
		heap_size = rozmiar;
		for (int i = 0; i < rozmiar; i++)
		{
			dane[i] = danetmp[i];
		}
	}
}

void stos_tablica::wypelnij_losowo(){
    srand((unsigned)time(NULL));
    	if (rozmiar==0)
    	{
    		cout<<"podaj rozmiar : ";
        	cin>>rozmiar;
    	}
        
        dane = new int[rozmiar];
        lewy = 0;
        prawy = rozmiar -1;
        heap_size = rozmiar;
        for (int i = 0; i < rozmiar; i++)
        {
            dane[i] = 0+rand()%(rozmiar+1);
        }
}



void stos_tablica::wyzeruj_stos(){
	if (rozmiar>0)
	{
		delete [] dane;
		rozmiar = 0;
		prawy = 0;
		lewy = 0;
		heap_size = 0;
	}
}

void stos_tablica::wyzeruj_stos_caly(){
	if (rozmiar>0)
	{
		delete [] dane;
		rozmiar = 0;
		prawy = 0;
		lewy = 0;
		heap_size = 0;
	}
	if (rozmiar_tmp>0)
	{
		delete [] danetmp;
		rozmiar_tmp = 0;
	}
}

	void stos_tablica::quicksort( int left, int right ){
    int i = left;
    int j = right;
    int x = dane[( left + right ) / 2 ];
    do
    {
        while( dane[ i ] < x )
             i++;
        
        while( dane[ j ] > x )
             j--;
        
        if( i <= j )
        {
            swap( &dane[ i ], &dane[ j ] );
            
            i++;
            j--;
        }
    } while( i <= j );
    
    if( left < j ) quicksort( left, j );
    
    if( right > i ) quicksort( i, right );
    
}

void stos_tablica::swap(int *x, int *y) { 
    int temp; 
    temp=*x; 
    *x=*y; 
    *y=temp; 
}

void stos_tablica::mergesort(int pocz, int kon){

	int polowa, l1, l2;
	int *tab_tmp;
	tab_tmp=0;
	tab_tmp = new int[rozmiar];
	polowa = (pocz + kon + 1) / 2;
	if(polowa - pocz > 1)
		mergesort(pocz, polowa - 1);
	if(kon - polowa > 0)
		mergesort(polowa, kon);
	l1 = pocz;
	l2 = polowa;
	for( int i = pocz; i <= kon; i++)
	{
		tab_tmp[i] = ((l1 == polowa) || ((l2 <= kon) && (dane[l1] > dane[l2]))) ? dane[l2++]: dane[l1++];
	}
	for(int i = pocz; i <= kon ; i++)
	{
		dane[i] = tab_tmp[i];
	}
	delete [] tab_tmp;
}

void stos_tablica::build_heap(){

	int temp=0, j=0, k=0;

	for(int i = 2; i <= rozmiar; i++)
	{
		j = i;
		k = j / 2;
		temp = dane[i];
		while((k > 0) && (dane[k] < temp))
		{
			dane[j] = dane[k];
			j = k;
			k = j / 2;
		}
		dane[j] = temp;
	}
}

void stos_tablica::disassemble_heap(){

	int m=0, j=0, k=0;

	for(int i = rozmiar; i > 1; i--)
	{
		swap(&dane[1], &dane[i]);
		j = 1;
		k = 2;
		while( k < i)
		{
			if((k + 1 < i) && (dane[k + 1] > dane[k]))
				m = k + 1;
			else
				m = k;
			if(dane[m] <= dane[j])
				break;
			swap(&dane[j], &dane[m]);
			j = m;
			k = j + j;
		}
	}
}


