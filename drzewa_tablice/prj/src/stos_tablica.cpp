#include "../inc/stos_tablica.hh"
#include <iostream>

using namespace std;		
	bool stos_tablica::isEmpty(){
		if ( rozmiar == 0)
		{
			cout<<"Brak elentow"<<endl;
			return 1;
		}
		else {
			cout<<"Sa Elementy"<<endl;
			return 0;
		}
	}

int stos_tablica::size(){
		cout<<"Rozmiar to: "<<rozmiar<<endl;
		return rozmiar;
}

void stos_tablica::dodaj_element(){
	string k;
	string w;
	cout<<"Podaj klucz : ";
	cin>>k;
	cout<<"Podaj wartosc zapisana pod kluczem : ";
	cin>>w;
	push(k,w);
}

void stos_tablica::wypelnij(string nazwa){
	string tmp1, tmp2;
   	nazwa="dane/"+nazwa;
	ifstream liczby(nazwa.c_str());
	if (!liczby){
        cout << "\n***********Nie mozna otworzyc pliku !!**********\n";
    }
    else
    	while (liczby>>tmp1){
    		liczby>>tmp2;
       		push(tmp1,tmp2);	
		}
}
	

void stos_tablica::push(string klucz, string wartosc){
	if (rozmiar != 0)
	{ 
		danetmp = new string[rozmiar];
		danetmp2 = new string[rozmiar];
		for (int i = 0; i < rozmiar; i++){
			danetmp[i] = dane[i];
			danetmp2[i] = tab_kluczy[i];
		}
		delete [] dane;
		delete [] tab_kluczy;
		++rozmiar;
		dane = new string[rozmiar];
		tab_kluczy = new string[rozmiar];
		for (int i = 0; i < (rozmiar-1); i++){
			dane[i] = danetmp[i];
			tab_kluczy[i] = danetmp2[i];
		}
		dane[rozmiar-1] = wartosc;
		tab_kluczy[rozmiar-1] = klucz;
		delete [] danetmp;
		delete [] danetmp2;
	}
	else{
		++rozmiar;
		dane = new string[rozmiar];
		dane[rozmiar-1]=wartosc;
		tab_kluczy= new string[rozmiar];
		tab_kluczy[rozmiar-1]=klucz;
		}

}
void stos_tablica::pobierz(){
	string k;
	cout<<"Podaj klucz jaki chcesz znalezc : ";
	cin>>k;
	bool czy_jest=0;
	int indeks=0;
	for (int i = 0; i < rozmiar; i++){
		if (tab_kluczy[i] == k){
			czy_jest = 1;
			indeks=i;
		}
	}
	string tmp1, tmp2;

	if (czy_jest == 1){
		cout<<"Element o kluczu : "<<k<<" ma wartosc :  "<<dane[indeks]<<endl;
	}
	else
		cout<<"Nie ma elementu o kluczu : "<<k<<" !!!"<<endl;
}

void stos_tablica::szukaj(string k){
	//bool czy_jest=0;
	//int indeks=0;
	for (int i = 0; i < rozmiar; i++){
		if (tab_kluczy[i] == k){
			//czy_jest = 1;
			//indeks=i;
		}
	}

/*
	if (czy_jest == 1){
		cout<<"****ASOC****Element o kluczu : "<<k<<" ma wartosc :  "<<dane[indeks]<<endl;
	}
	else
		cout<<"*ASOCJACYJNA*Nie ma elementu o kluczu : "<<k<<" !!!"<<endl;
*/
}

void stos_tablica::usun(){
	string k;
	cout<<"Podaj klucz jaki chcesz usunac : ";
	cin>>k;
	bool czy_jest=0;
	int indeks=0;
	for (int i = 0; i < rozmiar; i++){
		if (tab_kluczy[i] == k){
			czy_jest = 1;
			indeks=i;
		}
	}
	
	if (czy_jest == 1){
		string tmp1, tmp2;
		tmp1 = tab_kluczy[indeks];
		tmp2 = dane[indeks];
		tab_kluczy[indeks]=tab_kluczy[rozmiar-1];
		dane[indeks] = dane[rozmiar-1];
		tab_kluczy[rozmiar-1] = tmp1;
		dane[rozmiar-1] = tmp2;
		pop();
		cout<<"Usunieto element z kluczem : "<<k<<endl;
	}
	else
		pop();

}

void stos_tablica::pop(){

	if (rozmiar != 0){
		danetmp = new string[rozmiar];
		danetmp2 = new string[rozmiar];
		for (int i = 0; i < rozmiar; i++){
			danetmp[i] = dane[i];
			danetmp2[i] = tab_kluczy[i];
		}
		delete [] dane;
		delete [] tab_kluczy;
		--rozmiar;
		dane = new string[rozmiar];
		tab_kluczy = new string[rozmiar];
		for (int i = 0; i < rozmiar; i++){
			dane[i] = danetmp[i];
			tab_kluczy[i] = danetmp2[i];
		}
		delete [] danetmp;
		delete [] danetmp2;
	}
	else cout<<" nie ma co usuwac, stos pusty !"<<endl;
}

void stos_tablica::pokaz_elementy(){
	if (rozmiar !=0){
		cout<<"Elementy stosu to :\n";
		for (int i = 0; i <rozmiar; i++)
			cout<<"Element o kluczu : "<<tab_kluczy[i]<<" ma wartosc : "<<dane[i]<<endl;
	}
	else cout<<"Stos PUSTY ! "<<endl;
}
